/*
	GWEN
	Copyright (c) 2012 Facepunch Studios
	See license in Gwen.h
*/

#ifndef GWEN_RENDERERS_DIRECTX9_H
#define GWEN_RENDERERS_DIRECTX9_H

#include "gwen/Gwen.h"
#include "gwen/BaseRender.h"

#include <D3D9.h>
#include <D3DX9Core.h>

#pragma comment( lib, "D3D9.lib" )
#pragma comment( lib, "D3Dx9.lib" )

namespace gwen
{
	namespace Renderer
	{

		class GWEN_EXPORT DirectX9 : public gwen::Renderer::Base
		{
			public:

				DirectX9( IDirect3DDevice9* pDevice = NULL );
				~DirectX9();

				virtual void Begin();
				virtual void End();
				virtual void Release();

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

				virtual void FillPresentParameters( gwen::WindowProvider* pWindow, D3DPRESENT_PARAMETERS & Params );

			protected:

				void*				m_pCurrentTexture;
				IDirect3DDevice9*	m_pDevice;
				IDirect3D9*			m_pD3D;
				DWORD				m_Color;
				gwen::Font::List	m_FontList;
				//gwen::Texture::List	m_TextureList;

				void Flush();
				void AddVert( int x, int y );
				void AddVert( int x, int y, float u, float v );

			protected:

				struct VertexFormat
				{
					FLOAT x, y, z, rhw;
					DWORD color;
					float u, v;
				};

				static const int		MaxVerts = 1024;
				VertexFormat			m_pVerts[MaxVerts];
				int						m_iVertNum;

		};

	}
}
#endif
