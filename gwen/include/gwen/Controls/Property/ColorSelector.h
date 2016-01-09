#pragma once
#ifndef GWEN_CONTROLS_PROPERTY_COLORSELECTOR_H
#define GWEN_CONTROLS_PROPERTY_COLORSELECTOR_H

#include "gwen/Controls/Properties.h"
#include "gwen/Controls/Menu.h"
#include "gwen/Controls/HSVColorPicker.h"

namespace gwen
{
	namespace Controls
	{
		namespace Internal
		{
			class ColourButton : public Button
			{
					GWEN_CONTROL_INLINE( ColourButton, Button )
					{
						m_Color = Colors::Black;
						SetText( "" );
					}

					void Render( Skin::Base* skin )
					{
						skin->GetRender()->SetDrawColor( m_Color );
						skin->GetRender()->DrawFilledRect( GetRenderBounds() );
					}

					void SetColor( const gwen::Color & col ) { m_Color = col; }

					gwen::Color	m_Color;
			};
		}

		namespace Property
		{
			class ColorSelector : public Property::Text
			{
					GWEN_CONTROL_INLINE( ColorSelector, Property::Text )
					{
						m_Button = new Controls::Internal::ColourButton( m_TextBox );
						m_Button->Dock( Pos::Right );
						m_Button->SetWidth( 20 );
						m_Button->onPress.Add( this, &ThisClass::OnButtonPress );
						m_Button->SetMargin( Margin( 1, 1, 1, 2 ) );
					}

					void OnButtonPress( Controls::Base* control )
					{
						gwen::Controls::Menu* pMenu = new Menu( GetCanvas() );
						pMenu->SetSize( 256, 180 );
						pMenu->SetDeleteOnClose( true );
						pMenu->SetDisableIconMargin( true );
						gwen::Controls::HSVColorPicker* picker = new gwen::Controls::HSVColorPicker( pMenu );
						picker->Dock( Pos::Fill );
						picker->SetSize( 256, 128 );
						float defaultColor[3];
						gwen::Utility::Strings::To::Floats( m_TextBox->GetText().Get(), defaultColor, 3 );
						picker->SetColor( gwen::Color( defaultColor[0], defaultColor[1], defaultColor[2], 255 ), false, true );
						picker->onColorChanged.Add( this, &ThisClass::ColorChanged );
						pMenu->Open( Pos::Right | Pos::Top );
					}

					void ColorChanged( Controls::Base* control )
					{
						gwen::Controls::HSVColorPicker* picker = gwen_cast<gwen::Controls::HSVColorPicker> ( control );
						gwen::String colorStr;
						colorStr += gwen::Utility::ToString( ( int ) picker->GetColor().r ) + " ";
						colorStr += gwen::Utility::ToString( ( int ) picker->GetColor().g ) + " ";
						colorStr += gwen::Utility::ToString( ( int ) picker->GetColor().b );
						m_TextBox->SetText( colorStr );
						DoChanged();
					}

					virtual TextObject GetPropertyValue()
					{
						return m_TextBox->GetText();
					}

					virtual void SetPropertyValue( const TextObject & v, bool bFireChangeEvents )
					{
						m_TextBox->SetText( v, bFireChangeEvents );
					}

					virtual bool IsEditing()
					{
						return m_TextBox == gwen::KeyboardFocus;
					}

					virtual void DoChanged()
					{
						BaseClass::DoChanged();
						float col[3];
						gwen::Utility::Strings::To::Floats( m_TextBox->GetText().Get(), col, 3 );
						m_Button->SetColor( gwen::Color( col[0], col[1], col[2] ) );
					}

					Controls::Internal::ColourButton*		m_Button;
			};
		}
	}
}
#endif
