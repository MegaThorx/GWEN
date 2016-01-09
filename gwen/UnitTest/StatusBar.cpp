#include "gwen/UnitTest/UnitTest.h"
#include "gwen/Controls/StatusBar.h"
#include "gwen/Controls/Label.h"

using namespace gwen;

class StatusBar : public GUnit
{
	public:

		GWEN_CONTROL_INLINE( StatusBar, GUnit )
		{
			Dock( Pos::Fill );
			gwen::Controls::StatusBar* pStatus = new gwen::Controls::StatusBar( this );
			gwen::Controls::Label* pRight = new gwen::Controls::Label( pStatus );
			pRight->SetText( L"Label Added to Right" );
			pStatus->AddControl( pRight, true );
		}

		void Layout( gwen::Skin::Base* skin ) {}
};



DEFINE_UNIT_TEST( StatusBar, L"StatusBar" );