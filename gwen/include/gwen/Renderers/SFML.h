/*
	GWEN
	Copyright (c) 2011 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#ifndef GWEN_RENDERERS_SFML_H
#define GWEN_RENDERERS_SFML_H
#include "gwen/Gwen.h"
#include "gwen/BaseRender.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

namespace sf { class RenderTarget; }

namespace gwen
{
	namespace Renderer
	{

		class SFML : public gwen::Renderer::Base
		{
			public:

				SFML( sf::RenderTarget & target );
				~SFML();

				virtual void SetDrawColor( gwen::Color color );

				virtual void DrawFilledRect( gwen::Rect rect );

				virtual void LoadFont( gwen::Font* pFont );
				virtual void FreeFont( gwen::Font* pFont );
				virtual void RenderText( gwen::Font* pFont, gwen::Point pos, const gwen::UnicodeString & text );
				virtual gwen::Point MeasureText( gwen::Font* pFont, const gwen::UnicodeString & text );

				void StartClip();
				void EndClip();

				void DrawTexturedRect( gwen::Texture* pTexture, gwen::Rect pTargetRect, float u1 = 0.0f, float v1 = 0.0f, float u2 = 1.0f, float v2 = 1.0f );
				void LoadTexture( gwen::Texture* pTexture );
				void FreeTexture( gwen::Texture* pTexture );
				gwen::Color PixelColour( gwen::Texture* pTexture, unsigned int x, unsigned int y, const gwen::Color & col_default );

				virtual void DrawLinedRect( gwen::Rect rect );
				virtual void DrawPixel( int x, int y );

			protected:

				sf::RenderTarget	& m_Target;
				sf::Color			m_Color;
				sf::RectangleShape  m_pixelShape;

		};
	}
}
#endif
