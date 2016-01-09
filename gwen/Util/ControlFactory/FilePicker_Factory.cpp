
#include "gwen/Util/ControlFactory.h"
#include "gwen/Controls.h"

namespace gwen
{
	namespace ControlFactory
	{

		using namespace gwen;

		namespace Properties
		{
			using namespace gwen;

			class FileType: public ControlFactory::Property
			{
					GWEN_CONTROL_FACTORY_PROPERTY( FileType, "In the format \"PNG file | *.png\"" );

					UnicodeString GetValue( Controls::Base* ctrl )
					{
						return Utility::StringToUnicode( gwen_cast<Controls::FilePicker> ( ctrl )->GetFileType() );
					}

					void SetValue( Controls::Base* ctrl, const UnicodeString & str )
					{
						gwen_cast<Controls::FilePicker> ( ctrl )->SetFileType( Utility::UnicodeToString( str ) );
					}

			};

		}

		class FilePicker_Factory : public gwen::ControlFactory::Base
		{
			public:

				GWEN_CONTROL_FACTORY_CONSTRUCTOR( FilePicker_Factory, ControlFactory::Base )
				{
					AddProperty( new Properties::FileType() );
				}

				virtual gwen::String Name()     { return "FilePicker"; }
				virtual gwen::String BaseName() { return "Base"; }

				virtual gwen::Controls::Base* CreateInstance( gwen::Controls::Base* parent )
				{
					gwen::Controls::FilePicker* pControl = new gwen::Controls::FilePicker( parent );
					pControl->SetSize( 100, 20 );
					pControl->SetFileType( "EXE file | *.exe" );
					return pControl;
				}
		};

		GWEN_CONTROL_FACTORY( FilePicker_Factory );

	}
}
