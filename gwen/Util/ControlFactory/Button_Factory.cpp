
#include "gwen/Util/ControlFactory.h"
#include "gwen/Controls.h"

namespace gwen
{
	namespace ControlFactory
	{

		class Button_Factory : public gwen::ControlFactory::Base
		{
			public:

				GWEN_CONTROL_FACTORY_CONSTRUCTOR( Button_Factory, gwen::ControlFactory::Base )
				{
				}

				virtual gwen::String Name() { return "Button"; }
				virtual gwen::String BaseName() { return "Label"; }

				virtual gwen::Controls::Base* CreateInstance( gwen::Controls::Base* parent )
				{
					gwen::Controls::Button* pControl = new gwen::Controls::Button( parent );
					pControl->SetSize( 100, 20 );
					pControl->SetText( "New Button" );
					return pControl;
				}
		};


		GWEN_CONTROL_FACTORY( Button_Factory );

	}
}
