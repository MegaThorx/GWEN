#include "gwen/Gwen.h"
#include "gwen/Skins/Simple.h"
#include "gwen/Skins/TexturedBase.h"
#include "gwen/UnitTest/UnitTest.h"
#include "gwen/Renderers/OpenGL.h"
#include "gwen/Controls/WindowCanvas.h"

//
// These are the renderers that work with WindowCanvas
// (you need to include the relevant libs to use them)
//
#include "gwen/Renderers/OpenGL_DebugFont.h"
//#include "gwen/Renderers/GDIPlus.h"
//#include "gwen/Renderers/Direct2D.h"
//#include "gwen/Renderers/DirectX9.h"


//
// Program starts here
//
int main()
{
	//
	// Note: Order is important here. you need to create the WindowCanvas before
	// you setup the skin - because the renderer won't be properly set up
	// if you try to do it before (The window canvas initializes the renderer)
	//
	// Create the skin and renderer
	//
	//gwen::Renderer::GDIPlusBuffered		renderer;
	//gwen::Renderer::Direct2D				renderer;
	//gwen::Renderer::DirectX9				renderer;
	gwen::Renderer::OpenGL_DebugFont		renderer;
	gwen::Skin::TexturedBase			skin( &renderer );
	//
	// The window canvas is a cross between a window and a canvas
	// It's cool because it takes care of creating an OS specific
	// window - so we don't have to bother with all that crap.
	//
	//
	gwen::Controls::WindowCanvas window_canvas( -1, -1, 700, 500, &skin, "gwen's Cross Platform Example" );
	//
	// Now it's safe to set up the skin
	//
	skin.Init( "DefaultSkin.png" );
	//
	// Create our unittest control
	//
	UnitTest* pUnit = new UnitTest( &window_canvas );
	pUnit->SetPos( 10, 10 );

	while ( !window_canvas.WantsQuit() )
	{
		window_canvas.DoThink();
	}

	// Everything should be automatically released
	// pUnit is a child of Canvas - which releases all of its children
}