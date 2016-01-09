#include "gwen/UnitTest/UnitTest.h"
#include "gwen/Controls/TreeControl.h"

using namespace gwen;

class TreeControl : public GUnit
{
	public:

		GWEN_CONTROL_INLINE( TreeControl, GUnit )
		{
			{
				gwen::Controls::TreeControl* ctrl = new gwen::Controls::TreeControl( this );
				ctrl->AddNode( L"Node One" );
				gwen::Controls::TreeNode* pNode = ctrl->AddNode( L"Node Two" );
				pNode->AddNode( L"Node Two Inside" );
				pNode->AddNode( L"Eyes" );
				pNode->AddNode( L"Brown" )->AddNode( L"Node Two Inside" )->AddNode( L"Eyes" )->AddNode( L"Brown" );
				pNode->AddNode( L"More" );
				pNode->AddNode( L"Nodes" );
				ctrl->AddNode( L"Node Three" );
				ctrl->SetBounds( 30, 30, 200, 200 );
				ctrl->ExpandAll();
			}
			{
				gwen::Controls::TreeControl* ctrl = new gwen::Controls::TreeControl( this );
				ctrl->AllowMultiSelect( true );
				ctrl->AddNode( L"Node One" );
				gwen::Controls::TreeNode* pNode = ctrl->AddNode( L"Node Two" );
				pNode->AddNode( L"Node Two Inside" );
				pNode->AddNode( L"Eyes" );
				gwen::Controls::TreeNode* pNodeTwo = pNode->AddNode( L"Brown" )->AddNode( L"Node Two Inside" )->AddNode( L"Eyes" );
				pNodeTwo->AddNode( L"Brown" );
				pNodeTwo->AddNode( L"Green" );
				pNodeTwo->AddNode( L"Slime" );
				pNodeTwo->AddNode( L"Grass" );
				pNodeTwo->AddNode( L"Pipe" );
				pNode->AddNode( L"More" );
				pNode->AddNode( L"Nodes" );
				ctrl->AddNode( L"Node Three" );
				ctrl->SetBounds( 240, 30, 200, 200 );
				ctrl->ExpandAll();
			}
		}

};



DEFINE_UNIT_TEST( TreeControl, L"TreeControl" );