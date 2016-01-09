
#include "gwen/Util/ControlFactory.h"
#include "gwen/Controls.h"

namespace gwen
{
	namespace ControlFactory
	{

		class MenuStrip_Factory : public gwen::ControlFactory::Base
		{
			public:

				GWEN_CONTROL_FACTORY_CONSTRUCTOR( MenuStrip_Factory, gwen::ControlFactory::Base )
				{
				}

				virtual gwen::String Name()     { return "MenuStrip"; }
				virtual gwen::String BaseName() { return "Base"; }

				virtual gwen::Controls::Base* CreateInstance( gwen::Controls::Base* parent )
				{
					gwen::Controls::MenuStrip* pControl = new gwen::Controls::MenuStrip( parent );
					return pControl;
				}
		};


		GWEN_CONTROL_FACTORY( MenuStrip_Factory );

	}
}
