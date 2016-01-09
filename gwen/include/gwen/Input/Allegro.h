/*
	GWEN
	Copyright (c) 2011 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#ifndef GWEN_INPUT_ALLEGRO_H
#define GWEN_INPUT_ALLEGRO_H

#include "gwen/InputHandler.h"
#include "gwen/Gwen.h"
#include "gwen/Controls/Canvas.h"

#include <allegro5/allegro.h>

namespace gwen
{
	namespace Input
	{
		class Allegro
		{
			public:

				Allegro()
				{
					m_Canvas = NULL;
					m_MouseX = 0;
					m_MouseY = 0;
				}

				void Initialize( gwen::Controls::Canvas* c )
				{
					m_Canvas = c;
				}

				unsigned char TranslateKeyCode( int iKeyCode )
				{
					switch ( iKeyCode )
					{
						case ALLEGRO_KEY_BACKSPACE:
							return gwen::Key::Backspace;

						case ALLEGRO_KEY_ENTER:
							return gwen::Key::Return;

						case ALLEGRO_KEY_ESCAPE:
							return gwen::Key::Escape;

						case ALLEGRO_KEY_TAB:
							return gwen::Key::Tab;

						case ALLEGRO_KEY_SPACE:
							return gwen::Key::Space;

						case ALLEGRO_KEY_UP:
							return gwen::Key::Up;

						case ALLEGRO_KEY_DOWN:
							return gwen::Key::Down;

						case ALLEGRO_KEY_LEFT:
							return gwen::Key::Left;

						case ALLEGRO_KEY_RIGHT:
							return gwen::Key::Right;

						case ALLEGRO_KEY_HOME:
							return gwen::Key::Home;

						case ALLEGRO_KEY_END:
							return gwen::Key::End;

						case ALLEGRO_KEY_DELETE:
							return gwen::Key::Delete;

						case ALLEGRO_KEY_LCTRL:
							return gwen::Key::Control;

						case ALLEGRO_KEY_ALT:
							return gwen::Key::Alt;

						case ALLEGRO_KEY_LSHIFT:
							return gwen::Key::Shift;

						case ALLEGRO_KEY_RCTRL:
							return gwen::Key::Control;

						case ALLEGRO_KEY_ALTGR:
							return gwen::Key::Alt;

						case ALLEGRO_KEY_RSHIFT:
							return gwen::Key::Shift;
					}

					return gwen::Key::Invalid;
				}

				bool ProcessMessage( ALLEGRO_EVENT & event )
				{
					if ( !m_Canvas ) { return false; }

					switch ( event.type )
					{
						case ALLEGRO_EVENT_MOUSE_AXES:
							{
								int dx = event.mouse.x - m_MouseX;
								int dy = event.mouse.y - m_MouseY;

								if ( event.mouse.dz != 0 )
								{
									return m_Canvas->InputMouseWheel( event.mouse.dz * 60 );
								}

								m_MouseX = event.mouse.x;
								m_MouseY = event.mouse.y;
								return m_Canvas->InputMouseMoved( m_MouseX, m_MouseY, dx, dy );
							}

						case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
						case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
							{
								return m_Canvas->InputMouseButton( event.mouse.button - 1,
																   event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN );
							}

						case ALLEGRO_EVENT_KEY_CHAR:
							{
								return m_Canvas->InputCharacter( event.keyboard.unichar );
							}

						case ALLEGRO_EVENT_KEY_DOWN:
						case ALLEGRO_EVENT_KEY_UP:
							{
								bool bPressed = ( event.type == ALLEGRO_EVENT_KEY_DOWN );

								if ( event.keyboard.keycode
										&& bPressed
										&& event.keyboard.keycode >= 'a'
										&& event.keyboard.keycode <= 'z' )
								{
									return m_Canvas->InputCharacter( event.keyboard.keycode );
								}

								unsigned char iKey = TranslateKeyCode( event.keyboard.keycode );
								return m_Canvas->InputKey( iKey, bPressed );
							}
					}

					return false;
				}

			protected:

				gwen::Controls::Canvas*	m_Canvas;
				int m_MouseX;
				int m_MouseY;

		};
	}
}
#endif
