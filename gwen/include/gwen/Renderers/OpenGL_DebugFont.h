/*
	GWEN
	Copyright (c) 2011 Facepunch Studios
	See license in Gwen.h
*/

#ifndef GWEN_RENDERERS_OPENGL_DEBUGFONT_H
#define GWEN_RENDERERS_OPENGL_DEBUGFONT_H

#include "gwen/Gwen.h"
#include "gwen/Renderers/OpenGL.h"

namespace gwen
{
	namespace Renderer
	{

		class OpenGL_DebugFont : public gwen::Renderer::OpenGL
		{
			public:

				OpenGL_DebugFont();
				~OpenGL_DebugFont();

				void Init();

				void RenderText( gwen::Font* pFont, gwen::Point pos, const gwen::UnicodeString & text );
				gwen::Point MeasureText( gwen::Font* pFont, const gwen::UnicodeString & text );

			protected:

				void CreateDebugFont();
				void DestroyDebugFont();

				gwen::Texture*	m_pFontTexture;
				float			m_fFontScale[2];
				float			m_fLetterSpacing;

		};

	}
}
#endif
