
#include "gwen/Util/ControlFactory.h"
#include "gwen/Controls.h"

namespace gwen
{
	namespace ControlFactory
	{

		class CheckBox_Factory : public gwen::ControlFactory::Base
		{
			public:

				GWEN_CONTROL_FACTORY_CONSTRUCTOR( CheckBox_Factory, gwen::ControlFactory::Base )
				{
				}

				virtual gwen::String Name() { return "CheckBox"; }
				virtual gwen::String BaseName() { return "Base"; }

				virtual gwen::Controls::Base* CreateInstance( gwen::Controls::Base* parent )
				{
					gwen::Controls::CheckBox* pControl = new gwen::Controls::CheckBox( parent );
					return pControl;
				}
		};

		GWEN_CONTROL_FACTORY( CheckBox_Factory );



		namespace Properties
		{
			class CheckboxText: public ControlFactory::Property
			{
					GWEN_CONTROL_FACTORY_PROPERTY( CheckboxText, "The text, or label of the control" );

					UnicodeString GetValue( Controls::Base* ctrl )
					{
						return gwen_cast<Controls::CheckBoxWithLabel> ( ctrl )->Label()->GetText().GetUnicode();
					}

					void SetValue( Controls::Base* ctrl, const UnicodeString & str )
					{
						gwen_cast<Controls::CheckBoxWithLabel> ( ctrl )->Label()->SetText( str );
					}

			};
		}

		class CheckBoxWithLabel_Factory : public gwen::ControlFactory::Base
		{
			public:

				GWEN_CONTROL_FACTORY_CONSTRUCTOR( CheckBoxWithLabel_Factory, gwen::ControlFactory::Base )
				{
					AddProperty( new Properties::CheckboxText() );
				}

				virtual gwen::String Name()     { return "CheckBoxWithLabel"; }
				virtual gwen::String BaseName() { return "Base"; }

				virtual gwen::Controls::Base* CreateInstance( gwen::Controls::Base* parent )
				{
					gwen::Controls::CheckBoxWithLabel* pControl = new gwen::Controls::CheckBoxWithLabel( parent );
					return pControl;
				}
		};


		GWEN_CONTROL_FACTORY( CheckBoxWithLabel_Factory );

	}
}
