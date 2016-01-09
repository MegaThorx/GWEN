/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#ifndef GWEN_CONTROLS_HORIZONTALSLIDER_H
#define GWEN_CONTROLS_HORIZONTALSLIDER_H

#include "gwen/Controls/Base.h"
#include "gwen/Controls/Button.h"
#include "gwen/Controls/Dragger.h"
#include "gwen/Gwen.h"
#include "gwen/Skin.h"
#include "gwen/Controls/Slider.h"

namespace gwen
{
	namespace Controls
	{
		class GWEN_EXPORT HorizontalSlider : public Slider
		{
				GWEN_CONTROL( HorizontalSlider, Slider );

				virtual void Layout( Skin::Base* skin );
				virtual void Render( Skin::Base* skin );

				virtual float CalculateValue();
				virtual void UpdateBarFromValue();
				virtual void OnMouseClickLeft( int x, int y, bool bDown );
		};
	}
}
#endif
