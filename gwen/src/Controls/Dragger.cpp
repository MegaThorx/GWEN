/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/


#include "gwen/Controls/Dragger.h"

using namespace gwen;
using namespace gwen::ControlsInternal;



GWEN_CONTROL_CONSTRUCTOR( Dragger )
{
	m_pTarget = NULL;
	SetMouseInputEnabled( true );
	m_bDepressed = false;
	m_bDoMove = true;
}

void Dragger::OnMouseClickLeft( int x, int y, bool bDown )
{
	if ( bDown )
	{
		m_bDepressed = true;

		if ( m_pTarget )
		{ m_HoldPos = m_pTarget->CanvasPosToLocal( gwen::Point( x, y ) ); }

		gwen::MouseFocus = this;
		onDragStart.Call( this );
	}
	else
	{
		m_bDepressed = false;
		gwen::MouseFocus = NULL;
	}
}

void Dragger::OnMouseMoved( int x, int y, int deltaX, int deltaY )
{
	if ( !m_bDepressed ) { return; }

	if ( m_bDoMove && m_pTarget )
	{
		gwen::Point p = gwen::Point( x - m_HoldPos.x, y - m_HoldPos.y );

		// Translate to parent
		if ( m_pTarget->GetParent() )
		{ p = m_pTarget->GetParent()->CanvasPosToLocal( p ); }

		m_pTarget->MoveTo( p.x, p.y );
	}

	gwen::Event::Information info;
	info.Point = gwen::Point( deltaX, deltaY );
	onDragged.Call( this, info );
}

void Dragger::Render( Skin::Base* skin )
{
	//skin->DrawButton(this,false,false, false);
}

void Dragger::OnMouseDoubleClickLeft( int x, int y )
{
	onDoubleClickLeft.Call( this );
}