/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#ifndef GWEN_CONTROLS_RADIOBUTTON_H
#define GWEN_CONTROLS_RADIOBUTTON_H

#include "gwen/Controls/Base.h"
#include "gwen/Controls/Label.h"
#include "gwen/Controls/Button.h"
#include "gwen/Gwen.h"
#include "gwen/Skin.h"
#include "gwen/Controls/CheckBox.h"
#include "gwen/Controls/LabelClickable.h"

namespace gwen
{
	namespace Controls
	{
		class GWEN_EXPORT RadioButton : public CheckBox
		{
				GWEN_CONTROL( RadioButton, CheckBox );
				virtual void Render( Skin::Base* skin );

			private:

				// From CheckBox
				virtual bool AllowUncheck() { return false; }
		};

		class GWEN_EXPORT LabeledRadioButton : public Base
		{
			public:

				GWEN_CONTROL_INLINE( LabeledRadioButton, Base )
				{
					SetSize( 200, 19 );
					m_RadioButton = new RadioButton( this );
					m_RadioButton->Dock( Pos::Left );
					m_RadioButton->SetMargin( Margin( 0, 2, 2, 2 ) );
					m_RadioButton->SetTabable( false );
					m_RadioButton->SetKeyboardInputEnabled( false );
					m_Label = new LabelClickable( this );
					m_Label->SetAlignment( Pos::CenterV | Pos::Left );
					m_Label->SetText( "Radio Button" );
					m_Label->Dock( Pos::Fill );
					m_Label->onPress.Add( m_RadioButton, &CheckBox::OnPress );
					m_Label->SetTabable( false );
					m_Label->SetKeyboardInputEnabled( false );
				}

				void RenderFocus( gwen::Skin::Base* skin )
				{
					if ( gwen::KeyboardFocus != this ) { return; }

					if ( !IsTabable() ) { return; }

					skin->DrawKeyboardHighlight( this, GetRenderBounds(), 0 );
				}

				virtual RadioButton*	GetRadioButton() { return m_RadioButton; }
				virtual LabelClickable*	GetLabel() { return m_Label; }
				virtual bool OnKeySpace( bool bDown ) { if ( bDown )  { m_RadioButton->SetChecked( !m_RadioButton->IsChecked() ); } return true;  }

				virtual void Select() { m_RadioButton->SetChecked( true ); }

			private:

				RadioButton*		m_RadioButton;
				LabelClickable*		m_Label;
		};
	}
}
#endif
