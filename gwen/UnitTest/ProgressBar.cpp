#include "gwen/UnitTest/UnitTest.h"
#include "gwen/Controls/RadioButtonController.h"
#include "gwen/Controls/ProgressBar.h"

using namespace gwen;

class ProgressBar : public GUnit
{
	public:

		GWEN_CONTROL_INLINE( ProgressBar, GUnit )
		{
			{
				gwen::Controls::ProgressBar* pb = new gwen::Controls::ProgressBar( this );
				pb->SetBounds( gwen::Rect( 110, 20, 200, 20 ) );
				pb->SetValue( 0.27f );
			}
			{
				gwen::Controls::ProgressBar* pb = new gwen::Controls::ProgressBar( this );
				pb->SetBounds( gwen::Rect( 110, 50, 200, 20 ) );
				pb->SetValue( 0.66f );
				pb->SetAlignment( Pos::Right | Pos::CenterV );
			}
			{
				gwen::Controls::ProgressBar* pb = new gwen::Controls::ProgressBar( this );
				pb->SetBounds( gwen::Rect( 110, 80, 200, 20 ) );
				pb->SetValue( 0.88f );
				pb->SetAlignment( Pos::Left | Pos::CenterV );
			}
			{
				gwen::Controls::ProgressBar* pb = new gwen::Controls::ProgressBar( this );
				pb->SetBounds( gwen::Rect( 110, 110, 200, 20 ) );
				pb->SetAutoLabel( false );
				pb->SetValue( 0.20f );
				pb->SetAlignment( Pos::Right | Pos::CenterV );
				pb->SetText( L"40,245 MB" );
			}
			{
				gwen::Controls::ProgressBar* pb = new gwen::Controls::ProgressBar( this );
				pb->SetBounds( gwen::Rect( 110, 140, 200, 20 ) );
				pb->SetAutoLabel( false );
				pb->SetValue( 1.00f );
			}
			{
				gwen::Controls::ProgressBar* pb = new gwen::Controls::ProgressBar( this );
				pb->SetBounds( gwen::Rect( 110, 170, 200, 20 ) );
				pb->SetAutoLabel( false );
				pb->SetValue( 0.00f );
			}
			{
				gwen::Controls::ProgressBar* pb = new gwen::Controls::ProgressBar( this );
				pb->SetBounds( gwen::Rect( 110, 200, 200, 20 ) );
				pb->SetAutoLabel( false );
				pb->SetValue( 0.50f );
			}
			{
				gwen::Controls::ProgressBar* pb = new gwen::Controls::ProgressBar( this );
				pb->SetBounds( gwen::Rect( 20, 20, 25, 200 ) );
				pb->SetVertical();
				pb->SetValue( 0.25f );
				pb->SetAlignment( Pos::Top | Pos::CenterH );
			}
			{
				gwen::Controls::ProgressBar* pb = new gwen::Controls::ProgressBar( this );
				pb->SetBounds( gwen::Rect( 50, 20, 25, 200 ) );
				pb->SetVertical();
				pb->SetValue( 0.40f );
			}
			{
				gwen::Controls::ProgressBar* pb = new gwen::Controls::ProgressBar( this );
				pb->SetBounds( gwen::Rect( 80, 20, 25, 200 ) );
				pb->SetVertical();
				pb->SetAlignment( Pos::Bottom | Pos::CenterH );
				pb->SetValue( 0.65f );
			}
		}

};



DEFINE_UNIT_TEST( ProgressBar, L"ProgressBar" );