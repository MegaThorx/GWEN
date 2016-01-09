/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/


#include "gwen/Controls/RadioButton.h"

using namespace gwen;
using namespace gwen::Controls;

GWEN_CONTROL_CONSTRUCTOR( RadioButton )
{
	SetSize( 15, 15 );
	SetMouseInputEnabled( true );
	SetTabable( false );
}

void RadioButton::Render( Skin::Base* skin )
{
	skin->DrawRadioButton( this, IsChecked(), IsDepressed() );
}

