/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#ifndef GWEN_SKIN_H
#define GWEN_SKIN_H

#include "gwen/BaseRender.h"
#include "gwen/Font.h"

namespace gwen
{
	namespace Controls
	{
		class Base;
	}

	namespace Skin
	{
		namespace Symbol
		{
			static const unsigned char None				= 0;
			static const unsigned char ArrowRight		= 1;
			static const unsigned char Check			= 2;
			static const unsigned char Dot				= 3;
		}

		class GWEN_EXPORT Base
		{
			public:

				Base( gwen::Renderer::Base* renderer = NULL )
				{
					m_DefaultFont.facename = L"Arial";
					m_DefaultFont.size = 10.0f;
					m_Render = renderer;
				}

				virtual ~Base()
				{
					ReleaseFont( &m_DefaultFont );
				}

				virtual void ReleaseFont( gwen::Font* fnt )
				{
					if ( !fnt ) { return; }

					if ( !m_Render ) { return; }

					m_Render->FreeFont( fnt );
				}

				virtual void DrawGenericPanel( Controls::Base* control ) = 0;

				virtual void DrawButton( Controls::Base* control, bool bDepressed, bool bHovered, bool bDisabled ) = 0;
				virtual void DrawTabButton( Controls::Base* control, bool bActive, int dir ) = 0;
				virtual void DrawTabControl( Controls::Base* control ) = 0;
				virtual void DrawTabTitleBar( Controls::Base* control ) = 0;


				virtual void DrawMenuItem( Controls::Base* control, bool bSubmenuOpen, bool bChecked ) = 0;
				virtual void DrawMenuStrip( Controls::Base* control ) = 0;
				virtual void DrawMenu( Controls::Base* control, bool bPaddingDisabled ) = 0;
				virtual void DrawMenuRightArrow( Controls::Base* control ) = 0;

				virtual void DrawRadioButton( Controls::Base* control, bool bSelected, bool bDepressed ) = 0;
				virtual void DrawCheckBox( Controls::Base* control, bool bSelected, bool bDepressed ) = 0;
				virtual void DrawGroupBox( Controls::Base* control, int textStart, int textHeight, int textWidth ) = 0;
				virtual void DrawTextBox( Controls::Base* control ) = 0;

				virtual void DrawWindow( Controls::Base* control, int topHeight, bool inFocus ) = 0;
				virtual void DrawWindowCloseButton( gwen::Controls::Base* control, bool bDepressed, bool bHovered, bool bDisabled ) = 0;
				virtual void DrawWindowMaximizeButton( gwen::Controls::Base* control, bool bDepressed, bool bHovered, bool bDisabled, bool bMaximized ) = 0;
				virtual void DrawWindowMinimizeButton( gwen::Controls::Base* control, bool bDepressed, bool bHovered, bool bDisabled ) = 0;


				virtual void DrawHighlight( Controls::Base* control ) = 0;
				virtual void DrawStatusBar( Controls::Base* control ) = 0;

				virtual void DrawShadow( Controls::Base* control ) = 0;
				virtual void DrawScrollBarBar( Controls::Base* control, bool bDepressed, bool isHovered, bool isHorizontal ) = 0;
				virtual void DrawScrollBar( Controls::Base* control, bool isHorizontal, bool bDepressed ) = 0;
				virtual void DrawScrollButton( Controls::Base* control, int iDirection, bool bDepressed, bool bHovered, bool bDisabled ) = 0;
				virtual void DrawProgressBar( Controls::Base* control, bool isHorizontal, float progress ) = 0;

				virtual void DrawListBox( Controls::Base* control ) = 0;
				virtual void DrawListBoxLine( Controls::Base* control, bool bSelected, bool bEven ) = 0;

				virtual void DrawSlider( Controls::Base* control, bool bIsHorizontal, int numNotches, int barSize ) = 0;
				virtual void DrawSlideButton( gwen::Controls::Base* control, bool bDepressed, bool bHorizontal ) = 0;

				virtual void DrawComboBox( Controls::Base* control, bool bIsDown, bool bIsMenuOpen ) = 0;
				virtual void DrawComboDownArrow( gwen::Controls::Base* control, bool bHovered, bool bDown, bool bOpen, bool bDisabled ) = 0;
				virtual void DrawKeyboardHighlight( Controls::Base* control, const gwen::Rect & rect, int offset ) = 0;
				virtual void DrawToolTip( Controls::Base* control ) = 0;

				virtual void DrawNumericUpDownButton( Controls::Base* control, bool bDepressed, bool bUp ) = 0;

				virtual void DrawTreeButton( Controls::Base* control, bool bOpen ) = 0;
				virtual void DrawTreeControl( Controls::Base* control ) = 0;
				virtual void DrawTreeNode( Controls::Base* ctrl, bool bOpen, bool bSelected, int iLabelHeight, int iLabelWidth, int iHalfWay, int iLastBranch, bool bIsRoot );

				virtual void DrawPropertyRow( Controls::Base* control, int iWidth, bool bBeingEdited, bool bHovered );
				virtual void DrawPropertyTreeNode( Controls::Base* control, int BorderLeft, int BorderTop );
				virtual void DrawColorDisplay( Controls::Base* control, gwen::Color color ) = 0;
				virtual void DrawModalControl( Controls::Base* control ) = 0;
				virtual void DrawMenuDivider( Controls::Base* control ) = 0;

				virtual void DrawCategoryHolder( Controls::Base* ctrl ) = 0;
				virtual void DrawCategoryInner( Controls::Base* ctrl, bool bCollapsed ) = 0;


				virtual void SetRender( gwen::Renderer::Base* renderer )
				{
					m_Render = renderer;
				}
				virtual gwen::Renderer::Base* GetRender()
				{
					return m_Render;
				}

				virtual void DrawArrowDown( gwen::Rect rect );
				virtual void DrawArrowUp( gwen::Rect rect );
				virtual void DrawArrowLeft( gwen::Rect rect );
				virtual void DrawArrowRight( gwen::Rect rect );
				virtual void DrawCheck( gwen::Rect rect );


				struct
				{
					struct Window_t
					{
						gwen::Color TitleActive;
						gwen::Color TitleInactive;

					} Window;

					struct Label_t
					{
						gwen::Color Default;
						gwen::Color Bright;
						gwen::Color Dark;
						gwen::Color Highlight;

					} Label;

					struct Tree_t
					{
						gwen::Color Lines;
						gwen::Color Normal;
						gwen::Color Hover;
						gwen::Color Selected;

					} Tree;

					struct Properties_t
					{
						gwen::Color Line_Normal;
						gwen::Color Line_Selected;
						gwen::Color Line_Hover;
						gwen::Color Column_Normal;
						gwen::Color Column_Selected;
						gwen::Color Column_Hover;
						gwen::Color Label_Normal;
						gwen::Color Label_Selected;
						gwen::Color Label_Hover;
						gwen::Color Border;
						gwen::Color Title;

					} Properties;

					struct Button_t
					{
						gwen::Color Normal;
						gwen::Color Hover;
						gwen::Color Down;
						gwen::Color Disabled;

					} Button;

					struct Tab_t
					{
						struct Active_t
						{
							gwen::Color Normal;
							gwen::Color Hover;
							gwen::Color Down;
							gwen::Color Disabled;
						} Active;

						struct Inactive_t
						{
							gwen::Color Normal;
							gwen::Color Hover;
							gwen::Color Down;
							gwen::Color Disabled;
						} Inactive;

					} Tab;

					struct Category_t
					{
						gwen::Color Header;
						gwen::Color Header_Closed;

						struct Line_t
						{
							gwen::Color Text;
							gwen::Color Text_Hover;
							gwen::Color Text_Selected;
							gwen::Color Button;
							gwen::Color Button_Hover;
							gwen::Color Button_Selected;
						} Line;

						struct LineAlt_t
						{
							gwen::Color Text;
							gwen::Color Text_Hover;
							gwen::Color Text_Selected;
							gwen::Color Button;
							gwen::Color Button_Hover;
							gwen::Color Button_Selected;
						} LineAlt;

					} Category;

					gwen::Color ModalBackground;
					gwen::Color TooltipText;

				} Colors;


			public:

				virtual gwen::Font* GetDefaultFont()
				{
					return &m_DefaultFont;
				}

				virtual void SetDefaultFont( const gwen::UnicodeString & strFacename, float fSize = 10.0f )
				{
					m_DefaultFont.facename = strFacename;
					m_DefaultFont.size = fSize;
				}

			protected:

				gwen::Font m_DefaultFont;
				gwen::Renderer::Base* m_Render;

		};
	};
}
#endif
