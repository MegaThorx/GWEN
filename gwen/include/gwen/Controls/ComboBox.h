/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#ifndef GWEN_CONTROLS_COMBOBOX_H
#define GWEN_CONTROLS_COMBOBOX_H

#include "gwen/Controls/Base.h"
#include "gwen/Controls/Button.h"
#include "gwen/Gwen.h"
#include "gwen/Skin.h"
#include "gwen/Controls/TextBox.h"
#include "gwen/Controls/Menu.h"


namespace gwen
{
	namespace Controls
	{
		class GWEN_EXPORT ComboBox : public Button
		{
			public:

				GWEN_CONTROL( ComboBox, Button );

				virtual void Render( Skin::Base* skin );
				virtual void Layout( Skin::Base* skin );
				virtual void UpdateColours();

				virtual void SelectItem( MenuItem* pItem, bool bFireChangeEvents = true );
				virtual void SelectItemByName( const gwen::String & name, bool bFireChangeEvents = true );
				virtual gwen::Controls::Label* GetSelectedItem();

				virtual void OnPress();
				virtual void OnItemSelected( Controls::Base* pControl );
				virtual void OpenList();
				virtual void CloseList();

				virtual void ClearItems();

				virtual MenuItem* AddItem( const UnicodeString & strLabel, const String & strName = "" );
				virtual bool OnKeyUp( bool bDown );
				virtual bool OnKeyDown( bool bDown );

				virtual void RenderFocus( gwen::Skin::Base* skin );
				virtual void OnLostKeyboardFocus();
				virtual void OnKeyboardFocus();

				virtual bool IsMenuOpen();

				virtual bool IsMenuComponent() { return true; }

				gwen::Event::Caller	onSelection;

			protected:

				Menu* m_Menu;
				MenuItem* m_SelectedItem;

				Controls::Base*	m_Button;

		};

	}
}
#endif
