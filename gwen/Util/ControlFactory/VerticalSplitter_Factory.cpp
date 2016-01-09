
#include "gwen/Util/ControlFactory.h"
#include "gwen/Controls.h"

namespace gwen
{
	namespace ControlFactory
	{

		using namespace gwen;

		class VerticalSplitter_Factory : public gwen::ControlFactory::Base
		{
			public:

				GWEN_CONTROL_FACTORY_CONSTRUCTOR( VerticalSplitter_Factory, gwen::ControlFactory::Base )
				{
				}

				virtual gwen::String Name() { return "VerticalSplitter"; }
				virtual gwen::String BaseName() { return "Base"; }

				virtual gwen::Controls::Base* CreateInstance( gwen::Controls::Base* parent )
				{
					gwen::Controls::SplitterVertical* pControl = new gwen::Controls::SplitterVertical( parent );
					pControl->SetSize( 200, 200 );
					return pControl;
				}

				void AddChild( gwen::Controls::Base* ctrl, gwen::Controls::Base* child, gwen::Point & pos )
				{
					gwen::Controls::SplitterVertical* pSplitter = gwen_cast<gwen::Controls::SplitterVertical> ( ctrl );
					child->SetParent( pSplitter );

					if ( pos.y < pSplitter->SplitterPos() )
					{ pSplitter->SetPanels( child, NULL ); }
					else
					{ pSplitter->SetPanels( NULL, child ); }
				}

				void AddChild( gwen::Controls::Base* ctrl, gwen::Controls::Base* child, int iPage )
				{
					child->SetParent( ctrl );
				}
		};


		GWEN_CONTROL_FACTORY( VerticalSplitter_Factory );

	}
}

