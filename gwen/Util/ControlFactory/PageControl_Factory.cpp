
#include "gwen/Util/ControlFactory.h"
#include "gwen/Controls.h"


namespace gwen
{
	namespace ControlFactory
	{

		using namespace gwen;

		namespace Properties
		{
			class NumPages: public ControlFactory::Property
			{
					GWEN_CONTROL_FACTORY_PROPERTY( NumPages, "The number of pages we have" );

					UnicodeString GetValue( Controls::Base* ctrl )
					{
						return Utility::Format( L"%i", ( int ) gwen_cast<Controls::PageControl> ( ctrl )->GetPageCount() );
					}

					void SetValue( Controls::Base* ctrl, const UnicodeString & str )
					{
						int num;

						if ( swscanf( str.c_str(), L"%i", &num ) != 1 ) { return; }

						gwen_cast<Controls::PageControl> ( ctrl )->SetPageCount( num );
					}

			};

			class FinishName: public ControlFactory::Property
			{
					GWEN_CONTROL_FACTORY_PROPERTY( FinishName, "The name of the finish button" );

					UnicodeString GetValue( Controls::Base* ctrl )
					{
						gwen::Controls::PageControl* pControl = gwen_cast<gwen::Controls::PageControl> ( ctrl );
						return Utility::StringToUnicode( pControl->FinishButton()->GetName() );
					}

					void SetValue( Controls::Base* ctrl, const UnicodeString & str )
					{
						gwen::Controls::PageControl* pControl = gwen_cast<gwen::Controls::PageControl> ( ctrl );
						pControl->FinishButton()->SetName( Utility::UnicodeToString( str ) );
					}
			};

		}

		class PageControl_Factory : public gwen::ControlFactory::Base
		{
			public:

				GWEN_CONTROL_FACTORY_CONSTRUCTOR( PageControl_Factory, gwen::ControlFactory::Base )
				{
					AddProperty( new Properties::NumPages() );
					AddProperty( new Properties::FinishName() );
				}

				virtual gwen::String Name()     { return "PageControl"; }
				virtual gwen::String BaseName() { return "Base"; }

				virtual gwen::Controls::Base* CreateInstance( gwen::Controls::Base* parent )
				{
					gwen::Controls::PageControl* pControl = new gwen::Controls::PageControl( parent );
					pControl->SetSize( 300, 300 );
					pControl->SetPageCount( 1 );
					return pControl;
				}

				//
				// Called when a child is clicked on in the editor
				//
				virtual bool ChildTouched( gwen::Controls::Base* ctrl, gwen::Controls::Base* pChildControl )
				{
					gwen::Controls::PageControl* pControl = gwen_cast<gwen::Controls::PageControl> ( ctrl );

					if ( pChildControl == pControl->NextButton() ) { pControl->NextButton()->DoAction(); return true; }

					if ( pChildControl == pControl->BackButton() ) { pControl->BackButton()->DoAction(); return true; }

					return false;
				}

				//
				// A child is being dropped on this position.. set the parent properly
				//
				void AddChild( gwen::Controls::Base* ctrl, gwen::Controls::Base* child, const gwen::Point & pos )
				{
					gwen::Controls::PageControl* pControl = gwen_cast<gwen::Controls::PageControl> ( ctrl );
					AddChild( ctrl, child, pControl->GetPageNumber() );
				}

				void AddChild( gwen::Controls::Base* ctrl, gwen::Controls::Base* child, int iPage )
				{
					gwen::Controls::PageControl* pControl = gwen_cast<gwen::Controls::PageControl> ( ctrl );

					if ( !pControl->GetPage( iPage ) ) { iPage = 0; }

					SetParentPage( child, iPage );
					child->SetParent( pControl->GetPage( iPage ) );
				}
		};


		GWEN_CONTROL_FACTORY( PageControl_Factory );

	}
}
