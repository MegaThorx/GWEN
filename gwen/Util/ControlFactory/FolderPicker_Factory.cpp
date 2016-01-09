
#include "gwen/Util/ControlFactory.h"
#include "gwen/Controls.h"

namespace gwen
{
	namespace ControlFactory
	{

		using namespace gwen;

		class FolderPicker_Factory : public gwen::ControlFactory::Base
		{
			public:

				GWEN_CONTROL_FACTORY_CONSTRUCTOR( FolderPicker_Factory, ControlFactory::Base )
				{
				}

				virtual gwen::String Name()     { return "FolderPicker"; }
				virtual gwen::String BaseName() { return "Base"; }

				virtual gwen::Controls::Base* CreateInstance( gwen::Controls::Base* parent )
				{
					gwen::Controls::FolderPicker* pControl = new gwen::Controls::FolderPicker( parent );
					pControl->SetSize( 100, 20 );
					return pControl;
				}
		};

		GWEN_CONTROL_FACTORY( FolderPicker_Factory );

	}
}
