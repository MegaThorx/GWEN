/*
	GWEN
	Copyright (c) 2011 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#ifndef GWEN_INPUT_SFML_H
#define GWEN_INPUT_SFML_H

#include "gwen/InputHandler.h"
#include "gwen/Gwen.h"
#include "gwen/Controls/Canvas.h"

#include <SFML/Window/Event.hpp>

namespace gwen
{
	namespace Input
	{
		class SFML
		{
			public:

				SFML()
				{
					m_Canvas = NULL;
					m_MouseX = 0;
					m_MouseY = 0;
                    m_LeftMouseDown = false;
                    m_RightMouseDown = false;
                    m_MiddleMouseDown = false;
                    m_XButton1MouseDown = false;
                    m_XButton2MouseDown = false;
				}

				void Initialize( gwen::Controls::Canvas* c )
				{
					m_Canvas = c;
				}

				unsigned char TranslateKeyCode( int iKeyCode )
				{
					switch ( iKeyCode )
					{
#if SFML_VERSION_MAJOR == 2

						case sf::Keyboard::BackSpace:
							return gwen::Key::Backspace;

						case sf::Keyboard::Return:
							return gwen::Key::Return;

						case sf::Keyboard::Escape:
							return gwen::Key::Escape;

						case sf::Keyboard::Tab:
							return gwen::Key::Tab;

						case sf::Keyboard::Space:
							return gwen::Key::Space;

						case sf::Keyboard::Up:
							return gwen::Key::Up;

						case sf::Keyboard::Down:
							return gwen::Key::Down;

						case sf::Keyboard::Left:
							return gwen::Key::Left;

						case sf::Keyboard::Right:
							return gwen::Key::Right;

						case sf::Keyboard::Home:
							return gwen::Key::Home;

						case sf::Keyboard::End:
							return gwen::Key::End;

						case sf::Keyboard::Delete:
							return gwen::Key::Delete;

						case sf::Keyboard::LControl:
							return gwen::Key::Control;

						case sf::Keyboard::LAlt:
							return gwen::Key::Alt;

						case sf::Keyboard::LShift:
							return gwen::Key::Shift;

						case sf::Keyboard::RControl:
							return gwen::Key::Control;

						case sf::Keyboard::RAlt:
							return gwen::Key::Alt;

						case sf::Keyboard::RShift:
							return gwen::Key::Shift;
#else

						case sf::Key::Back:
							return gwen::Key::Backspace;

						case sf::Key::Return:
							return gwen::Key::Return;

						case sf::Key::Escape:
							return gwen::Key::Escape;

						case sf::Key::Tab:
							return gwen::Key::Tab;

						case sf::Key::Space:
							return gwen::Key::Space;

						case sf::Key::Up:
							return gwen::Key::Up;

						case sf::Key::Down:
							return gwen::Key::Down;

						case sf::Key::Left:
							return gwen::Key::Left;

						case sf::Key::Right:
							return gwen::Key::Right;

						case sf::Key::Home:
							return gwen::Key::Home;

						case sf::Key::End:
							return gwen::Key::End;

						case sf::Key::Delete:
							return gwen::Key::Delete;

						case sf::Key::LControl:
							return gwen::Key::Control;

						case sf::Key::LAlt:
							return gwen::Key::Alt;

						case sf::Key::LShift:
							return gwen::Key::Shift;

						case sf::Key::RControl:
							return gwen::Key::Control;

						case sf::Key::RAlt:
							return gwen::Key::Alt;

						case sf::Key::RShift:
							return gwen::Key::Shift;
#endif
					}

					return gwen::Key::Invalid;
				}

				bool ProcessMessage( sf::Event & event )
				{
					if ( !m_Canvas ) { return false; }

#if SFML_VERSION_MAJOR == 2

					switch ( event.type )
#else
					switch ( event.Type )
#endif
					{
						case sf::Event::MouseMoved:
							{
#if SFML_VERSION_MAJOR == 2
								int dx = event.mouseMove.x - m_MouseX;
								int dy = event.mouseMove.y - m_MouseY;
								m_MouseX = event.mouseMove.x;
								m_MouseY = event.mouseMove.y;
#else
								int dx = event.MouseMove.X - m_MouseX;
								int dy = event.MouseMove.Y - m_MouseY;
								m_MouseX = event.MouseMove.X;
								m_MouseY = event.MouseMove.Y;
#endif
								return m_Canvas->InputMouseMoved( m_MouseX, m_MouseY, dx, dy );
							}

                        case sf::Event::MouseButtonPressed:
                            {
#if SFML_VERSION_MAJOR == 2
                                sf::Mouse::Button button = event.mouseButton.button;
#else
                                sf::Mouse::Button button = event.MouseButton.Button;
#endif
                                if      (button == sf::Mouse::Left)     m_LeftMouseDown     = true;
                                else if (button == sf::Mouse::Right)    m_RightMouseDown    = true;
                                else if (button == sf::Mouse::Middle)   m_MiddleMouseDown   = true;
                                else if (button == sf::Mouse::XButton1) m_XButton1MouseDown = true;
                                else if (button == sf::Mouse::XButton2) m_XButton2MouseDown = true;
                                return m_Canvas->InputMouseButton( button, true );
                            }

                        case sf::Event::MouseButtonReleased:
                            {
#if SFML_VERSION_MAJOR == 2
                                sf::Mouse::Button button = event.mouseButton.button;
#else
                                sf::Mouse::Button button = event.MouseButton.Button;
#endif
                                if      (button == sf::Mouse::Left)     m_LeftMouseDown     = false;
                                else if (button == sf::Mouse::Right)    m_RightMouseDown    = false;
                                else if (button == sf::Mouse::Middle)   m_MiddleMouseDown   = false;
                                else if (button == sf::Mouse::XButton1) m_XButton1MouseDown = false;
                                else if (button == sf::Mouse::XButton2) m_XButton2MouseDown = false;
                                return m_Canvas->InputMouseButton( button, false );
                            }

                        case sf::Event::MouseLeft:
                            {
                                if (m_LeftMouseDown)     { m_LeftMouseDown     = false; m_Canvas->InputMouseButton( sf::Mouse::Left,     false ); }
                                if (m_RightMouseDown)    { m_RightMouseDown    = false; m_Canvas->InputMouseButton( sf::Mouse::Right,    false ); }
                                if (m_MiddleMouseDown)   { m_MiddleMouseDown   = false; m_Canvas->InputMouseButton( sf::Mouse::Middle,   false ); }
                                if (m_XButton1MouseDown) { m_XButton1MouseDown = false; m_Canvas->InputMouseButton( sf::Mouse::XButton1, false ); }
                                if (m_XButton2MouseDown) { m_XButton2MouseDown = false; m_Canvas->InputMouseButton( sf::Mouse::XButton2, false ); }
                                break;
                            }

						case sf::Event::MouseWheelMoved:
							{
#if SFML_VERSION_MAJOR == 2
								return m_Canvas->InputMouseWheel( event.mouseWheel.delta * 60 );
#else
								return m_Canvas->InputMouseWheel( event.MouseWheel.Delta * 60 );
#endif
							}

						case sf::Event::TextEntered:
							{
#if SFML_VERSION_MAJOR == 2
								return m_Canvas->InputCharacter( event.text.unicode );
#else
								return m_Canvas->InputCharacter( event.Text.Unicode );
#endif
							}

						case sf::Event::KeyPressed:
						case sf::Event::KeyReleased:
							{
#if SFML_VERSION_MAJOR == 2
								bool bPressed = ( event.type == sf::Event::KeyPressed );
								char keyCode = event.key.code + 97; // adding 97 here turns the sf::Keyboard::Key into a lowercase ASCII character
								bool control = event.key.control;
#else
								bool bPressed = ( event.Type == sf::Event::KeyPressed );
								char keyCode = event.Key.Code;
								bool control = event.Key.Control;
#endif

								if ( control && bPressed && keyCode >= 'a' && keyCode <= 'z' )
								{
									return m_Canvas->InputCharacter( keyCode );
								}

#if SFML_VERSION_MAJOR == 2
								unsigned char iKey = TranslateKeyCode( event.key.code );
#else
								unsigned char iKey = TranslateKeyCode( keyCode );
#endif
								return m_Canvas->InputKey( iKey, bPressed );
							}
                        default:
                            break;
					}

					return false;
				}

			protected:

				gwen::Controls::Canvas*	m_Canvas;
				int m_MouseX;
				int m_MouseY;
                bool m_LeftMouseDown;
                bool m_RightMouseDown;
                bool m_MiddleMouseDown;
                bool m_XButton1MouseDown;
                bool m_XButton2MouseDown;

		};
	}
}
#endif
