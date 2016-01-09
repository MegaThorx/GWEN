/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#ifndef GWEN_RENDERERS_DIRECT2D_H
#define GWEN_RENDERERS_DIRECT2D_H

#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>
#include <wincodec.h>

#include "gwen/Gwen.h"
#include "gwen/BaseRender.h"
#include "gwen/Texture.h"

namespace gwen
{
	namespace Renderer
	{

		class GWEN_EXPORT Direct2D : public gwen::Renderer::Base
		{
			public:

				Direct2D();
				Direct2D( ID2D1RenderTarget* pDevice, IDWriteFactory* pDWriteFactory, IWICImagingFactory* pWICFactory );
				~Direct2D();

				virtual void Begin();
				virtual void End();
				virtual void Release();

				virtual void SetDrawColor( gwen::Color color );

				virtual void DrawFilledRect( gwen::Rect rect );

				virtual void LoadFont( gwen::Font* pFont );
				virtual void FreeFont( gwen::Font* pFont );
				virtual void RenderText( gwen::Font* pFont, gwen::Point pos, const gwen::UnicodeString & text );
				virtual gwen::Point MeasureText( gwen::Font* pFont, const gwen::UnicodeString & text );

				virtual void DeviceLost();
				virtual void DeviceAcquired( ID2D1RenderTarget* pRT );

				void StartClip();
				void EndClip();

				void DrawTexturedRect( gwen::Texture* pTexture, gwen::Rect pTargetRect, float u1 = 0.0f, float v1 = 0.0f, float u2 = 1.0f, float v2 = 1.0f );
				void LoadTexture( gwen::Texture* pTexture );
				void FreeTexture( gwen::Texture* pTexture );
				gwen::Color PixelColour( gwen::Texture* pTexture, unsigned int x, unsigned int y, const gwen::Color & col_default );

				void DrawLinedRect( gwen::Rect rect );
				void DrawShavedCornerRect( gwen::Rect rect, bool bSlight = false );

			public:

				//
				// Self Initialization
				//

				bool InitializeContext( gwen::WindowProvider* pWindow );
				bool ShutdownContext( gwen::WindowProvider* pWindow );
				bool PresentContext( gwen::WindowProvider* pWindow );
				bool ResizedContext( gwen::WindowProvider* pWindow, int w, int h );
				bool BeginContext( gwen::WindowProvider* pWindow );
				bool EndContext( gwen::WindowProvider* pWindow );

			private:
				bool InternalCreateDeviceResources();
				void InternalReleaseDeviceResources();

				ID2D1Factory*	m_pD2DFactory;
				HWND			m_pHWND;

			private:
				bool InternalLoadTexture( gwen::Texture* pTexture );
				bool InternalLoadFont( gwen::Font* pFont );

				void InternalFreeFont( gwen::Font* pFont, bool bRemove = true );
				void InternalFreeTexture( gwen::Texture* pTexture, bool bRemove = true );

			private:

				IDWriteFactory*		m_pDWriteFactory;
				IWICImagingFactory*	m_pWICFactory;
				ID2D1RenderTarget*	m_pRT;

				ID2D1SolidColorBrush* m_pSolidColorBrush;

				D2D1::ColorF		m_Color;

				gwen::Texture::List	m_TextureList;
				gwen::Font::List	m_FontList;

		};

	}
}
#endif
