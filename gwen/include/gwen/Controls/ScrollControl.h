/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#ifndef GWEN_CONTROLS_SCROLLCONTROL_H
#define GWEN_CONTROLS_SCROLLCONTROL_H

#include "gwen/Controls/Base.h"
#include "gwen/Controls/Button.h"
#include "gwen/Gwen.h"
#include "gwen/Skin.h"
#include "gwen/Controls/ScrollBar.h"
#include "gwen/Controls/VerticalScrollBar.h"
#include "gwen/Controls/HorizontalScrollBar.h"


namespace gwen
{
	namespace Controls
	{
		class GWEN_EXPORT ScrollControl : public Base
		{
			public:

				GWEN_CONTROL( ScrollControl, Base );

				virtual void Layout( Skin::Base* skin );
				virtual void Render( Skin::Base* skin );

				virtual void SetScroll( bool h, bool v );
				virtual void SetAutoHideBars( bool should ) { m_bAutoHideBars = should; }
				virtual bool CanScrollH() { return m_bCanScrollH; }
				virtual bool CanScrollV() { return m_bCanScrollV; }
				virtual void OnChildBoundsChanged( gwen::Rect oldChildBounds, Base* pChild );
				virtual void UpdateScrollBars();

				virtual void SetVScrollRequired( bool req );
				virtual void SetHScrollRequired( bool req );

				virtual void SetInnerSize( int w, int h );

				virtual void VBarMoved( Controls::Base* control );
				virtual void HBarMoved( Controls::Base* control );

				virtual bool OnMouseWheeled( int iDelta );

				virtual void ScrollToBottom();
				virtual void ScrollToTop();
				virtual void ScrollToLeft();
				virtual void ScrollToRight();

				virtual void Clear();

			protected:

				virtual bool ContentsAreDocked();

				bool m_bCanScrollH;
				bool m_bCanScrollV;

				bool m_bAutoHideBars;

				Controls::BaseScrollBar* m_VerticalScrollBar;
				Controls::BaseScrollBar* m_HorizontalScrollBar;
		};
	}
}
#endif
