/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/


#include "gwen/Controls/Rectangle.h"

using namespace gwen;
using namespace gwen::Controls;


GWEN_CONTROL_CONSTRUCTOR( Rectangle )
{
	m_Color = gwen::Color( 255, 255, 255, 255 );
}

void Rectangle::Render( Skin::Base* skin )
{
	skin->GetRender()->SetDrawColor( m_Color );
	skin->GetRender()->DrawFilledRect( GetRenderBounds() );
}
