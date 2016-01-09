/*
	GWEN
	Copyright (c) 2012 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#ifndef GWEN_CONTROLS_FOLDERPICKER_H
#define GWEN_CONTROLS_FOLDERPICKER_H

#include "gwen/BaseRender.h"
#include "gwen/Controls/Dialogs/FolderOpen.h"
#include "gwen/Controls/TextBox.h"


namespace gwen
{
	namespace Controls
	{
		class GWEN_EXPORT FolderPicker : public Controls::Base
		{
			public:

				GWEN_CONTROL_INLINE( FolderPicker, Controls::Base )
				{
					m_Button = new Controls::Button( this );
					m_Button->Dock( Pos::Right );
					m_Button->SetMargin( Margin( 2, 0, 0, 0 ) );
					m_Button->SetText( ".." );
					m_Button->SetSize( 20, 20 );
					m_Button->onPress.Add( this, &FolderPicker::OnBrowse );
					m_TextBox = new Controls::TextBox( this );
					m_TextBox->Dock( Pos::Fill );
					this->SetSize( 100, 20 );
					m_BrowseName = "Find Folder";
				}



				void SetFolder( const TextObject & strValue )
				{
					m_TextBox->SetText( strValue );
					m_TextBox->MoveCaretToEnd();
					onFolderChanged.Call( this );
				}


				const gwen::TextObject & GetFolder()
				{
					return m_TextBox->GetText();
				}

				void OnBrowse()
				{
					gwen::Dialogs::FolderOpen( true, "Name", GetFolder().Get(), this, &FolderPicker::SetFolderCallback );
				}

				virtual TextObject GetValue() { return GetFolder(); }
				virtual void SetValue( const TextObject & strValue ) { return SetFolder( strValue ); }

				Event::Caller	onFolderChanged;

			private:

				void SetFolderCallback( gwen::Event::Info info )
				{
					SetFolder( info.String );
				}

				Controls::TextBox*	m_TextBox;
				Controls::Button*	m_Button;
				gwen::String		m_BrowseName;

		};
	}

}
#endif
