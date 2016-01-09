
#include "gwen/Util/ControlFactory.h"
#include "gwen/Controls.h"

namespace gwen
{
	namespace ControlFactory
	{

		using namespace gwen;

		namespace Properties
		{

			class Color : public ControlFactory::Property
			{
					GWEN_CONTROL_FACTORY_PROPERTY( Color, "Rectangle's Background Color" );

					UnicodeString GetValue( Controls::Base* ctrl )
					{
						Controls::Rectangle* pRect = gwen_cast<Controls::Rectangle> ( ctrl );
						return Utility::Format( L"%i %i %i %i", pRect->GetColor().r, pRect->GetColor().g, pRect->GetColor().b, pRect->GetColor().a );
					}

					void SetValue( Controls::Base* ctrl, const UnicodeString & str )
					{
						Controls::Rectangle* pRect = gwen_cast<Controls::Rectangle> ( ctrl );
						int r, g, b, a;

						if ( swscanf( str.c_str(), L"%i %i %i %i", &r, &g, &b, &a ) != 4 ) { return; }

						pRect->SetColor( gwen::Color( r, g, b, a ) );
					}

					int	NumCount() { return 4; };

					gwen::String NumName( int i )
					{
						if ( i == 0 ) { return "r"; }

						if ( i == 1 ) { return "g"; }

						if ( i == 2 ) { return "b"; }

						return "a";
					}

					float NumGet( Controls::Base* ctrl, int i )
					{
						Controls::Rectangle* pRect = gwen_cast<Controls::Rectangle> ( ctrl );

						if ( i == 0 ) { return pRect->GetColor().r; }

						if ( i == 1 ) { return pRect->GetColor().g; }

						if ( i == 2 ) { return pRect->GetColor().b; }

						return pRect->GetColor().a;
					}

					void NumSet( Controls::Base* ctrl, int i, float f )
					{
						Controls::Rectangle* pRect = gwen_cast<Controls::Rectangle> ( ctrl );
						gwen::Color c = pRect->GetColor();

						if ( i == 0 ) { c.r = f; }

						if ( i == 1 ) { c.g = f; }

						if ( i == 2 ) { c.b = f; }

						if ( i == 3 ) { c.a = f; }

						pRect->SetColor( c );
					}

			};

		}


		class Rectangle_Factory : public gwen::ControlFactory::Base
		{
			public:

				GWEN_CONTROL_FACTORY_CONSTRUCTOR( Rectangle_Factory, ControlFactory::Base )
				{
					AddProperty( new Properties::Color() );
				}

				virtual gwen::String Name() { return "Rectangle"; }
				virtual gwen::String BaseName() { return "Base"; }

				virtual gwen::Controls::Base* CreateInstance( gwen::Controls::Base* parent )
				{
					gwen::Controls::Rectangle* pControl = new gwen::Controls::Rectangle( parent );
					pControl->SetSize( 100, 100 );
					return pControl;
				}
		};

		GWEN_CONTROL_FACTORY( Rectangle_Factory );

	}
}
