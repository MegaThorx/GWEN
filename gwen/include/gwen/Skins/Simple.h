#pragma once
#ifndef GWEN_SKINS_SIMPLE_H
#define GWEN_SKINS_SIMPLE_H

#include "gwen/Skin.h"
#include "gwen/Gwen.h"
#include "gwen/Controls/Base.h"

namespace gwen
{
	namespace Skin
	{
		class Simple : public gwen::Skin::Base
		{
			public:

				Simple( gwen::Renderer::Base* renderer ) : gwen::Skin::Base( renderer )
				{
				}

				gwen::Color m_colBorderColor;
				gwen::Color m_colControlOutlineLight;
				gwen::Color m_colControlOutlineLighter;
				gwen::Color m_colBG;
				gwen::Color m_colBGDark;
				gwen::Color m_colControl;
				gwen::Color m_colControlBorderHighlight;
				gwen::Color m_colControlDarker;
				gwen::Color m_colControlOutlineNormal;
				gwen::Color m_colControlBright;
				gwen::Color m_colControlDark;
				gwen::Color m_colHighlightBG;
				gwen::Color m_colHighlightBorder;
				gwen::Color m_colToolTipBackground;
				gwen::Color m_colToolTipBorder;
				gwen::Color m_colModal;

				Simple()
				{
					m_colBorderColor			= gwen::Color( 80, 80, 80, 255 );
					m_colBG						= gwen::Color( 248, 248, 248, 255 );
					m_colBGDark					= gwen::Color( 235, 235, 235, 255 );
					m_colControl				= gwen::Color( 240, 240, 240, 255 );
					m_colControlBright			= gwen::Color( 255, 255, 255, 255 );
					m_colControlDark			= gwen::Color( 214, 214, 214, 255 );
					m_colControlDarker			= gwen::Color( 180, 180, 180, 255 );
					m_colControlOutlineNormal	= gwen::Color( 112, 112, 112, 255 );
					m_colControlOutlineLight	= gwen::Color( 144, 144, 144, 255 );
					m_colControlOutlineLighter	= gwen::Color( 210, 210, 210, 255 );
					m_colHighlightBG			= gwen::Color( 192, 221, 252, 255 );
					m_colHighlightBorder		= gwen::Color( 51, 153, 255, 255 );
					m_colToolTipBackground		= gwen::Color( 255, 255, 225, 255 );
					m_colToolTipBorder			= gwen::Color( 0, 0, 0, 255 );
					m_colModal = gwen::Color( 25, 25, 25, 150 );
					m_DefaultFont.facename	= L"Microsoft Sans Serif";
					m_DefaultFont.size		= 11;
				}

				virtual void DrawGenericPanel( Controls::Base* control )
				{
					// TODO.
				}

				virtual void DrawButton( gwen::Controls::Base* control, bool bDepressed, bool bHovered, bool bDisabled )
				{
					int w = control->Width();
					int h = control->Height();
					DrawButton( w, h, bDepressed, bHovered );
				}

				virtual void DrawWindowCloseButton( gwen::Controls::Base* control, bool bDepressed, bool bHovered, bool bDisabled )
				{
					// TODO.
					DrawButton( control, bDepressed, bHovered, bDisabled );
				}

				virtual void DrawWindowMaximizeButton( gwen::Controls::Base* control, bool bDepressed, bool bHovered, bool bDisabled, bool bMaximized )
				{
					// TODO.
					DrawButton( control, bDepressed, bHovered, bDisabled );
				}

				virtual void DrawWindowMinimizeButton( gwen::Controls::Base* control, bool bDepressed, bool bHovered, bool bDisabled )
				{
					// TODO.
					DrawButton( control, bDepressed, bHovered, bDisabled );
				}

				virtual void DrawMenuItem( gwen::Controls::Base* control, bool bSubmenuOpen, bool bChecked )
				{
					if ( bSubmenuOpen || control->IsHovered() )
					{
						m_Render->SetDrawColor( m_colHighlightBG );
						m_Render->DrawFilledRect( control->GetRenderBounds() );
						m_Render->SetDrawColor( m_colHighlightBorder );
						m_Render->DrawLinedRect( control->GetRenderBounds() );
					}

					if ( bChecked )
					{
						m_Render->SetDrawColor( Color( 0, 0, 0, 255 ) );
						gwen::Rect r( control->Width() / 2 - 2, control->Height() / 2 - 2, 5, 5 );
						DrawCheck( r );
					}
				}

				virtual void DrawMenuStrip( gwen::Controls::Base* control )
				{
					int w = control->Width();
					int h = control->Height();
					m_Render->SetDrawColor( gwen::Color( 246, 248, 252, 255 ) );
					m_Render->DrawFilledRect( gwen::Rect( 0, 0, w, h ) );
					m_Render->SetDrawColor( gwen::Color( 218, 224, 241, 150 ) );
					m_Render->DrawFilledRect( gwen::Rect( 0, h * 0.4f, w, h * 0.6f ) );
					m_Render->DrawFilledRect( gwen::Rect( 0, h * 0.5f, w, h * 0.5f ) );
				}

				virtual void DrawMenu( gwen::Controls::Base* control, bool bPaddingDisabled )
				{
					int w = control->Width();
					int h = control->Height();
					m_Render->SetDrawColor( m_colControlBright );
					m_Render->DrawFilledRect( gwen::Rect( 0, 0, w, h ) );

					if ( !bPaddingDisabled )
					{
						m_Render->SetDrawColor( m_colControl );
						m_Render->DrawFilledRect( gwen::Rect( 1, 0, 22, h ) );
					}

					m_Render->SetDrawColor( m_colControlOutlineNormal );
					m_Render->DrawLinedRect( gwen::Rect( 0, 0, w, h ) );
				}

				virtual void DrawShadow( gwen::Controls::Base* control )
				{
					int w = control->Width();
					int h = control->Height();
					int x = 4;
					int y = 6;
					m_Render->SetDrawColor( gwen::Color( 0, 0, 0, 10 ) );
					m_Render->DrawFilledRect( gwen::Rect( x, y, w, h ) );
					x += 2;
					m_Render->DrawFilledRect( gwen::Rect( x, y, w, h ) );
					y += 2;
					m_Render->DrawFilledRect( gwen::Rect( x, y, w, h ) );
				}

				virtual void DrawButton( int w, int h, bool bDepressed, bool bHovered, bool bSquared = false )
				{
					if ( bDepressed )	{ m_Render->SetDrawColor( m_colControlDark ); }
					else if ( bHovered ) { m_Render->SetDrawColor( m_colControlBright ); }
					else				{ m_Render->SetDrawColor( m_colControl ); }

					m_Render->DrawFilledRect( gwen::Rect( 1, 1, w - 2, h - 2 ) );

					if ( bDepressed )	{ m_Render->SetDrawColor( m_colControlDark ); }
					else if ( bHovered ) { m_Render->SetDrawColor( m_colControl ); }
					else				{ m_Render->SetDrawColor( m_colControlDark ); }

					m_Render->DrawFilledRect( gwen::Rect( 1, h * 0.5, w - 2, h * 0.5 - 2 ) );

					if ( !bDepressed )
					{
						m_Render->SetDrawColor( m_colControlBright );
						m_Render->DrawShavedCornerRect( gwen::Rect( 1, 1, w - 2, h - 2 ), bSquared );
					}
					else
					{
						m_Render->SetDrawColor( m_colControlDarker );
						m_Render->DrawShavedCornerRect( gwen::Rect( 1, 1, w - 2, h - 2 ), bSquared );
					}

					// Border
					m_Render->SetDrawColor( m_colControlOutlineNormal );
					m_Render->DrawShavedCornerRect( gwen::Rect( 0, 0, w, h ), bSquared );
				}

				virtual void DrawRadioButton( gwen::Controls::Base* control, bool bSelected, bool bDepressed )
				{
					gwen::Rect rect = control->GetRenderBounds();

					// Inside colour
					if ( control->IsHovered() )	{ m_Render->SetDrawColor( gwen::Color( 220, 242, 254, 255 ) ); }
					else { m_Render->SetDrawColor( m_colControlBright ); }

					m_Render->DrawFilledRect( gwen::Rect( 1, 1, rect.w - 2, rect.h - 2 ) );

					// Border
					if ( control->IsHovered() )	{ m_Render->SetDrawColor( gwen::Color( 85, 130, 164, 255 ) ); }
					else { m_Render->SetDrawColor( m_colControlOutlineLight ); }

					m_Render->DrawShavedCornerRect( rect );
					m_Render->SetDrawColor( gwen::Color( 0,  50,  60, 15 ) );
					m_Render->DrawFilledRect( gwen::Rect( rect.x + 2, rect.y + 2, rect.w - 4, rect.h - 4 ) );
					m_Render->DrawFilledRect( gwen::Rect( rect.x + 2, rect.y + 2, rect.w * 0.3f, rect.h - 4 ) );
					m_Render->DrawFilledRect( gwen::Rect( rect.x + 2, rect.y + 2, rect.w - 4, rect.h * 0.3f ) );

					if ( control->IsHovered() )	{ m_Render->SetDrawColor( gwen::Color( 121, 198, 249, 255 ) ); }
					else { m_Render->SetDrawColor( gwen::Color( 0, 50, 60, 50 ) ); }

					m_Render->DrawFilledRect( gwen::Rect( rect.x + 2, rect.y + 3, 1, rect.h - 5 ) );
					m_Render->DrawFilledRect( gwen::Rect( rect.x + 3, rect.y + 2, rect.w - 5, 1 ) );

					if ( bSelected )
					{
						m_Render->SetDrawColor( gwen::Color( 40, 230, 30, 255 ) );
						m_Render->DrawFilledRect( gwen::Rect( rect.x + 2, rect.y + 2, rect.w - 4, rect.h - 4 ) );
					}
				}


				virtual void DrawCheckBox( gwen::Controls::Base* control, bool bSelected, bool bDepressed )
				{
					gwen::Rect rect = control->GetRenderBounds();

					// Inside colour
					if ( control->IsHovered() )	{ m_Render->SetDrawColor( gwen::Color( 220, 242, 254, 255 ) ); }
					else { m_Render->SetDrawColor( m_colControlBright ); }

					m_Render->DrawFilledRect( rect );

					// Border
					if ( control->IsHovered() )	{ m_Render->SetDrawColor( gwen::Color( 85, 130, 164, 255 ) ); }
					else { m_Render->SetDrawColor( m_colControlOutlineLight ); }

					m_Render->DrawLinedRect( rect );
					m_Render->SetDrawColor( gwen::Color( 0,  50,  60, 15 ) );
					m_Render->DrawFilledRect( gwen::Rect( rect.x + 2, rect.y + 2, rect.w - 4, rect.h - 4 ) );
					m_Render->DrawFilledRect( gwen::Rect( rect.x + 2, rect.y + 2, rect.w * 0.3f, rect.h - 4 ) );
					m_Render->DrawFilledRect( gwen::Rect( rect.x + 2, rect.y + 2, rect.w - 4, rect.h * 0.3f ) );

					if ( control->IsHovered() )	{ m_Render->SetDrawColor( gwen::Color( 121, 198, 249, 255 ) ); }
					else { m_Render->SetDrawColor( gwen::Color( 0, 50, 60, 50 ) ); }

					m_Render->DrawFilledRect( gwen::Rect( rect.x + 2, rect.y + 2, 1, rect.h - 4 ) );
					m_Render->DrawFilledRect( gwen::Rect( rect.x + 2, rect.y + 2, rect.w - 4, 1 ) );

					if ( bDepressed )
					{
						m_Render->SetDrawColor( Color( 100, 100, 100, 255 ) );
						gwen::Rect r( control->Width() / 2 - 2, control->Height() / 2 - 2, 5, 5 );
						DrawCheck( r );
					}
					else if ( bSelected )
					{
						m_Render->SetDrawColor( Color( 0, 0, 0, 255 ) );
						gwen::Rect r( control->Width() / 2 - 2, control->Height() / 2 - 2, 5, 5 );
						DrawCheck( r );
					}
				}

				virtual void DrawGroupBox( gwen::Controls::Base* control, int textStart, int textHeight, int textWidth )
				{
					gwen::Rect rect = control->GetRenderBounds();
					rect.y += textHeight * 0.5f;
					rect.h -= textHeight * 0.5f;
					gwen::Color m_colDarker			= gwen::Color( 0,  50,  60, 50 );
					gwen::Color m_colLighter		= gwen::Color( 255, 255, 255, 150 );
					m_Render->SetDrawColor( m_colLighter );
					m_Render->DrawFilledRect( gwen::Rect( rect.x + 1, rect.y + 1, textStart - 3, 1 ) );
					m_Render->DrawFilledRect( gwen::Rect( rect.x + 1 + textStart + textWidth, rect.y + 1, rect.w - textStart + textWidth - 2, 1 ) );
					m_Render->DrawFilledRect( gwen::Rect( rect.x + 1, ( rect.y + rect.h ) - 1, rect.w - 2, 1 ) );
					m_Render->DrawFilledRect( gwen::Rect( rect.x + 1, rect.y + 1, 1, rect.h ) );
					m_Render->DrawFilledRect( gwen::Rect( ( rect.x + rect.w ) - 2, rect.y + 1, 1, rect.h - 1 ) );
					m_Render->SetDrawColor( m_colDarker );
					m_Render->DrawFilledRect( gwen::Rect( rect.x + 1, rect.y, textStart - 3, 1 ) );
					m_Render->DrawFilledRect( gwen::Rect( rect.x + 1 + textStart + textWidth, rect.y, rect.w - textStart - textWidth - 2, 1 ) );
					m_Render->DrawFilledRect( gwen::Rect( rect.x + 1, ( rect.y + rect.h ) - 1, rect.w - 2, 1 ) );
					m_Render->DrawFilledRect( gwen::Rect( rect.x, rect.y + 1, 1, rect.h - 1 ) );
					m_Render->DrawFilledRect( gwen::Rect( ( rect.x + rect.w ) - 1, rect.y + 1, 1, rect.h - 1 ) );
				}

				virtual void DrawTextBox( gwen::Controls::Base* control )
				{
					gwen::Rect rect = control->GetRenderBounds();
					bool bHasFocus = control->HasFocus();
					// Box inside
					m_Render->SetDrawColor( gwen::Color( 255, 255, 255, 255 ) );
					m_Render->DrawFilledRect( gwen::Rect( 1, 1, rect.w - 2, rect.h - 2 ) );
					m_Render->SetDrawColor( m_colControlOutlineLight );
					m_Render->DrawFilledRect( gwen::Rect( rect.x + 1, rect.y, rect.w - 2, 1 ) );
					m_Render->DrawFilledRect( gwen::Rect( rect.x, rect.y + 1, 1, rect.h - 2 ) );
					m_Render->SetDrawColor( m_colControlOutlineLighter );
					m_Render->DrawFilledRect( gwen::Rect( rect.x + 1, ( rect.y + rect.h ) - 1, rect.w - 2, 1 ) );
					m_Render->DrawFilledRect( gwen::Rect( ( rect.x + rect.w ) - 1, rect.y + 1, 1, rect.h - 2 ) );

					if ( bHasFocus )
					{
						m_Render->SetDrawColor( gwen::Color( 50, 200, 255, 150 ) );
						m_Render->DrawLinedRect( rect );
					}
				}

				virtual void DrawTabButton( gwen::Controls::Base* control, bool bActive, int dir )
				{
					gwen::Rect rect = control->GetRenderBounds();
					bool bHovered = control->IsHovered();

					if ( bHovered ) { m_Render->SetDrawColor( m_colControlBright ); }
					else		   { m_Render->SetDrawColor( m_colControl ); }

					m_Render->DrawFilledRect( gwen::Rect( 1, 1, rect.w - 2, rect.h - 1 ) );

					if ( bHovered ) { m_Render->SetDrawColor( m_colControl ); }
					else		   { m_Render->SetDrawColor( m_colControlDark ); }

					m_Render->DrawFilledRect( gwen::Rect( 1, rect.h * 0.5, rect.w - 2, rect.h * 0.5 - 1 ) );
					m_Render->SetDrawColor( m_colControlBright );
					m_Render->DrawShavedCornerRect( gwen::Rect( 1, 1, rect.w - 2, rect.h ) );
					m_Render->SetDrawColor( m_colBorderColor );
					m_Render->DrawShavedCornerRect( gwen::Rect( 0, 0, rect.w, rect.h ) );
				}

				virtual void DrawTabControl( gwen::Controls::Base* control )
				{
					gwen::Rect rect = control->GetRenderBounds();
					m_Render->SetDrawColor( m_colControl );
					m_Render->DrawFilledRect( rect );
					m_Render->SetDrawColor( m_colBorderColor );
					m_Render->DrawLinedRect( rect );
					//m_Render->SetDrawColor( m_colControl );
					//m_Render->DrawFilledRect( CurrentButtonRect );
				}

				virtual void DrawWindow( gwen::Controls::Base* control, int topHeight, bool inFocus )
				{
					gwen::Rect rect = control->GetRenderBounds();

					// Titlebar
					if ( inFocus )
					{ m_Render->SetDrawColor( gwen::Color( 87, 164, 232, 230 ) ); }
					else
					{ m_Render->SetDrawColor( gwen::Color( 87 * 0.70, 164 * 0.70, 232 * 0.70, 230 ) ); }

					int iBorderSize = 5;
					m_Render->DrawFilledRect( gwen::Rect( rect.x + 1, rect.y + 1, rect.w - 2, topHeight - 1 ) );
					m_Render->DrawFilledRect( gwen::Rect( rect.x + 1, rect.y + topHeight - 1, iBorderSize, rect.h - 2 - topHeight ) );
					m_Render->DrawFilledRect( gwen::Rect( rect.x + rect.w - iBorderSize, rect.y + topHeight - 1, iBorderSize, rect.h - 2 - topHeight ) );
					m_Render->DrawFilledRect( gwen::Rect( rect.x + 1, rect.y + rect.h - iBorderSize, rect.w - 2, iBorderSize ) );
					// Main inner
					m_Render->SetDrawColor( gwen::Color( m_colControlDark.r, m_colControlDark.g, m_colControlDark.b, 230 ) );
					m_Render->DrawFilledRect( gwen::Rect( rect.x + iBorderSize + 1, rect.y + topHeight, rect.w - iBorderSize * 2 - 2, rect.h - topHeight - iBorderSize - 1 ) );
					// Light inner border
					m_Render->SetDrawColor( gwen::Color( 255, 255, 255, 100 ) );
					m_Render->DrawShavedCornerRect( gwen::Rect( rect.x + 1, rect.y + 1, rect.w - 2, rect.h - 2 ) );
					// Dark line between titlebar and main
					m_Render->SetDrawColor( m_colBorderColor );
					// Inside border
					m_Render->SetDrawColor( m_colControlOutlineNormal );
					m_Render->DrawLinedRect( gwen::Rect( rect.x + iBorderSize, rect.y + topHeight - 1, rect.w - 10, rect.h - topHeight - ( iBorderSize - 1 ) ) );
					// Dark outer border
					m_Render->SetDrawColor( m_colBorderColor );
					m_Render->DrawShavedCornerRect( gwen::Rect( rect.x, rect.y, rect.w, rect.h ) );
				}

				virtual void DrawHighlight( gwen::Controls::Base* control )
				{
					gwen::Rect rect = control->GetRenderBounds();
					m_Render->SetDrawColor( gwen::Color( 255, 100, 255, 255 ) );
					m_Render->DrawFilledRect( rect );
				}

				virtual void DrawScrollBar( gwen::Controls::Base* control, bool isHorizontal, bool bDepressed )
				{
					gwen::Rect rect = control->GetRenderBounds();

					if ( bDepressed )
					{ m_Render->SetDrawColor( m_colControlDarker ); }
					else
					{ m_Render->SetDrawColor( m_colControlBright ); }

					m_Render->DrawFilledRect( rect );
				}

				virtual void DrawScrollBarBar( Controls::Base* control, bool bDepressed, bool isHovered, bool isHorizontal )
				{
					//TODO: something specialized
					DrawButton( control, bDepressed, isHovered, false );
				}

				virtual void DrawTabTitleBar( gwen::Controls::Base* control )
				{
					gwen::Rect rect = control->GetRenderBounds();
					m_Render->SetDrawColor( gwen::Color( 177, 193, 214, 255 ) );
					m_Render->DrawFilledRect( rect );
					m_Render->SetDrawColor( m_colBorderColor );
					rect.h += 1;
					m_Render->DrawLinedRect( rect );
				}

				virtual void DrawProgressBar( gwen::Controls::Base* control, bool isHorizontal, float progress )
				{
					gwen::Rect rect = control->GetRenderBounds();
					gwen::Color FillColour( 0, 211, 40, 255 );

					if ( isHorizontal )
					{
						//Background
						m_Render->SetDrawColor( m_colControlDark );
						m_Render->DrawFilledRect( gwen::Rect( 1, 1, rect.w - 2, rect.h - 2 ) );
						//Right half
						m_Render->SetDrawColor( FillColour );
						m_Render->DrawFilledRect( gwen::Rect( 1, 1, rect.w * progress - 2, rect.h - 2 ) );
						m_Render->SetDrawColor( gwen::Color( 255, 255, 255, 150 ) );
						m_Render->DrawFilledRect( gwen::Rect( 1, 1, rect.w - 2, rect.h * 0.45f ) );
					}
					else
					{
						//Background
						m_Render->SetDrawColor( m_colControlDark );
						m_Render->DrawFilledRect( gwen::Rect( 1, 1, rect.w - 2, rect.h - 2 ) );
						//Top half
						m_Render->SetDrawColor( FillColour );
						m_Render->DrawFilledRect( gwen::Rect( 1, 1 + ( rect.h * ( 1 - progress ) ), rect.w - 2, rect.h * progress - 2 ) );
						m_Render->SetDrawColor( gwen::Color( 255, 255, 255, 150 ) );
						m_Render->DrawFilledRect( gwen::Rect( 1, 1, rect.w * 0.45f, rect.h - 2 ) );
					}

					m_Render->SetDrawColor( gwen::Color( 255, 255, 255, 150 ) );
					m_Render->DrawShavedCornerRect( gwen::Rect( 1, 1, rect.w - 2, rect.h - 2 ) );
					m_Render->SetDrawColor( gwen::Color( 255, 255, 255, 70 ) );
					m_Render->DrawShavedCornerRect( gwen::Rect( 2, 2, rect.w - 4, rect.h - 4 ) );
					m_Render->SetDrawColor( m_colBorderColor );
					m_Render->DrawShavedCornerRect( rect );
				}

				virtual void DrawListBox( gwen::Controls::Base* control )
				{
					gwen::Rect rect = control->GetRenderBounds();
					m_Render->SetDrawColor( m_colControlBright );
					m_Render->DrawFilledRect( rect );
					m_Render->SetDrawColor( m_colBorderColor );
					m_Render->DrawLinedRect( rect );
				}

				virtual void DrawListBoxLine( gwen::Controls::Base* control, bool bSelected, bool bEven )
				{
					gwen::Rect rect = control->GetRenderBounds();

					if ( bSelected )
					{
						m_Render->SetDrawColor( m_colHighlightBorder );
						m_Render->DrawFilledRect( rect );
					}
					else if ( control->IsHovered() )
					{
						m_Render->SetDrawColor( m_colHighlightBG );
						m_Render->DrawFilledRect( rect );
					}
				}


				virtual void DrawSlider( gwen::Controls::Base* control, bool bIsHorizontal, int numNotches, int barSize )
				{
					gwen::Rect rect = control->GetRenderBounds();

					if ( bIsHorizontal )
					{
						rect.y += rect.h * 0.4;
						rect.h -= rect.h * 0.8;
					}
					else
					{
						rect.x += rect.w * 0.4;
						rect.w -= rect.w * 0.8;
					}

					m_Render->SetDrawColor( m_colBGDark );
					m_Render->DrawFilledRect( rect );
					m_Render->SetDrawColor( m_colControlDarker );
					m_Render->DrawLinedRect( rect );
				}

				virtual void DrawComboBox( gwen::Controls::Base* control, bool bIsDown, bool bIsMenuOpen )
				{
					DrawTextBox( control );
				}

				virtual void DrawKeyboardHighlight( gwen::Controls::Base* control, const gwen::Rect & r, int iOffset )
				{
					gwen::Rect rect = r;
					rect.x += iOffset;
					rect.y += iOffset;
					rect.w -= iOffset * 2;
					rect.h -= iOffset * 2;
					//draw the top and bottom
					bool skip = true;

					for ( int i = 0; i < rect.w * 0.5; i++ )
					{
						m_Render->SetDrawColor( gwen::Color( 0, 0, 0, 255 ) );

						if ( !skip )
						{
							m_Render->DrawPixel( rect.x + ( i * 2 ), rect.y );
							m_Render->DrawPixel( rect.x + ( i * 2 ), rect.y + rect.h - 1 );
						}
						else
						{ skip = !skip; }
					}

					skip = false;

					for ( int i = 0; i < rect.h * 0.5; i++ )
					{
						m_Render->SetDrawColor( gwen::Color( 0, 0, 0, 255 ) );

						if ( !skip )
						{
							m_Render->DrawPixel( rect.x , rect.y + i * 2 );
							m_Render->DrawPixel( rect.x + rect.w - 1, rect.y + i * 2 );
						}
						else
						{ skip = !skip; }
					}
				}

				virtual void DrawToolTip( gwen::Controls::Base* control )
				{
					gwen::Rect rct = control->GetRenderBounds();
					rct.x -= 3;
					rct.y -= 3;
					rct.w += 6;
					rct.h += 6;
					m_Render->SetDrawColor( m_colToolTipBackground );
					m_Render->DrawFilledRect( rct );
					m_Render->SetDrawColor( m_colToolTipBorder );
					m_Render->DrawLinedRect( rct );
				}

				virtual void DrawScrollButton( gwen::Controls::Base* control, int iDirection, bool bDepressed, bool bHovered, bool bDisabled )
				{
					DrawButton( control, bDepressed, false, false );
					m_Render->SetDrawColor( gwen::Color( 0, 0, 0, 240 ) );
					gwen::Rect r( control->Width() / 2 - 2, control->Height() / 2 - 2, 5, 5 );

					if ( iDirection == gwen::Pos::Top ) { DrawArrowUp( r ); }
					else if ( iDirection == gwen::Pos::Bottom ) { DrawArrowDown( r ); }
					else if ( iDirection == gwen::Pos::Left ) { DrawArrowLeft( r ); }
					else { DrawArrowRight( r ); }
				}

				virtual void DrawComboDownArrow( gwen::Controls::Base* control, bool bHovered, bool bDown, bool bOpen, bool bDisabled )
				{
					//DrawButton( control->Width(), control->Height(), bDepressed, false, true );
					m_Render->SetDrawColor( gwen::Color( 0, 0, 0, 240 ) );
					gwen::Rect r( control->Width() / 2 - 2, control->Height() / 2 - 2, 5, 5 );
					DrawArrowDown( r );
				}

				virtual void DrawNumericUpDownButton( gwen::Controls::Base* control, bool bDepressed, bool bUp )
				{
					//DrawButton( control->Width(), control->Height(), bDepressed, false, true );
					m_Render->SetDrawColor( gwen::Color( 0, 0, 0, 240 ) );
					gwen::Rect r( control->Width() / 2 - 2, control->Height() / 2 - 2, 5, 5 );

					if ( bUp ) { DrawArrowUp( r ); }
					else { DrawArrowDown( r ); }
				}

				virtual void DrawTreeButton( Controls::Base* control, bool bOpen )
				{
					gwen::Rect rect = control->GetRenderBounds();
					rect.x += 2;
					rect.y += 2;
					rect.w -= 4;
					rect.h -= 4;
					m_Render->SetDrawColor( m_colControlBright );
					m_Render->DrawFilledRect( rect );
					m_Render->SetDrawColor( m_colBorderColor );
					m_Render->DrawLinedRect( rect );
					m_Render->SetDrawColor( m_colBorderColor );

					if ( !bOpen ) // ! because the button shows intention, not the current state
					{ m_Render->DrawFilledRect( gwen::Rect( rect.x + rect.w / 2,	rect.y + 2,				1,			rect.h - 4 ) ); }

					m_Render->DrawFilledRect( gwen::Rect( rect.x + 2,			rect.y + rect.h / 2,		rect.w - 4,	1 ) );
				}

				virtual void DrawTreeControl( Controls::Base* control )
				{
					gwen::Rect rect = control->GetRenderBounds();
					m_Render->SetDrawColor( m_colControlBright );
					m_Render->DrawFilledRect( rect );
					m_Render->SetDrawColor( m_colBorderColor );
					m_Render->DrawLinedRect( rect );
				}

				void DrawTreeNode( Controls::Base* ctrl, bool bOpen, bool bSelected, int iLabelHeight, int iLabelWidth, int iHalfWay, int iLastBranch, bool bIsRoot )
				{
					if ( bSelected )
					{
						GetRender()->SetDrawColor( Color( 0, 150, 255, 100 ) );
						GetRender()->DrawFilledRect( gwen::Rect( 17, 0, iLabelWidth + 2, iLabelHeight - 1 ) );
						GetRender()->SetDrawColor( Color( 0, 150, 255, 200 ) );
						GetRender()->DrawLinedRect( gwen::Rect( 17, 0, iLabelWidth + 2, iLabelHeight - 1 ) );
					}

					Base::DrawTreeNode( ctrl, bOpen, bSelected, iLabelHeight, iLabelWidth, iHalfWay, iLastBranch, bIsRoot );
				}

				virtual void DrawStatusBar( Controls::Base* control )
				{
					// TODO.
				}

				void DrawColorDisplay( Controls::Base* control, gwen::Color color )
				{
					gwen::Rect rect = control->GetRenderBounds();

					if ( color.a != 255 )
					{
						GetRender()->SetDrawColor( gwen::Color( 255, 255, 255, 255 ) );
						GetRender()->DrawFilledRect( rect );
						GetRender()->SetDrawColor( gwen::Color( 128, 128, 128, 128 ) );
						GetRender()->DrawFilledRect( gwen::Rect( 0, 0, rect.w * 0.5, rect.h * 0.5 ) );
						GetRender()->DrawFilledRect( gwen::Rect( rect.w * 0.5, rect.h * 0.5, rect.w * 0.5, rect.h * 0.5 ) );
					}

					GetRender()->SetDrawColor( color );
					GetRender()->DrawFilledRect( rect );
					GetRender()->SetDrawColor( gwen::Color( 0, 0, 0, 255 ) );
					GetRender()->DrawLinedRect( rect );
				}

				virtual void DrawModalControl( Controls::Base* control )
				{
					if ( control->ShouldDrawBackground() )
					{
						gwen::Rect rect = control->GetRenderBounds();
						GetRender()->SetDrawColor( m_colModal );
						GetRender()->DrawFilledRect( rect );
					}
				}

				virtual void DrawMenuDivider( Controls::Base* control )
				{
					gwen::Rect rect = control->GetRenderBounds();
					GetRender()->SetDrawColor( m_colBGDark );
					GetRender()->DrawFilledRect( rect );
					GetRender()->SetDrawColor( m_colControlDarker );
					GetRender()->DrawLinedRect( rect );
				}

				virtual void DrawMenuRightArrow( Controls::Base* control )
				{
					DrawArrowRight( control->GetRenderBounds() );
				}

				virtual void DrawSlideButton( gwen::Controls::Base* control, bool bDepressed, bool bHorizontal )
				{
					DrawButton( control, bDepressed, control->IsHovered(), control->IsDisabled() );
				}

				virtual void DrawCategoryHolder( Controls::Base* ctrl ) {}
				virtual void DrawCategoryInner( Controls::Base* ctrl, bool bCollapsed ) {}
		};
	}
}
#endif
