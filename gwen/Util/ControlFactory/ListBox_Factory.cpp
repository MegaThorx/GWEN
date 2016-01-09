
#include "gwen/Util/ControlFactory.h"
#include "gwen/Controls.h"

namespace gwen
{
	namespace ControlFactory
	{

		class ListBox_Factory : public gwen::ControlFactory::Base
		{
			public:

				GWEN_CONTROL_FACTORY_CONSTRUCTOR( ListBox_Factory, gwen::ControlFactory::Base )
				{
				}

				virtual gwen::String Name()     { return "ListBox"; }
				virtual gwen::String BaseName() { return "Base"; }

				virtual gwen::Controls::Base* CreateInstance( gwen::Controls::Base* parent )
				{
					gwen::Controls::ListBox* pControl = new gwen::Controls::ListBox( parent );
					pControl->SetSize( 100, 100 );
					return pControl;
				}
		};


		GWEN_CONTROL_FACTORY( ListBox_Factory );

	}
}
