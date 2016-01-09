
#include "gwen/Gwen.h"
#include "gwen/Controls/SplitterBar.h"

using namespace gwen;
using namespace Controls;

GWEN_CONTROL_CONSTRUCTOR( SplitterBar )
{
	SetTarget( this );
	RestrictToParent( true );
}

void SplitterBar::Layout( Skin::Base* /*skin*/ )
{
	MoveTo( X(), Y() );
}