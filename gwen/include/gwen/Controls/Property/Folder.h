
#pragma once
#ifndef GWEN_CONTROLS_PROPERTY_FOLDER_H
#define GWEN_CONTROLS_PROPERTY_FOLDER_H

#include "gwen/Controls/Properties.h"
#include "gwen/Controls/Button.h"
#include "gwen/Controls/Dialogs/FolderOpen.h"

namespace gwen
{
	namespace Controls
	{
		namespace Property
		{
			class Folder : public Property::Text
			{
					GWEN_CONTROL_INLINE( Folder, Property::Text )
					{
						Controls::Button* pButton = new Controls::Button( this );
						pButton->Dock( Pos::Right );
						pButton->SetText( "..." );
						pButton->SetWidth( 20 );
						pButton->onPress.Add( this, &ThisClass::OnButtonPress );
						pButton->SetMargin( Margin( 1, 1, 1, 2 ) );
						m_strDialogName = "Find Folder";
					}

					void OnButtonPress( Controls::Base* control )
					{
						gwen::Dialogs::FolderOpen( true, m_strDialogName, m_TextBox->GetText().Get(), this, &Folder::EventFilePicked );
					}

					void EventFilePicked( Event::Info info )
					{
						m_TextBox->SetText( info.String );
					}


					String	m_strDialogName;

			};
		}
	}
}
#endif
