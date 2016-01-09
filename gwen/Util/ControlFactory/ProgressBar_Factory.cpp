
#include "gwen/Util/ControlFactory.h"
#include "gwen/Controls.h"

namespace gwen
{
	namespace ControlFactory
	{

		using namespace gwen;

		namespace Properties
		{
			class CycleSpeed: public ControlFactory::Property
			{
					GWEN_CONTROL_FACTORY_PROPERTY( CycleSpeed, "" );

					UnicodeString GetValue( Controls::Base* ctrl )
					{
						return Utility::Format( L"%f", ( float ) gwen_cast<Controls::ProgressBar> ( ctrl )->GetCycleSpeed() );
					}

					void SetValue( Controls::Base* ctrl, const UnicodeString & str )
					{
						float num;

						if ( swscanf( str.c_str(), L"%f", &num ) != 1 ) { return; }

						gwen_cast<Controls::ProgressBar> ( ctrl )->SetCycleSpeed( num );
					}

			};

		}

		class ProgressBar_Factory : public gwen::ControlFactory::Base
		{
			public:

				GWEN_CONTROL_FACTORY_CONSTRUCTOR( ProgressBar_Factory, gwen::ControlFactory::Base )
				{
					AddProperty( new Properties::CycleSpeed() );
				}

				virtual gwen::String Name()     { return "ProgressBar"; }
				virtual gwen::String BaseName() { return "Base"; }

				virtual gwen::Controls::Base* CreateInstance( gwen::Controls::Base* parent )
				{
					gwen::Controls::ProgressBar* pControl = new gwen::Controls::ProgressBar( parent );
					pControl->SetSize( 200, 20 );
					return pControl;
				}
		};


		GWEN_CONTROL_FACTORY( ProgressBar_Factory );

	}
}
