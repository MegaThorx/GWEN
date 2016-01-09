/*
	GWEN
	Copyright (c) 2012 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#ifndef GWEN_CONTROLS_WINDOWCANVAS_H
#define GWEN_CONTROLS_WINDOWCANVAS_H

#include "gwen/Controls/Base.h"
#include "gwen/InputHandler.h"
#include "gwen/WindowProvider.h"
#include "gwen/Controls/Dragger.h"
#include "gwen/Controls/Label.h"
#include "gwen/Controls/WindowButtons.h"

namespace gwen
{
	namespace Controls
	{
		class GWEN_EXPORT WindowCanvas : public Canvas, public gwen::WindowProvider
		{
			public:

				GWEN_CLASS( WindowCanvas, Controls::Canvas );

				WindowCanvas( int x, int y, int w, int h, gwen::Skin::Base* pRenderer, const gwen::String & strWindowTitle = "" );
				~WindowCanvas();

				virtual void DoThink();

				virtual bool WantsQuit() { return m_bQuit; }

				// gwen::WindowProvider
				virtual void* GetWindow();

				virtual bool InputQuit();

				Skin::Base* GetSkin( void );

				virtual void Render( Skin::Base* skin );

				virtual void SetPos( int x, int y );
				virtual bool IsOnTop();

				virtual void Layout( Skin::Base* skin );

				virtual bool CanMaximize() { return m_bCanMaximize; }
				virtual void SetCanMaximize( bool b );
				virtual void SetMaximize( bool b );

				virtual void SetSizable( bool b ) { m_Sizer->SetHidden( !b ); }
				virtual bool GetSizable() { return m_Sizer->Visible(); }

			protected:

				virtual void RenderCanvas();
				virtual void DestroyWindow();

				virtual void CloseButtonPressed();
				virtual void MaximizeButtonPressed();
				virtual void MinimizeButtonPressed();

				virtual void Dragger_Start();
				virtual void Dragger_Moved();
				virtual void Sizer_Moved();
				virtual void OnTitleDoubleClicked();

				void*		m_pOSWindow;
				bool		m_bQuit;

				gwen::Skin::Base*			m_pSkinChange;

				ControlsInternal::Dragger*	m_TitleBar;
				ControlsInternal::Dragger*	m_Sizer;
				gwen::Controls::Label*		m_Title;


				gwen::Point		m_WindowPos;
				gwen::Point		m_HoldPos;

				bool			m_bCanMaximize;
				bool			m_bIsMaximized;

				gwen::Controls::WindowCloseButton*		m_pClose;
				gwen::Controls::WindowMaximizeButton*	m_pMaximize;
				gwen::Controls::WindowMinimizeButton*	m_pMinimize;

		};
	}
}
#endif
