/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#ifndef GWEN_CONTROLS_TABSTRIP_H
#define GWEN_CONTROLS_TABSTRIP_H

#include "gwen/Controls/Base.h"
#include "gwen/Controls/Button.h"
#include "gwen/Controls/TabButton.h"

namespace gwen
{
	namespace Controls
	{
		//class TabControl;

		class GWEN_EXPORT TabStrip : public Base
		{
			public:

				GWEN_CONTROL( TabStrip, Base );

				virtual void Layout( Skin::Base* skin );

				virtual bool DragAndDrop_HandleDrop( gwen::DragAndDrop::Package* pPackage, int x, int y );
				virtual bool DragAndDrop_CanAcceptPackage( gwen::DragAndDrop::Package* pPackage );

				virtual void DragAndDrop_HoverEnter( gwen::DragAndDrop::Package* pPackage, int x, int y );
				virtual void DragAndDrop_HoverLeave( gwen::DragAndDrop::Package* pPackage );
				virtual void DragAndDrop_Hover( gwen::DragAndDrop::Package* pPackage, int x, int y );

				virtual void SetTabPosition( int iPos );

				virtual void SetAllowReorder( bool b ) { m_bAllowReorder = b; }
				virtual bool AllowsTabReorder() { return m_bAllowReorder; }

				virtual bool ShouldClip() { return false; }

			private:

				Base*	m_TabDragControl;
				bool	m_bAllowReorder;

		};
	}
}
#endif
