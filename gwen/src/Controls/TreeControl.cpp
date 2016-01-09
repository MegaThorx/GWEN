/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/


#include "gwen/Controls/TreeControl.h"
#include "gwen/Controls/ScrollControl.h"
#include "gwen/Utility.h"

using namespace gwen;
using namespace gwen::Controls;

GWEN_CONTROL_CONSTRUCTOR( TreeControl )
{
	m_TreeControl = this;
	m_ToggleButton->DelayedDelete();
	m_ToggleButton = NULL;
	m_Title->DelayedDelete();
	m_Title = NULL;
	m_InnerPanel->DelayedDelete();
	m_InnerPanel = NULL;
	m_bAllowMultipleSelection = false;
	m_ScrollControl = new ScrollControl( this );
	m_ScrollControl->Dock( Pos::Fill );
	m_ScrollControl->SetScroll( false, true );
	m_ScrollControl->SetAutoHideBars( true );
	m_ScrollControl->SetMargin( Margin( 1, 1, 1, 1 ) );
	m_InnerPanel = m_ScrollControl;
	m_ScrollControl->SetInnerSize( 1000, 1000 );
}

void TreeControl::Render( Skin::Base* skin )
{
	if ( ShouldDrawBackground() )
	{ skin->DrawTreeControl( this ); }
}

void TreeControl::OnChildBoundsChanged( gwen::Rect /*oldChildBounds*/, Base* /*pChild*/ )
{
	m_ScrollControl->UpdateScrollBars();
	Invalidate();
}

void TreeControl::Clear()
{
	m_ScrollControl->Clear();
}

void TreeControl::Layout( Skin::Base* skin )
{
	BaseClass::BaseClass::Layout( skin );
}

void TreeControl::PostLayout( Skin::Base* skin )
{
	BaseClass::BaseClass::PostLayout( skin );
}

void TreeControl::OnNodeAdded( TreeNode* pNode )
{
	pNode->onNamePress.Add( this, &TreeControl::OnNodeSelection );
}

void TreeControl::OnNodeSelection( Controls::Base* /*control*/ )
{
	if ( !m_bAllowMultipleSelection || !gwen::Input::IsKeyDown( Key::Control ) )
	{ DeselectAll(); }
}
