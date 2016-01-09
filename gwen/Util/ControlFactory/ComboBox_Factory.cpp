
#include "gwen/Util/ControlFactory.h"
#include "gwen/Controls.h"

namespace gwen
{
	namespace ControlFactory
	{

		class ComboBox_Factory : public gwen::ControlFactory::Base
		{
			public:

				GWEN_CONTROL_FACTORY_CONSTRUCTOR( ComboBox_Factory, gwen::ControlFactory::Base )
				{
				}

				virtual gwen::String Name()     { return "ComboBox"; }
				virtual gwen::String BaseName() { return "Base"; }

				virtual gwen::Controls::Base* CreateInstance( gwen::Controls::Base* parent )
				{
					gwen::Controls::ComboBox* pControl = new gwen::Controls::ComboBox( parent );
					pControl->SetSize( 100, 20 );
					return pControl;
				}
		};


		GWEN_CONTROL_FACTORY( ComboBox_Factory );

	}
}
