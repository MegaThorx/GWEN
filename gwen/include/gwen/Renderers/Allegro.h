/*
	GWEN
	Copyright (c) 2011 Facepunch Studios
	See license in Gwen.h
*/

#pragma once

#ifndef GWEN_RENDERERS_ALLEGRO_H
#define GWEN_RENDERERS_ALLEGRO_H

#include "gwen/Gwen.h"
#include "gwen/BaseRender.h"
#include <allegro5/allegro5.h>

namespace gwen
{
	namespace Renderer
	{

		class Allegro : public gwen::Renderer::Base
		{
			public:

				Allegro();
				~Allegro();

				virtual void SetDrawColor( gwen::Color color );

				virtual void DrawFilledRect( gwen::Rect rect );

				virtual void LoadFont( gwen::Font* pFont );
				virtual void FreeFont( gwen::Font* pFont );
				virtual void RenderText( gwen::Font* pFont, gwen::Point pos, const gwen::UnicodeString & text );
				virtual gwen::Point MeasureText( gwen::Font* pFont, const gwen::UnicodeString & text );

				void StartClip();
				void EndClip();

				void DrawTexturedRect( gwen::Texture* pTexture, gwen::Rect pTargetRect,
									   float u1 = 0.0f, float v1 = 0.0f, float u2 = 1.0f, float v2 = 1.0f );
				void LoadTexture( gwen::Texture* pTexture );
				void FreeTexture( gwen::Texture* pTexture );
				gwen::Color PixelColour( gwen::Texture* pTexture, unsigned int x, unsigned int y,
										 const gwen::Color & col_default );

				void DrawLinedRect( gwen::Rect rect );
				void DrawPixel( int x, int y );

				bool BeginContext( gwen::WindowProvider* pWindow );
				bool EndContext( gwen::WindowProvider* pWindow );
				bool PresentContext( gwen::WindowProvider* pWindow );

			protected:

				ALLEGRO_COLOR   m_Color;

		};
	}
}
#endif
