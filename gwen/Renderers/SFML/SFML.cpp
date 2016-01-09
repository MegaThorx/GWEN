#include "gwen/Gwen.h"
#include "gwen/BaseRender.h"
#include "gwen/Utility.h"
#include "gwen/Font.h"
#include "gwen/Texture.h"
#include "gwen/Renderers/SFML.h"
#include <SFML/Graphics.hpp>
#include <GL/gl.h>
#include <cmath>

namespace gwen
{
	namespace Renderer
	{
		struct TextureData
		{
			TextureData( sf::Image* img ) : image( img ), texture( NULL ) { }
			TextureData( sf::Texture* text ) : texture( text ), image( NULL ) { }
			~TextureData() { if ( texture != NULL ) { delete texture; } if ( image != NULL ) { delete image; } }

			sf::Texture* texture;
			sf::Image*   image;
		};


		SFML::SFML( sf::RenderTarget & target ) : m_Target( target ), m_pixelShape( sf::Vector2f( 1, 1 ) )
		{
		}

		SFML::~SFML()
		{
		}

		void SFML::SetDrawColor( gwen::Color color )
		{
			m_Color.r = color.r;
			m_Color.g = color.g;
			m_Color.b = color.b;
			m_Color.a = color.a;
		}

		void SFML::DrawFilledRect( gwen::Rect rect )
		{
			Translate( rect );
			m_Target.Draw( sf::Shape::Rectangle( rect.x, rect.y, rect.x + rect.w, rect.y + rect.h, m_Color ) );
		}

        void SFML::DrawLinedRect( gwen::Rect rect )
        {
            Base::DrawLinedRect( rect );
        }

        void SFML::DrawPixel( int x, int y )
        {
            Base::DrawPixel( x, y );
        }

		void SFML::LoadFont( gwen::Font* font )
		{
			font->realsize = font->size * Scale();
			sf::Font* pFont = new sf::Font();
			
			if ( !pFont->LoadFromFile( Utility::UnicodeToString( font->facename ), font->realsize  ) )
			{
				// Ideally here we should be setting the font to a system default font here.
				delete pFont;

				static sf::Font defaultFont = sf::Font::GetDefaultFont();
				pFont = &defaultFont;
			}

			font->data = pFont;
		}

		void SFML::FreeFont( gwen::Font* pFont )
		{
			if ( !pFont->data ) { return; }

			// If this is the default font then don't delete it!
			if ( font != &sf::Font::GetDefaultFont() )
				delete font;
			
			pFont->data = NULL;
		}

		void SFML::RenderText( gwen::Font* pFont, gwen::Point pos, const gwen::UnicodeString & text )
		{
			Translate( pos.x, pos.y );

			// If the font doesn't exist, or the font size should be changed
			if ( !pFont->data || fabs( pFont->realsize - pFont->size * Scale() ) > 2 )
			{
				FreeFont( pFont );
				LoadFont( pFont );
			}

			const sf::Font* pSFFont = ( sf::Font* )( pFont->data );

			if ( !pSFFont )
			{
				static sf::Font defaultFont = sf::Font::GetDefaultFont();
				pSFFont = &defaultFont;
			}

			sf::String sfStr( text );
			sfStr.SetFont( *pSFFont );
			sfStr.Move( pos.x, pos.y );
			sfStr.SetSize( pFont->realsize );
			sfStr.SetColor( m_Color );
			m_Target.Draw( sfStr );
			
		}

		gwen::Point SFML::MeasureText( gwen::Font* pFont, const gwen::UnicodeString & text )
		{
			// If the font doesn't exist, or the font size should be changed
			if ( !pFont->data || fabs( pFont->realsize - pFont->size * Scale() ) > 2 )
			{
				FreeFont( pFont );
				LoadFont( pFont );
			}

			const sf::Font* pSFFont = ( sf::Font* )( pFont->data );

			if ( !pSFFont )
			{
				static sf::Font defaultFont = sf::Font::GetDefaultFont();
				pSFFont = &defaultFont;
			}

			sf::String sfStr( text );
			sfStr.SetFont( *pSFFont );
			sfStr.SetSize( pFont->realsize );
			sf::FloatRect sz = sfStr.GetRect();
			
			return gwen::Point( sz.GetWidth(), sz.GetHeight() );			
		}

		void SFML::StartClip()
		{
			gwen::Rect rect = ClipRegion();
			// OpenGL's coords are from the bottom left
			// so we need to translate them here.
			{
				GLint view[4];
				glGetIntegerv( GL_VIEWPORT, &view[0] );
				rect.y = view[3] - ( rect.y + rect.h );
			}
			glScissor( rect.x * Scale(), rect.y * Scale(), rect.w * Scale(), rect.h * Scale() );
			glEnable( GL_SCISSOR_TEST );
		};


		void SFML::EndClip()
		{
			glDisable( GL_SCISSOR_TEST );
		};

		void SFML::LoadTexture( gwen::Texture* pTexture )
		{
			if ( !pTexture ) { return; }
			if ( pTexture->data ) { FreeTexture( pTexture ); }

			sf::Image* tex = new sf::Image();
            tex->SetSmooth( true );
            
            if ( !tex->LoadFromFile( pTexture->name.Get() ) )
			{
				delete( tex );
				pTexture->failed = true;
				return;
			}
			
			pTexture->height = tex->GetHeight();
			pTexture->width = tex->GetWidth();
			pTexture->data = new TextureData( tex );
			
		};

		void SFML::FreeTexture( gwen::Texture* pTexture )
		{
			TextureData* data = static_cast<TextureData*>( pTexture->data );

			if ( data )
			{
				delete data;
			}

			pTexture->data = NULL;
		}

		void SFML::DrawTexturedRect( gwen::Texture* pTexture, gwen::Rect rect, float u1, float v1, float u2, float v2 )
		{
			TextureData* data = static_cast<TextureData*>( pTexture->data );

			if ( !data )
			{ return DrawMissingImage( rect ); }

			const sf::Image* tex = data->image;

			if ( !tex )
			{ return DrawMissingImage( rect ); }

			Translate( rect );
			
			tex->Bind();
			glColor4f( 1, 1, 1, 1 );
			glBegin( GL_QUADS );
			glTexCoord2f( u1, v1 );
			glVertex2f( rect.x,     rect.y );
			glTexCoord2f( u1, v2 );
			glVertex2f( rect.x,     rect.y + rect.h );
			glTexCoord2f( u2, v2 );
			glVertex2f( rect.x + rect.w, rect.y + rect.h );
			glTexCoord2f( u2, v1 );
			glVertex2f( rect.x + rect.w, rect.y ) ;
			glEnd();
			
			glBindTexture( GL_TEXTURE_2D, 0 );
		}

		gwen::Color SFML::PixelColour( gwen::Texture* pTexture, unsigned int x, unsigned int y, const gwen::Color & col_default )
		{
            TextureData* data = static_cast<TextureData*>( pTexture->data );

			const sf::Image* tex = data->image;
			if ( !tex ) return col_default;

			sf::Color col = tex->GetPixel( x, y );
			return gwen::Color( col.r, col.g, col.b, col.a );

			sf::Color col = tex->GetPixel( x, y );
			return gwen::Color( col.r, col.g, col.b, col.a );
		}
		
	}
}
