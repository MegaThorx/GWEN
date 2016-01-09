#include "gwen/UnitTest/UnitTest.h"
#include "gwen/Controls/RadioButtonController.h"
#include "gwen/Controls/VerticalSlider.h"
#include "gwen/Controls/HorizontalSlider.h"

using namespace gwen;

class Slider : public GUnit
{
	public:

		GWEN_CONTROL_INLINE( Slider, GUnit )
		{
			{
				gwen::Controls::HorizontalSlider* pSlider = new gwen::Controls::HorizontalSlider( this );
				pSlider->SetPos( 10, 10 );
				pSlider->SetSize( 150, 20 );
				pSlider->SetRange( 0, 100 );
				pSlider->SetFloatValue( 25 );
				pSlider->onValueChanged.Add( this, &Slider::SliderMoved );
			}
			{
				gwen::Controls::HorizontalSlider* pSlider = new gwen::Controls::HorizontalSlider( this );
				pSlider->SetPos( 10, 40 );
				pSlider->SetSize( 150, 20 );
				pSlider->SetRange( 0, 100 );
				pSlider->SetFloatValue( 20 );
				pSlider->SetNotchCount( 10 );
				pSlider->SetClampToNotches( true );
				pSlider->onValueChanged.Add( this, &Slider::SliderMoved );
			}
			{
				gwen::Controls::VerticalSlider* pSlider = new gwen::Controls::VerticalSlider( this );
				pSlider->SetPos( 160, 10 );
				pSlider->SetSize( 20, 200 );
				pSlider->SetRange( 0, 100 );
				pSlider->SetFloatValue( 25 );
				pSlider->onValueChanged.Add( this, &Slider::SliderMoved );
			}
			{
				gwen::Controls::VerticalSlider* pSlider = new gwen::Controls::VerticalSlider( this );
				pSlider->SetPos( 190, 10 );
				pSlider->SetSize( 20, 200 );
				pSlider->SetRange( 0, 100 );
				pSlider->SetFloatValue( 20 );
				pSlider->SetNotchCount( 10 );
				pSlider->SetClampToNotches( true );
				pSlider->onValueChanged.Add( this, &Slider::SliderMoved );
			}
		}

		void SliderMoved( Base* pControl )
		{
			gwen::Controls::Slider* pSlider = ( gwen::Controls::Slider* ) pControl;
			UnitPrint( Utility::Format( L"Slider Value: %.2f", ( float ) pSlider->GetFloatValue() ) );
		}

};



DEFINE_UNIT_TEST( Slider, L"Slider" );