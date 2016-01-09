#include "gwen/UnitTest/UnitTest.h"
#include "gwen/Controls/ImagePanel.h"

using namespace gwen;

class ImagePanel : public GUnit
{
	public:

		GWEN_CONTROL_INLINE( ImagePanel, GUnit )
		{
			// Normal
			{
				Controls::ImagePanel* img = new Controls::ImagePanel( this );
				img->SetImage( L"gwen.png" );
				img->SetBounds( 10, 10, 100, 100 );
			}
			// Missing
			{
				Controls::ImagePanel* img = new Controls::ImagePanel( this );
				img->SetImage( L"missingimage.png" );
				img->SetBounds( 120, 10, 100, 100 );
			}
		}

};



DEFINE_UNIT_TEST( ImagePanel, L"ImagePanel" );