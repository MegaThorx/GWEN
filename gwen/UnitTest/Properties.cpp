#include "gwen/UnitTest/UnitTest.h"
#include "gwen/Controls/Properties.h"
#include "gwen/Controls/PropertyTree.h"
#include "gwen/Controls/Property/ColorSelector.h"
#include "gwen/Controls/Property/Checkbox.h"
#include "gwen/Controls/Property/ComboBox.h"

using namespace gwen;

class Properties : public GUnit
{
	public:

		GWEN_CONTROL_INLINE( Properties, GUnit )
		{
			{
				gwen::Controls::Properties* props = new gwen::Controls::Properties( this );
				props->SetBounds( 10, 10, 150, 300 );
				{
					{
						gwen::Controls::PropertyRow* pRow = props->Add( L"First Name" );
						pRow->onChange.Add( this, &Properties::OnFirstNameChanged );
					}
					props->Add( L"Middle Name" );
					props->Add( L"Last Name" );
				}
			}
			{
				gwen::Controls::PropertyTree* ptree = new gwen::Controls::PropertyTree( this );
				ptree->SetBounds( 200, 10, 200, 200 );
				{
					gwen::Controls::Properties* props = ptree->Add( L"Item One" );
					props->Add( L"Middle Name" );
					props->Add( L"Last Name" );
					props->Add( L"Four" );
				}
				{
					gwen::Controls::Properties* props = ptree->Add( L"Item Two" );
					props->Add( L"More Items" );
					props->Add( L"Checkbox", new gwen::Controls::Property::Checkbox( props ), L"1" );
					props->Add( L"To Fill" );
					props->Add( L"ColorSelector", new gwen::Controls::Property::ColorSelector( props ), L"255 0 0" );
					props->Add( L"Out Here" );
					// Combo Box Test
					{
						gwen::Controls::Property::ComboBox* pCombo = new gwen::Controls::Property::ComboBox( props );
						pCombo->GetComboBox()->AddItem( L"Option One", "one" );
						pCombo->GetComboBox()->AddItem( L"Number Two", "two" );
						pCombo->GetComboBox()->AddItem( L"Door Three", "three" );
						pCombo->GetComboBox()->AddItem( L"Four Legs", "four" );
						pCombo->GetComboBox()->AddItem( L"Five Birds", "five" );
						gwen::Controls::PropertyRow* pRow = props->Add( L"ComboBox", pCombo, L"1" );
						pRow->onChange.Add( this, &Properties::OnFirstNameChanged );
					}
				}
				ptree->ExpandAll();
			}
		}

		void OnFirstNameChanged( Controls::Base* pControl )
		{
			gwen::Controls::PropertyRow* pRow = ( gwen::Controls::PropertyRow* ) pControl;
			UnitPrint( Utility::Format( L"First Name Changed: %ls", pRow->GetProperty()->GetPropertyValue().GetUnicode().c_str() ) );
		}

};



DEFINE_UNIT_TEST( Properties, L"Properties" );
