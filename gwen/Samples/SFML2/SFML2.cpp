#include <SFML/Graphics.hpp>
#include <cmath>

#include "gwen/Renderers/SFML2.h"
#include "gwen/Input/SFML.h"

#include "gwen/Skins/Simple.h"
#include "gwen/Skins/TexturedBase.h"
#include "gwen/UnitTest/UnitTest.h"

////////////////////////////////////////////////////////////
/// Entry point of application
///
/// \return Application exit code
///
////////////////////////////////////////////////////////////
int main()
{
	// Create the window of the application
	sf::RenderWindow App( sf::VideoMode( 1004, 650, 32 ), "GWEN: SFML2");

	gwen::Renderer::SFML2 gwenRenderer( App );

	//
	// Create a GWEN skin
	//
	//gwen::Skin::Simple skin;
	//skin.SetRender( &gwenRenderer );

	gwen::Skin::TexturedBase skin( &gwenRenderer );
	skin.Init( "DefaultSkin.png" );

	// The fonts work differently in SFML - it can't use
	// system fonts. So force the skin to use a local one.
	skin.SetDefaultFont( L"OpenSans.ttf", 11 );


	//
	// Create a Canvas (it's root, on which all other GWEN panels are created)
	//
	gwen::Controls::Canvas* pCanvas = new gwen::Controls::Canvas( &skin );

	pCanvas->SetSize( App.getSize().x, App.getSize().y );
	pCanvas->SetDrawBackground( true );
	pCanvas->SetBackgroundColor( gwen::Color( 150, 170, 170, 255 ) );

	//
	// Create our unittest control (which is a Window with controls in it)
	//
	UnitTest* pUnit = new UnitTest( pCanvas );

	//
	// Create an input processor
	//
	gwen::Input::SFML gwenInput;
	gwenInput.Initialize( pCanvas );

	while ( App.isOpen() )
	{
		// Handle events
		sf::Event Event;

		while ( App.pollEvent( Event ) )
		{
			// Window closed or escape key pressed : exit
			if ( (Event.type == sf::Event::Closed) || 
				( (Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape) ) )
			{
				App.close();
				break;
			}
			else if ( Event.type == sf::Event::Resized )
			{
				pCanvas->SetSize( Event.size.width, Event.size.height );
			}

			gwenInput.ProcessMessage( Event );
		}

		// Clear the window

        App.clear();		
		pCanvas->RenderCanvas();		
    	App.display();
	}

	return EXIT_SUCCESS;
}
