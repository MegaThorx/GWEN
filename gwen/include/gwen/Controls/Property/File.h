
#pragma once
#ifndef GWEN_CONTROLS_PROPERTY_FILE_H
#define GWEN_CONTROLS_PROPERTY_FILE_H

#include "gwen/Controls/Properties.h"
#include "gwen/Controls/Button.h"
#include "gwen/Controls/Dialogs/FolderOpen.h"

namespace gwen
{
	namespace Controls
	{
		namespace Property
		{
			class File : public Property::Text
			{
					GWEN_CONTROL_INLINE( File, Property::Text )
					{
						Controls::Button* pButton = new Controls::Button( this );
						pButton->Dock( Pos::Right );
						pButton->SetText( "..." );
						pButton->SetWidth( 20 );
						pButton->onPress.Add( this, &ThisClass::OnButtonPress );
						pButton->SetMargin( Margin( 1, 1, 1, 2 ) );
						m_strDialogName = "Find File";
						m_strFileExtension = "*.*";
					}

					File* SetExtension( const gwen::String & string )
					{
						m_strFileExtension = string;
						return this;
					}

					void OnButtonPress( Controls::Base* control )
					{
						gwen::Dialogs::FileOpen( true, m_strDialogName, m_TextBox->GetText().Get(), m_strFileExtension, this, &File::EventFilePicked );
					}

					void EventFilePicked( Event::Info info )
					{
						m_TextBox->SetText( info.String );
					}


					String	m_strDialogName;
					String	m_strFileExtension;

			};
		}
	}
}
#endif
