/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/


#include "gwen/Gwen.h"
#include "gwen/Skin.h"
#include "gwen/Controls/LabelClickable.h"

using namespace gwen;
using namespace gwen::Controls;

GWEN_CONTROL_CONSTRUCTOR( LabelClickable )
{
	SetIsToggle( false );
	SetCursor( gwen::CursorType::Finger );
	SetAlignment( gwen::Pos::Left | gwen::Pos::CenterV );
}

void LabelClickable::Render( Skin::Base* /*skin*/ )
{
	//skin->DrawButton( this, IsDepressed(), IsToggle() && GetToggleState() );
}