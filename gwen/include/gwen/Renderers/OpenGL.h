/*
	GWEN
	Copyright (c) 2011 Facepunch Studios
	See license in Gwen.h
*/

#ifndef GWEN_RENDERERS_OPENGL_H
#define GWEN_RENDERERS_OPENGL_H

#include "gwen/Gwen.h"
#include "gwen/BaseRender.h"

namespace gwen
{
	namespace Renderer
	{

		class OpenGL : public gwen::Renderer::Base
		{
			public:

				struct Vertex
				{
					float x, y, z;
					float u, v;
					unsigned char r, g, b, a;
				};

				OpenGL();
				~OpenGL();

				virtual void Init();

				virtual void Begin();
				virtual void End();

				virtual void SetDrawColor( gwen::Color color );
				virtual void DrawFilledRect( gwen::Rect rect );

				void StartClip();
				void EndClip();

				void DrawTexturedRect( gwen::Texture* pTexture, gwen::Rect pTargetRect, float u1 = 0.0f, float v1 = 0.0f, float u2 = 1.0f, float v2 = 1.0f );
				void LoadTexture( gwen::Texture* pTexture );
				void FreeTexture( gwen::Texture* pTexture );
				gwen::Color PixelColour( gwen::Texture* pTexture, unsigned int x, unsigned int y, const gwen::Color & col_default );

			protected:

				static const int	MaxVerts = 1024;


				void Flush();
				void AddVert( int x, int y, float u = 0.0f , float v = 0.0f );

				gwen::Color			m_Color;
				int					m_iVertNum;
				Vertex				m_Vertices[ MaxVerts ];


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

				void*	m_pContext;
		};

	}
}
#endif
