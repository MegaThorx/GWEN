#include "gwen/UnitTest/UnitTest.h"
#include "gwen/Controls/CheckBox.h"

using namespace gwen;

class Checkbox : public GUnit
{
	public:

		GWEN_CONTROL_INLINE( Checkbox, GUnit )
		{
			gwen::Controls::CheckBox* check = new gwen::Controls::CheckBox( this );
			check->SetPos( 10, 10 );
			check->onChecked.Add( this, &Checkbox::OnChecked );
			check->onUnChecked.Add( this, &Checkbox::OnUnchecked );
			check->onCheckChanged.Add( this, &Checkbox::OnCheckChanged );
			gwen::Controls::CheckBoxWithLabel* labeled = new gwen::Controls::CheckBoxWithLabel( this );
			labeled->SetPos( 10, 30 );
			labeled->Label()->SetText( "Labeled CheckBox" );
			labeled->Checkbox()->onChecked.Add( this, &Checkbox::OnChecked );
			labeled->Checkbox()->onUnChecked.Add( this, &Checkbox::OnUnchecked );
			labeled->Checkbox()->onCheckChanged.Add( this, &Checkbox::OnCheckChanged );
			{
				gwen::Controls::CheckBox* check = new gwen::Controls::CheckBox( this );
				check->SetPos( 10, 54 );
				check->SetDisabled( true );
			}
		}

		void OnChecked( Controls::Base* pControl )
		{
			UnitPrint( L"Checkbox Checked (using 'OnChecked' event)" );
		}

		void OnUnchecked( Controls::Base* pControl )
		{
			UnitPrint( L"Checkbox Unchecked (using 'OnUnchecked' event)" );
		}

		void OnCheckChanged( Controls::Base* pControl )
		{
			UnitPrint( L"Checkbox CheckChanged (using 'OnCheckChanged' event)" );
		}

};



DEFINE_UNIT_TEST( Checkbox, L"Checkbox" );