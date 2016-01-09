
#include "gwen/Util/ControlFactory.h"
#include "gwen/Controls.h"


namespace gwen
{
	namespace ControlFactory
	{

		using namespace gwen;

		namespace Properties
		{

			class Min: public ControlFactory::Property
			{
					GWEN_CONTROL_FACTORY_PROPERTY( Min, "The minimum value" );

					UnicodeString GetValue( Controls::Base* ctrl )
					{
						return gwen::Utility::Format( L"%f", ( int ) gwen_cast<Controls::Slider> ( ctrl )->GetMin() );
					}

					void SetValue( Controls::Base* ctrl, const UnicodeString & str )
					{
						float val;

						if ( swscanf( str.c_str(), L"%f", &val ) != 1 ) { return; }

						if ( val == gwen_cast<Controls::Slider> ( ctrl )->GetMin() ) { return; }

						gwen_cast<Controls::Slider> ( ctrl )->SetRange( val, gwen_cast<Controls::Slider> ( ctrl )->GetMax() );
					}

			};

			class Max: public ControlFactory::Property
			{
					GWEN_CONTROL_FACTORY_PROPERTY( Max, "The max value" );

					UnicodeString GetValue( Controls::Base* ctrl )
					{
						return gwen::Utility::Format( L"%f", ( int ) gwen_cast<Controls::Slider> ( ctrl )->GetMax() );
					}

					void SetValue( Controls::Base* ctrl, const UnicodeString & str )
					{
						float val;

						if ( swscanf( str.c_str(), L"%f", &val ) != 1 ) { return; }

						if ( val == gwen_cast<Controls::Slider> ( ctrl )->GetMax() ) { return; }

						gwen_cast<Controls::Slider> ( ctrl )->SetRange( gwen_cast<Controls::Slider> ( ctrl )->GetMin(), val );
					}

			};
		}

		class HorizontalSlider_Factory : public gwen::ControlFactory::Base
		{
			public:

				GWEN_CONTROL_FACTORY_CONSTRUCTOR( HorizontalSlider_Factory, gwen::ControlFactory::Base )
				{
					AddProperty( new Properties::Min() );
					AddProperty( new Properties::Max() );
				}

				virtual gwen::String Name() { return "HorizontalSlider"; }
				virtual gwen::String BaseName() { return "Base"; }

				virtual gwen::Controls::Base* CreateInstance( gwen::Controls::Base* parent )
				{
					gwen::Controls::HorizontalSlider* pControl = new gwen::Controls::HorizontalSlider( parent );
					pControl->SetSize( 100, 20 );
					pControl->SetRange( 0, 1 );
					return pControl;
				}
		};


		GWEN_CONTROL_FACTORY( HorizontalSlider_Factory );

	}
}
