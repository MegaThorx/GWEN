/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#ifndef GWEN_CONTROLS_HSVCOLORPICKER_H
#define GWEN_CONTROLS_HSVCOLORPICKER_H

#include "gwen/Controls/Base.h"
#include "gwen/Gwen.h"
#include "gwen/Skin.h"
#include "gwen/Controls/ColorControls.h"
#include "gwen/Controls/ColorPicker.h"


namespace gwen
{
	namespace Controls
	{
		class GWEN_EXPORT HSVColorPicker : public Controls::Base
		{
			public:
				GWEN_CONTROL( HSVColorPicker, Controls::Base );

				gwen::Color GetColor();
				gwen::Color GetDefaultColor() { return m_Before->GetColor(); }
				void SetColor( gwen::Color color, bool onlyHue = false, bool reset = false );

				void ColorBoxChanged( gwen::Controls::Base* pControl );
				void ColorSliderChanged( gwen::Controls::Base* pControl );
				void NumericTyped( gwen::Controls::Base* control );

				void UpdateControls( gwen::Color newColor );

				Event::Caller	onColorChanged;

			protected:
				ColorLerpBox* m_LerpBox;
				ColorSlider* m_ColorSlider;
				ControlsInternal::ColorDisplay* m_Before;
				ControlsInternal::ColorDisplay* m_After;
		};
	}
}
#endif
