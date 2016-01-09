/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/


#include "gwen/Controls/Slider.h"
#include "gwen/Controls/VerticalSlider.h"

using namespace gwen;
using namespace gwen::Controls;
using namespace gwen::ControlsInternal;


GWEN_CONTROL_CONSTRUCTOR( VerticalSlider )
{
	m_SliderBar->SetHorizontal( false );
}

float VerticalSlider::CalculateValue()
{
	return  1 - ( float ) m_SliderBar->Y() / ( float )( Height() - m_SliderBar->Height() );
}

void VerticalSlider::UpdateBarFromValue()
{
	m_SliderBar->MoveTo( m_SliderBar->X(), ( Height() - m_SliderBar->Height() ) * ( 1 - m_fValue ) );
}


void VerticalSlider::OnMouseClickLeft( int x, int y, bool bDown )
{
	m_SliderBar->MoveTo( m_SliderBar->X(), CanvasPosToLocal( gwen::Point( x, y ) ).y - m_SliderBar->Height() * 0.5 );
	m_SliderBar->OnMouseClickLeft( x, y, bDown );
	OnMoved( m_SliderBar );
}


void VerticalSlider::Layout( Skin::Base* /*skin*/ )
{
	m_SliderBar->SetSize( Width(), 15 );
}


void VerticalSlider::Render( Skin::Base* skin )
{
	skin->DrawSlider( this, false, m_bClampToNotches ? m_iNumNotches : 0, m_SliderBar->Height() );
}