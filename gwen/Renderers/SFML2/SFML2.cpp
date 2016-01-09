
#include "gwen/Gwen.h"
#include "gwen/BaseRender.h"
#include "gwen/Font.h"
#include "gwen/Texture.h"
#include "gwen/Renderers/SFML2.h"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

#include <GL/gl.h>

#include <cmath>

struct TextureData
{
	TextureData( sf::Image* img ): texture( NULL ), image( img ) { }
	TextureData( sf::Texture* text ): texture( text ), image( NULL ) { }
	~TextureData()
	{
		if ( texture != NULL ) delete texture;
		if ( image != NULL) delete image;
	}

	sf::Texture *texture;
	sf::Image *image;
};

gwen::Renderer::SFML2::SFML2( sf::RenderTarget& target ):
	m_Target( target ), m_Color(), m_Buffer(), m_RenderStates( sf::RenderStates::Default ), m_Height( m_Target.getSize().y )
{
	m_Buffer.setPrimitiveType( sf::Triangles );
	m_RenderStates.blendMode = sf::BlendAlpha;
}

gwen::Renderer::SFML2::~SFML2() { }

void gwen::Renderer::SFML2::Begin()
{
	m_OriginalView = m_Target.getView();
	sf::FloatRect vrect;
	vrect.left = 0;	vrect.top = 0;
	vrect.width = m_Target.getSize().x;	vrect.height = m_Height = m_Target.getSize().y;
	sf::FloatRect vprect;
	vprect.left = 0; vprect.top = 0;
	vprect.width = 1.0f; vprect.height = 1.0f;
	sf::View view( vrect );
	view.setViewport( vprect );
	m_Target.setView( view );
}

void gwen::Renderer::SFML2::End()
{
	m_Target.setView( m_OriginalView );
}

void gwen::Renderer::SFML2::StartClip()
{
	Flush();

	gwen::Rect rect = ClipRegion();
	float x = rect.x, y = rect.y, w = rect.w, h = rect.h;

	// OpenGL's coords are from the bottom left
	// so we need to translate them here.
	y = m_Height - ( y + h );

	float scale = Scale();

	glEnable( GL_SCISSOR_TEST );
	glScissor( x * scale, y * scale, w * scale, h * scale );
}

void gwen::Renderer::SFML2::EndClip()
{
	Flush();
	glDisable( GL_SCISSOR_TEST );
}

void gwen::Renderer::SFML2::SetDrawColor( gwen::Color color )
{
	m_Color = sf::Color( color.r, color.g, color.b, color.a );
}

void gwen::Renderer::SFML2::DrawPixel( int x, int y )
{
	EnsurePrimitiveType( sf::Points );
	EnsureTexture( NULL );
	Translate( x, y );
	AddVert( x, y+1 );
}

void gwen::Renderer::SFML2::DrawLinedRect( gwen::Rect rect )
{
	EnsurePrimitiveType( sf::Lines );
	EnsureTexture( NULL );

	Translate ( rect );

	//   (x,y) ---------- (x+w, y)
	//         |        |
	// (x,y+h) ---------- (x+w,y+h)

	AddVert( rect.x, rect.y);
	AddVert( rect.x+rect.w, rect.y	);

	AddVert( rect.x+rect.w, rect.y	);
	AddVert( rect.x+rect.w, rect.y+rect.h );

	AddVert( rect.x+rect.w, rect.y+rect.h );
	AddVert( rect.x, rect.y + rect.h );

	AddVert( rect.x, rect.y + rect.h );
	AddVert( rect.x, rect.y );
}

void gwen::Renderer::SFML2::DrawFilledRect( gwen::Rect rect )
{

	EnsurePrimitiveType( sf::Triangles );
	EnsureTexture( NULL );

	Translate( rect );

	AddVert( rect.x, rect.y );
	AddVert( rect.x+rect.w, rect.y );
	AddVert( rect.x, rect.y + rect.h );

	AddVert( rect.x+rect.w, rect.y );
	AddVert( rect.x+rect.w, rect.y+rect.h );
	AddVert( rect.x, rect.y + rect.h );
}

void gwen::Renderer::SFML2::DrawShavedCornerRect( gwen::Rect rect, bool bSlight )
{
	//TODO: Implement this
	Base::DrawShavedCornerRect( rect, bSlight );
}

void gwen::Renderer::SFML2::DrawTexturedRect( gwen::Texture* pTexture, gwen::Rect rect, float u1, float v1, float u2, float v2 )
{
	TextureData* data = reinterpret_cast<TextureData*>( pTexture->data );

	// Missing image, not loaded properly?
	if ( !data )
		return DrawMissingImage( rect );

	const sf::Texture* tex = data->texture;

	EnsurePrimitiveType( sf::Triangles );
	EnsureTexture( tex );

	Translate( rect );

	AddVert( rect.x, rect.y, u1, v1 );
	AddVert( rect.x+rect.w, rect.y,	u2, v1 );
	AddVert( rect.x, rect.y + rect.h,	u1, v2 );

	AddVert( rect.x+rect.w, rect.y, u2, v1 );
	AddVert( rect.x+rect.w, rect.y+rect.h, u2, v2 );
	AddVert( rect.x, rect.y + rect.h, u1, v2 );
}

void gwen::Renderer::SFML2::LoadFont( gwen::Font* font )
{
	font->realsize = font->size * Scale();

	sf::Font* pFont = new sf::Font();

	if ( !pFont->loadFromFile( Utility::UnicodeToString( font->facename ) ) )
	{
		// Ideally here we should be setting the font to a system default font here.
		delete pFont;
		pFont = NULL; // SFML 2 doesn't have a default font anymore
	}

	font->data = pFont;
}

void gwen::Renderer::SFML2::FreeFont( gwen::Font* pFont )
{
	if ( !pFont->data ) return;
	sf::Font* font = reinterpret_cast<sf::Font*>( pFont->data );
	delete font;
	pFont->data = NULL;
}

void gwen::Renderer::SFML2::RenderText( gwen::Font* pFont, gwen::Point pos, const gwen::UnicodeString& text )
{
	Flush();

	Translate( pos.x, pos.y );

	// If the font doesn't exist, or the font size should be changed
	if ( !pFont->data || fabs( pFont->realsize - pFont->size * Scale() ) > 2 )
	{
		FreeFont( pFont );
		LoadFont( pFont );
	}

	const sf::Font* pSFFont = reinterpret_cast<sf::Font*>( pFont->data );

	sf::Text sfStr;
	sfStr.setString( text );
	sfStr.setFont( *pSFFont );
	sfStr.move( pos.x, pos.y );
	sfStr.setCharacterSize( pFont->realsize );
	sfStr.setColor( m_Color );
	m_Target.draw( sfStr );
}

gwen::Point gwen::Renderer::SFML2::MeasureText( gwen::Font* pFont, const gwen::UnicodeString& text )
{
	// If the font doesn't exist, or the font size should be changed
	if ( !pFont->data || fabs( pFont->realsize - pFont->size * Scale() ) > 2 )
	{
		FreeFont( pFont );
		LoadFont( pFont );
	}

	const sf::Font* pSFFont = reinterpret_cast<sf::Font*>( pFont->data );

    if ( pSFFont ) {
        sf::Text sfStr;
        sfStr.setString( text );
        sfStr.setFont( *pSFFont );
        sfStr.setCharacterSize( pFont->realsize );
        return gwen::Point( sfStr.getLocalBounds().width, pSFFont->getLineSpacing( pFont->realsize ) );
    }

    return gwen::Point();
}

void gwen::Renderer::SFML2::LoadTexture( gwen::Texture* pTexture )
{
	if ( !pTexture ) return;
	if ( pTexture->data ) FreeTexture( pTexture );

	sf::Texture* tex = new sf::Texture();
	tex->setSmooth( true );
	if ( !tex->loadFromFile( pTexture->name.Get() ) )
	{
		delete( tex );
		pTexture->failed = true;
		return;
	}

	pTexture->height = tex->getSize().x;
	pTexture->width = tex->getSize().y;
	pTexture->data = new TextureData( tex );
}

void gwen::Renderer::SFML2::FreeTexture( gwen::Texture* pTexture )
{
	TextureData* data = reinterpret_cast<TextureData*>( pTexture->data );

	if ( data )
		delete data;

	pTexture->data = NULL;
}

gwen::Color gwen::Renderer::SFML2::PixelColour( gwen::Texture* pTexture, unsigned int x, unsigned int y, const gwen::Color& col_default )
{
	TextureData* data = static_cast<TextureData*>( pTexture->data );

	if ( !data->texture && !data->image ) return col_default;
	if ( !data->image )
	{
		sf::Image copy = data->texture->copyToImage();
		data->image = new sf::Image( copy );
	}

	sf::Color col = data->image->getPixel( x, y );
	return gwen::Color( col.r, col.g, col.b, col.a );
}


