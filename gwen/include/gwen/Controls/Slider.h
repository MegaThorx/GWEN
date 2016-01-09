/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#ifndef GWEN_CONTROLS_SLIDER_H
#define GWEN_CONTROLS_SLIDER_H

#include "gwen/Controls/Base.h"
#include "gwen/Controls/Button.h"
#include "gwen/Controls/Dragger.h"
#include "gwen/Gwen.h"
#include "gwen/Skin.h"

namespace gwen
{
	namespace ControlsInternal
	{
		class GWEN_EXPORT SliderBar : public ControlsInternal::Dragger
		{
				GWEN_CONTROL( SliderBar, ControlsInternal::Dragger );

				virtual void Render( Skin::Base* skin );
				virtual void SetHorizontal( bool b ) { m_bHorizontal = b; }
				virtual bool IsHorizontal() { return m_bHorizontal; }

			protected:

				bool m_bHorizontal;
		};
	}

	namespace Controls
	{

		class GWEN_EXPORT Slider : public Base
		{
				GWEN_CONTROL( Slider, Base );

				virtual void Render( Skin::Base* skin ) = 0;
				virtual void Layout( Skin::Base* skin );

				virtual void SetClampToNotches( bool bClamp ) { m_bClampToNotches = bClamp; }

				virtual void SetNotchCount( int num ) { m_iNumNotches = num; }
				virtual int GetNotchCount() { return m_iNumNotches; }

				virtual void SetRange( float fMin, float fMax );
				virtual float GetFloatValue();
				virtual void SetFloatValue( float val, bool forceUpdate = true );

				virtual float CalculateValue();
				virtual void OnMoved( Controls::Base* control );

				virtual void OnMouseClickLeft( int /*x*/, int /*y*/, bool /*bDown*/ ) {};

				virtual bool OnKeyRight( bool bDown )	{	if ( bDown ) { SetFloatValue( GetFloatValue() + 1, true ); } return true; }
				virtual bool OnKeyLeft( bool bDown )	{	if ( bDown ) { SetFloatValue( GetFloatValue() - 1, true ); } return true; }
				virtual bool OnKeyUp( bool bDown )		{	if ( bDown ) { SetFloatValue( GetFloatValue() + 1, true ); } return true; }
				virtual bool OnKeyDown( bool bDown )	{	if ( bDown ) { SetFloatValue( GetFloatValue() - 1, true ); } return true; }

				virtual void RenderFocus( gwen::Skin::Base* skin );

				gwen::Event::Caller	onValueChanged;

				virtual float GetMin() { return m_fMin; }
				virtual float GetMax() { return m_fMax; }

			protected:

				virtual void SetValueInternal( float fVal );
				virtual void UpdateBarFromValue(){};

				ControlsInternal::SliderBar* m_SliderBar;
				void OnBoundsChanged( gwen::Rect oldBounds );
				bool m_bClampToNotches;
				int m_iNumNotches;
				float m_fValue;

				float m_fMin;
				float m_fMax;

		};
	}


}
#endif
