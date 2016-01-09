
#include "gwen/Util/ControlFactory.h"
#include "gwen/Controls.h"

namespace gwen
{
	namespace ControlFactory
	{


		class DesignerCanvas_Factory : public gwen::ControlFactory::Base
		{
			public:

				GWEN_CONTROL_FACTORY_CONSTRUCTOR( DesignerCanvas_Factory, gwen::ControlFactory::Base )
				{
				}

				virtual gwen::String Name()     { return "DesignerCanvas"; }
				virtual gwen::String BaseName() { return "Base"; }

				virtual gwen::Controls::Base* CreateInstance( gwen::Controls::Base* parent )
				{
					return NULL;
				}
		};


		GWEN_CONTROL_FACTORY( DesignerCanvas_Factory );

	}
}
