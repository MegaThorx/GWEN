#include "gwen/UnitTest/UnitTest.h"
#include "gwen/Controls/ComboBox.h"

using namespace gwen;

class ComboBox : public GUnit
{
	public:

		GWEN_CONTROL_INLINE( ComboBox, GUnit )
		{
			{
				gwen::Controls::ComboBox* combo = new gwen::Controls::ComboBox( this );
				combo->SetPos( 50, 50 );
				combo->SetWidth( 200 );
				combo->AddItem( L"Option One", "one" );
				combo->AddItem( L"Number Two", "two" );
				combo->AddItem( L"Door Three", "three" );
				combo->AddItem( L"Four Legs", "four" );
				combo->AddItem( L"Five Birds", "five" );
				combo->onSelection.Add( this, &ComboBox::OnComboSelect );
			}
			{
				// Empty..
				gwen::Controls::ComboBox* combo = new gwen::Controls::ComboBox( this );
				combo->SetPos( 50, 80 );
				combo->SetWidth( 200 );
			}
			{
				// Empty..
				gwen::Controls::ComboBox* combo = new gwen::Controls::ComboBox( this );
				combo->SetPos( 50, 110 );
				combo->SetWidth( 200 );

				for ( int i = 0; i < 500; i++ )
				{ combo->AddItem( L"Lots Of Options" ); }
			}
		}

		void OnComboSelect( gwen::Controls::Base* pControl )
		{
			gwen::Controls::ComboBox* combo = ( gwen::Controls::ComboBox* ) pControl;
			UnitPrint( Utility::Format( L"Combo Changed: %ls", combo->GetSelectedItem()->GetText().GetUnicode().c_str() ) );
		}
};



DEFINE_UNIT_TEST( ComboBox, L"ComboBox" );
