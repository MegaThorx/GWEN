/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#ifndef GWEN_CONTROLS_WINDOWCONTROL_H
#define GWEN_CONTROLS_WINDOWCONTROL_H

#include "gwen/Gwen.h"
#include "gwen/Controls/Base.h"
#include "gwen/Controls/Label.h"
#include "gwen/Controls/Button.h"
#include "gwen/Controls/Dragger.h"
#include "gwen/Controls/Label.h"
#include "gwen/Controls/ResizableControl.h"
#include "gwen/Controls/Modal.h"
#include "gwen/Controls/WindowButtons.h"
#include "gwen/Skin.h"


namespace gwen
{
	namespace Controls
	{
		class CloseButton;

		class GWEN_EXPORT WindowControl : public ResizableControl
		{
			public:

				GWEN_CONTROL( WindowControl, ResizableControl );

				virtual ~WindowControl();
				virtual void Render( Skin::Base* skin );
				virtual void RenderUnder( Skin::Base* skin );

				virtual void SetTitle( gwen::UnicodeString title );
				virtual void SetTitle( gwen::String title ) { SetTitle( gwen::Utility::StringToUnicode( title ) ); }
				virtual void SetClosable( bool closeable );

				virtual void Touch();
				bool IsOnTop();

				virtual void SetHidden( bool hidden );

				void CloseButtonPressed();
				void RenderFocus( gwen::Skin::Base* skin );
				void SetDeleteOnClose( bool b ) { m_bDeleteOnClose = b; }

				void MakeModal( bool bDrawBackground = true );
				void DestroyModal();

				gwen::Event::Caller	onWindowClosed;

			protected:

				gwen::ControlsInternal::Dragger*	m_TitleBar;
				gwen::Controls::Label*				m_Title;
				gwen::Controls::WindowCloseButton*	m_CloseButton;

				bool m_bDeleteOnClose;

				ControlsInternal::Modal* m_Modal;
		};
	}
}
#endif
