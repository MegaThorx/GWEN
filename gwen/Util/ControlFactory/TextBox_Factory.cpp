
#include "gwen/Util/ControlFactory.h"
#include "gwen/Controls.h"

namespace gwen
{
	namespace ControlFactory
	{

		class TextBox_Factory : public gwen::ControlFactory::Base
		{
			public:

				GWEN_CONTROL_FACTORY_CONSTRUCTOR( TextBox_Factory, gwen::ControlFactory::Base )
				{
				}

				virtual gwen::String Name() { return "TextBox"; }
				virtual gwen::String BaseName() { return "Label"; }

				virtual gwen::Controls::Base* CreateInstance( gwen::Controls::Base* parent )
				{
					gwen::Controls::TextBox* pControl = new gwen::Controls::TextBox( parent );
					pControl->SetSize( 100, 20 );
					pControl->SetText( "" );
					return pControl;
				}
		};


		class TextBoxMultiLine_Factory : public gwen::ControlFactory::Base
		{
			public:

				GWEN_CONTROL_FACTORY_CONSTRUCTOR( TextBoxMultiLine_Factory, gwen::ControlFactory::Base )
				{
				}

				virtual gwen::String Name() { return "TextBoxMultiline"; }
				virtual gwen::String BaseName() { return "TextBox"; }

				virtual gwen::Controls::Base* CreateInstance( gwen::Controls::Base* parent )
				{
					gwen::Controls::TextBoxMultiline* pControl = new gwen::Controls::TextBoxMultiline( parent );
					pControl->SetSize( 100, 50 );
					pControl->SetText( "" );
					return pControl;
				}
		};


		GWEN_CONTROL_FACTORY( TextBox_Factory );
		GWEN_CONTROL_FACTORY( TextBoxMultiLine_Factory );

	}
}

