/*
	GWEN
	Copyright (c) 2011 Facepunch Studios
	See license in Gwen.h
*/

#ifndef GWEN_RENDERERS_GDIPLUS_H
#define GWEN_RENDERERS_GDIPLUS_H

#include "gwen/Gwen.h"
#include "gwen/BaseRender.h"

#include <gdiplus.h>

/*

 GDI(plus) is pretty slow for rendering GWEN, because we're
 re-rendering everything on redraw.

 Therefore its usage should be as a test - rather than production.

*/

namespace gwen
{
	namespace Renderer
	{

		class GDIPlus : public gwen::Renderer::Base
		{
			public:

				GDIPlus( HWND pHWND = NULL );
				~GDIPlus();

				virtual void Begin();
				virtual void End();

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

			public:

				//
				// Self Initialization
				//

				virtual bool InitializeContext( gwen::WindowProvider* pWindow );
				virtual bool ShutdownContext( gwen::WindowProvider* pWindow );
				virtual bool PresentContext( gwen::WindowProvider* pWindow );
				virtual bool ResizedContext( gwen::WindowProvider* pWindow, int w, int h );
				virtual bool BeginContext( gwen::WindowProvider* pWindow );
				virtual bool EndContext( gwen::WindowProvider* pWindow );

			protected:

				int m_iWidth;
				int m_iHeight;

				Gdiplus::Color	m_Colour;

				HWND			m_HWND;
				HDC				m_hDC;
				ULONG_PTR       m_gdiplusToken;

				Gdiplus::Graphics*		graphics;
		};

		class GDIPlusBuffered : public GDIPlus
		{
			public:

				GDIPlusBuffered( HWND pHWND = NULL );
				~GDIPlusBuffered();

				virtual void Begin();
				virtual void End();

			private:

				void CreateBackbuffer();
				void DestroyBackbuffer();

				Gdiplus::Bitmap*			m_Bitmap;

		};
	}
}
#endif
