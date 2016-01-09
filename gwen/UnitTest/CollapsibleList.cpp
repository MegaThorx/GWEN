#include "gwen/UnitTest/UnitTest.h"
#include "gwen/Controls/CollapsibleList.h"

using namespace gwen;

class CollapsibleList : public GUnit
{
	public:

		GWEN_CONTROL_INLINE( CollapsibleList, GUnit )
		{
			gwen::Controls::CollapsibleList* pControl = new gwen::Controls::CollapsibleList( this );
			pControl->SetSize( 100, 200 );
			pControl->SetPos( 10, 10 );
			{
				gwen::Controls::CollapsibleCategory* cat = pControl->Add( "Category One" );
				cat->Add( "Hello" );
				cat->Add( "Two" );
				cat->Add( "Three" );
				cat->Add( "Four" );
			}
			{
				gwen::Controls::CollapsibleCategory* cat = pControl->Add( "Shopping" );
				cat->Add( "Special" );
				cat->Add( "Two Noses" );
				cat->Add( "Orange ears" );
				cat->Add( "Beer" );
				cat->Add( "Three Eyes" );
				cat->Add( "Special" );
				cat->Add( "Two Noses" );
				cat->Add( "Orange ears" );
				cat->Add( "Beer" );
				cat->Add( "Three Eyes" );
				cat->Add( "Special" );
				cat->Add( "Two Noses" );
				cat->Add( "Orange ears" );
				cat->Add( "Beer" );
				cat->Add( "Three Eyes" );
			}
			{
				gwen::Controls::CollapsibleCategory* cat = pControl->Add( "Category One" );
				cat->Add( "Hello" );
				cat->Add( "Two" );
				cat->Add( "Three" );
				cat->Add( "Four" );
			}
		}
};



DEFINE_UNIT_TEST( CollapsibleList, L"CollapsibleList" );