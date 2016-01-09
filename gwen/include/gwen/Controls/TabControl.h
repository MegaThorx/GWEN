/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#ifndef GWEN_CONTROLS_TABCONTROL_H
#define GWEN_CONTROLS_TABCONTROL_H

#include "gwen/Controls/Base.h"
#include "gwen/Controls/Button.h"
#include "gwen/Controls/TabButton.h"
#include "gwen/Controls/TabStrip.h"
#include "gwen/Controls/TabTitleBar.h"

namespace gwen
{
	namespace ControlsInternal
	{
		class ScrollBarButton;
	}

	namespace Controls
	{
		class GWEN_EXPORT TabControl : public Base
		{
				GWEN_CONTROL( TabControl, Base );

				virtual TabButton* AddPage( const TextObject strText, Controls::Base* pPage = NULL );

				virtual void AddPage( TabButton* pButton );
				virtual void RemovePage( TabButton* pButton );

				virtual void OnTabPressed( Controls::Base* control );
				virtual void OnLoseTab( TabButton* pButton );

				virtual int TabCount( void );
				virtual TabButton* GetTab( int iNum );
				virtual TabButton* GetCurrentButton() { return m_pCurrentButton; }
				virtual TabStrip* GetTabStrip() { return m_TabStrip; }

				virtual void SetTabStripPosition( int iDock );

				virtual bool DoesAllowDrag();

				virtual void SetAllowReorder( bool b ) { GetTabStrip()->SetAllowReorder( b ); }

				gwen::Event::Caller	onLoseTab;
				gwen::Event::Caller	onAddTab;

			private:

				virtual void PostLayout( Skin::Base* skin );
				void HandleOverflow();

				void ScrollPressLeft( Base* pFrom );
				void ScrollPressRight( Base* pFrom );

				TabStrip*		m_TabStrip;
				TabButton*		m_pCurrentButton;

				ControlsInternal::ScrollBarButton*	m_pScroll[2];
				int				m_iScrollOffset;


		};
	}
}
#endif
