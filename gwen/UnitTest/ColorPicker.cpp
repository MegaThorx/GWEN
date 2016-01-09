#include "gwen/UnitTest/UnitTest.h"
#include "gwen/Controls/ColorPicker.h"
#include "gwen/Controls/HSVColorPicker.h"

using namespace gwen;

class ColorPicker : public GUnit
{
	public:

		GWEN_CONTROL_INLINE( ColorPicker, GUnit )
		{
			Controls::ColorPicker* pCtrl = new Controls::ColorPicker( this );
			pCtrl->SetBounds( 0, 10, 250, 150 );
			Controls::HSVColorPicker* pHSVCtrl = new Controls::HSVColorPicker( this );
			pHSVCtrl->SetBounds( 260, 10, 250, 150 );
		}
};



DEFINE_UNIT_TEST( ColorPicker, L"ColorPicker" );
