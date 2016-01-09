/*
	GWEN
	Copyright (c) 2012 Facepunch Studios
	See license in Gwen.h
*/


#include "gwen/Gwen.h"
#include "gwen/ControlList.h"

using namespace gwen;
using namespace gwen::Controls;

void ControlList::Enable()
{
	for ( List::const_iterator it = list.begin(); it != list.end(); ++it )
	{
		( *it )->SetDisabled( false );
	}
}

void ControlList::Disable()
{
	for ( List::const_iterator it = list.begin(); it != list.end(); ++it )
	{
		( *it )->SetDisabled( true );
	}
}

void ControlList::Show()
{
	for ( List::const_iterator it = list.begin(); it != list.end(); ++it )
	{
		( *it )->Show();
	}
}

void ControlList::Hide()
{
	for ( List::const_iterator it = list.begin(); it != list.end(); ++it )
	{
		( *it )->Hide();
	}
}

gwen::TextObject ControlList::GetValue()
{
	for ( List::const_iterator it = list.begin(); it != list.end(); ++it )
	{
		return ( *it )->GetValue();
	}

	return "";
}

void ControlList::SetValue( const gwen::TextObject & value )
{
	for ( List::const_iterator it = list.begin(); it != list.end(); ++it )
	{
		( *it )->SetValue( value );
	}
}

void ControlList::MoveBy( const gwen::Point & point )
{
	for ( List::const_iterator it = list.begin(); it != list.end(); ++it )
	{
		( *it )->MoveBy( point.x, point.y );
	}
}

void ControlList::DoAction()
{
	for ( List::const_iterator it = list.begin(); it != list.end(); ++it )
	{
		( *it )->DoAction();
	}
}

void ControlList::SetActionInternal( gwen::Event::Handler* pObject, void ( gwen::Event::Handler::*f )( gwen::Event::Info ), const gwen::Event::Packet & packet )
{
	for ( List::const_iterator it = list.begin(); it != list.end(); ++it )
	{
		( *it )->SetAction( pObject, f, packet );
	}
}