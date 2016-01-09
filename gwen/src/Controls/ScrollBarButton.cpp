/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/


#include "gwen/Controls/ScrollBar.h"
#include "gwen/Controls/ScrollBarButton.h"

using namespace gwen;
using namespace gwen::Controls;
using namespace gwen::ControlsInternal;


GWEN_CONTROL_CONSTRUCTOR( ScrollBarButton )
{
	SetDirectionUp();
}

void ScrollBarButton::SetDirectionUp()
{
	m_iDirection = Pos::Top;
}

void ScrollBarButton::SetDirectionDown()
{
	m_iDirection = Pos::Bottom;
}

void ScrollBarButton::SetDirectionLeft()
{
	m_iDirection = Pos::Left;
}

void ScrollBarButton::SetDirectionRight()
{
	m_iDirection = Pos::Right;
}

void ScrollBarButton::Render( Skin::Base* skin )
{
	skin->DrawScrollButton( this, m_iDirection, m_bDepressed, IsHovered(), IsDisabled() );
}