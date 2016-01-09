/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/


#include "gwen/Gwen.h"
#include "gwen/Controls/Canvas.h"
#include "gwen/Skin.h"
#include "gwen/Controls/Menu.h"
#include "gwen/DragAndDrop.h"
#include "gwen/ToolTip.h"

#ifndef GWEN_NO_ANIMATION
#include "gwen/Anim.h"
#endif

using namespace gwen::Controls;


Canvas::Canvas( gwen::Skin::Base* pSkin ) : BaseClass( NULL ), m_bAnyDelete( false )
{
	SetBounds( 0, 0, 10000, 10000 );
	SetScale( 1.0f );
	SetBackgroundColor( Color( 255, 255, 255, 255 ) );
	SetDrawBackground( false );

	if ( pSkin ) { SetSkin( pSkin ); }
}

Canvas::~Canvas()
{
	ReleaseChildren();
}

void Canvas::RenderCanvas()
{
	DoThink();
	gwen::Renderer::Base* render = m_Skin->GetRender();
	render->Begin();
	RecurseLayout( m_Skin );
	render->SetClipRegion( GetBounds() );
	render->SetRenderOffset( gwen::Point( 0, 0 ) );
	render->SetScale( Scale() );

	if ( m_bDrawBackground )
	{
		render->SetDrawColor( m_BackgroundColor );
		render->DrawFilledRect( GetRenderBounds() );
	}

	DoRender( m_Skin );
	DragAndDrop::RenderOverlay( this, m_Skin );
	ToolTip::RenderToolTip( m_Skin );
	render->End();
}

void Canvas::Render( gwen::Skin::Base* /*pRender*/ )
{
	m_bNeedsRedraw = false;
}

void Canvas::OnBoundsChanged( gwen::Rect oldBounds )
{
	BaseClass::OnBoundsChanged( oldBounds );
	InvalidateChildren( true );
}


void Canvas::DoThink()
{
	ProcessDelayedDeletes();

	if ( Hidden() ) { return; }

#ifndef GWEN_NO_ANIMATION
	gwen::Anim::Think();
#endif
	// Reset tabbing
	{
		NextTab = NULL;
		FirstTab = NULL;
	}
	ProcessDelayedDeletes();
	// Check has focus etc..
	RecurseLayout( m_Skin );

	// If we didn't have a next tab, cycle to the start.
	if ( NextTab == NULL )
	{ NextTab = FirstTab; }

	gwen::Input::OnCanvasThink( this );
}

void Canvas::SetScale( float f )
{
	if ( m_fScale == f ) { return; }

	m_fScale = f;

	if ( m_Skin && m_Skin->GetRender() )
	{ m_Skin->GetRender()->SetScale( m_fScale ); }

	OnScaleChanged();
	Redraw();
}

void Canvas::AddDelayedDelete( gwen::Controls::Base* pControl )
{
	if ( !m_bAnyDelete || m_DeleteSet.find( pControl ) == m_DeleteSet.end() )
	{
		m_bAnyDelete = true;
		m_DeleteSet.insert( pControl );
		m_DeleteList.push_back( pControl );
	}
}

void Canvas::PreDeleteCanvas( Controls::Base* pControl )
{
	if ( m_bAnyDelete )
	{
		std::set< Controls::Base* >::iterator itFind;

		if ( ( itFind = m_DeleteSet.find( pControl ) ) != m_DeleteSet.end() )
		{
			m_DeleteList.remove( pControl );
			m_DeleteSet.erase( pControl );
			m_bAnyDelete = !m_DeleteSet.empty();
		}
	}
}

void Canvas::ProcessDelayedDeletes()
{
	while ( m_bAnyDelete )
	{
		m_bAnyDelete = false;
		Controls::Base::List deleteList = m_DeleteList;
		m_DeleteList.clear();
		m_DeleteSet.clear();

		for ( gwen::Controls::Base::List::iterator it = deleteList.begin(); it != deleteList.end(); ++it )
		{
			gwen::Controls::Base* pControl = *it;
			pControl->PreDelete( GetSkin() );
			delete pControl;
			Redraw();
		}
	}
}

void Canvas::ReleaseChildren()
{
	Base::List::iterator iter = Children.begin();

	while ( iter != Children.end() )
	{
		Base* pChild = *iter;
		iter = Children.erase( iter );
		delete pChild;
	}
}

bool Canvas::InputMouseMoved( int x, int y, int deltaX, int deltaY )
{
	if ( Hidden() ) { return false; }

	if ( ToolTip::TooltipActive() )
	{ Redraw(); }

	// Todo: Handle scaling here..
	//float fScale = 1.0f / Scale();
	gwen::Input::OnMouseMoved( this, x, y, deltaX, deltaY );

	if ( !gwen::HoveredControl ) { return false; }

	if ( gwen::HoveredControl == this ) { return false; }

	if ( gwen::HoveredControl->GetCanvas() != this ) { return false; }

	gwen::HoveredControl->OnMouseMoved( x, y, deltaX, deltaY );
	gwen::HoveredControl->UpdateCursor();
	DragAndDrop::OnMouseMoved( gwen::HoveredControl, x, y );
	return true;
}

bool Canvas::InputMouseButton( int iButton, bool bDown )
{
	if ( Hidden() ) { return false; }

	return gwen::Input::OnMouseClicked( this, iButton, bDown );
}

bool Canvas::InputKey( int iKey, bool bDown )
{
	if ( Hidden() ) { return false; }

	if ( iKey <= gwen::Key::Invalid ) { return false; }

	if ( iKey >= gwen::Key::Count ) { return false; }

	return gwen::Input::OnKeyEvent( this, iKey, bDown );
}

bool Canvas::InputCharacter( gwen::UnicodeChar chr )
{
	if ( Hidden() ) { return false; }

	if ( !iswprint( chr ) ) { return false; }

	//Handle Accelerators
	if ( gwen::Input::HandleAccelerator( this, chr ) )
	{ return true; }

	//Handle characters
	if ( !gwen::KeyboardFocus ) { return false; }

	if ( gwen::KeyboardFocus->GetCanvas() != this ) { return false; }

	if ( !gwen::KeyboardFocus->Visible() ) { return false; }

	if ( gwen::Input::IsControlDown() ) { return false; }

	return KeyboardFocus->OnChar( chr );
}

bool Canvas::InputMouseWheel( int val )
{
	if ( Hidden() ) { return false; }

	if ( !gwen::HoveredControl ) { return false; }

	if ( gwen::HoveredControl == this ) { return false; }

	if ( gwen::HoveredControl->GetCanvas() != this ) { return false; }

	return gwen::HoveredControl->OnMouseWheeled( val );
}