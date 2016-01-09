/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#ifndef GWEN_CONTROLS_COLORPICKER_H
#define GWEN_CONTROLS_COLORPICKER_H

#include "gwen/Controls/Base.h"
#include "gwen/Gwen.h"
#include "gwen/Skin.h"


namespace gwen
{
	namespace ControlsInternal
	{
		class GWEN_EXPORT ColorDisplay : public Controls::Base
		{
			public:
				GWEN_CONTROL_INLINE( ColorDisplay, Controls::Base )
				{
					SetSize( 32, 32 );
					m_Color = Color( 255, 0, 0, 255 );
					m_DrawCheckers = true;
				}

				virtual void Render( gwen::Skin::Base* skin )
				{
					skin->DrawColorDisplay( this, m_Color );
				}

				virtual void SetColor( gwen::Color color ) { m_Color = color; }
				virtual gwen::Color GetColor() { return m_Color; }

				virtual void SetRed( int red )  	{ m_Color.r = red;	}
				virtual void SetGreen( int green )	{ m_Color.g = green;}
				virtual void SetBlue( int blue )	{ m_Color.b = blue;	}
				virtual void SetAlpha( int alpha )	{ m_Color.a = alpha;}

				virtual void SetDrawCheckers( bool should ) { m_DrawCheckers = should; }

			protected:
				gwen::Color m_Color;
				bool m_DrawCheckers;
		};
	}
	namespace Controls
	{

		class GWEN_EXPORT ColorPicker : public Base
		{
			public:

				GWEN_CONTROL( ColorPicker, Base );

				virtual void Layout( Skin::Base* skin );
				virtual void CreateControls();
				virtual void SlidersMoved( gwen::Controls::Base* control );
				virtual void NumericTyped( gwen::Controls::Base* control );
				virtual void UpdateControls();
				virtual void UpdateColorControls( gwen::String name, gwen::Color col, int sliderVal );
				virtual void CreateColorControl( gwen::String name, int y );

				virtual void SetColor( gwen::Color color );
				virtual gwen::Color GetColor() { return m_Color; }

				int GetColorByName( gwen::String colorName );
				void SetColorByName( gwen::String colorName, int colorValue );
				gwen::String GetColorFromName( gwen::String name );
				virtual void SetAlphaVisible( bool visible );

				virtual void SetRed( int red )  	{ m_Color.r = red;	}
				virtual void SetGreen( int green )	{ m_Color.g = green;}
				virtual void SetBlue( int blue )	{ m_Color.b = blue;	}
				virtual void SetAlpha( int alpha )	{ m_Color.a = alpha;}

				Event::Caller	onColorChanged;

			protected:
				gwen::Color m_Color;

		};
	}
}
#endif
