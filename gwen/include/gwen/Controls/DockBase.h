/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#ifndef GWEN_CONTROLS_DOCKBASE_H
#define GWEN_CONTROLS_DOCKBASE_H

#include "gwen/Controls/Base.h"
#include "gwen/Controls/Button.h"

namespace gwen
{
	namespace Controls
	{
		class DockedTabControl;
		class TabControl;

		class GWEN_EXPORT DockBase : public Base
		{
			public:

				GWEN_CONTROL( DockBase, Base );

				virtual void Render( Skin::Base* skin );
				virtual void RenderOver( Skin::Base* skin );
				virtual bool IsEmpty();

				virtual TabControl* GetTabControl();

				virtual DockBase* GetRight() { return GetChildDock( Pos::Right ); }
				virtual DockBase* GetLeft() { return GetChildDock( Pos::Left ); }
				virtual DockBase* GetTop() { return GetChildDock( Pos::Top ); }
				virtual DockBase* GetBottom() { return GetChildDock( Pos::Bottom ); }

				// No action on space (default button action is to press)
				virtual bool OnKeySpace( bool /*bDown*/ ) { return false; }

			private:

				// Drag n Drop
				virtual bool DragAndDrop_HandleDrop( gwen::DragAndDrop::Package* pPackage, int x, int y );
				virtual bool DragAndDrop_CanAcceptPackage( gwen::DragAndDrop::Package* pPackage );
				virtual void DragAndDrop_HoverEnter( gwen::DragAndDrop::Package* pPackage, int x, int y );
				virtual void DragAndDrop_HoverLeave( gwen::DragAndDrop::Package* pPackage );
				virtual void DragAndDrop_Hover( gwen::DragAndDrop::Package* pPackage, int x, int y );

				virtual void SetupChildDock( int iPos );

				virtual void DoRedundancyCheck();
				virtual void DoConsolidateCheck();
				virtual void OnRedundantChildDock( DockBase* pDockBase );

				virtual int GetDroppedTabDirection( int x, int y );
				virtual void OnTabRemoved( gwen::Controls::Base* pControl );

				DockBase* GetChildDock( int iPos );
				DockBase** GetChildDockPtr( int iPos );

				DockBase*		m_Left;
				DockBase*		m_Right;
				DockBase*		m_Top;
				DockBase*		m_Bottom;

				// Only CHILD dockpanels have a tabcontrol.
				DockedTabControl*		m_DockedTabControl;

				bool		m_bDrawHover;
				bool		m_bDropFar;
				gwen::Rect		m_HoverRect;

		};
	}
}
#endif
