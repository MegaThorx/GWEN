/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#ifndef GWEN_CONTROLS_LABEL_H
#define GWEN_CONTROLS_LABEL_H

#include "gwen/BaseRender.h"
#include "gwen/Controls/Base.h"
#include "gwen/Controls/Text.h"

namespace gwen
{
	namespace Controls
	{
		class GWEN_EXPORT Label : public Controls::Base
		{
			public:

				GWEN_CONTROL( Label, Controls::Base );
				virtual void PreDelete( gwen::Skin::Base* skin );

				virtual void SetText( const TextObject & str, bool bDoEvents = true );

				virtual const TextObject & GetText() const { return m_Text->GetText(); }

				virtual void Render( Skin::Base* /*skin*/ ) {}

				virtual void PostLayout( Skin::Base* skin );

				virtual void SizeToContents();

				virtual void SetAlignment( int iAlign );
				virtual int GetAlignment();


				virtual void SetFont( gwen::UnicodeString strFacename, int iSize, bool bBold );

				virtual void SetFont( gwen::Font* pFont ) { m_Text->SetFont( pFont ); }
				virtual gwen::Font* GetFont() { return m_Text->GetFont(); }
				virtual void SetTextColor( const gwen::Color & col ) { m_Text->SetTextColor( col ); }
				virtual void SetTextColorOverride( const gwen::Color & col ) { m_Text->SetTextColorOverride( col ); }
				inline const gwen::Color & TextColor() const { return m_Text->TextColor(); }

				virtual int TextWidth() { return m_Text->Width(); }
				virtual int TextRight() { return m_Text->Right(); }
				virtual int TextHeight() { return m_Text->Height(); }
				virtual int TextX() { return m_Text->X(); }
				virtual int TextY() { return m_Text->Y(); }
				virtual int TextLength() { return m_Text->Length(); }

				gwen::Rect GetCharacterPosition( int iChar );

				virtual void SetTextPadding( const Padding & padding ) { m_Text->SetPadding( padding ); Invalidate(); InvalidateParent(); }
				virtual const Padding & GetTextPadding() { return m_Text->GetPadding(); }

				inline int Alignment() const { return m_iAlign; }

				virtual void MakeColorNormal() { SetTextColor( GetSkin()->Colors.Label.Default ); }
				virtual void MakeColorBright() { SetTextColor( GetSkin()->Colors.Label.Bright ); }
				virtual void MakeColorDark() { SetTextColor( GetSkin()->Colors.Label.Dark ); }
				virtual void MakeColorHighlight() { SetTextColor( GetSkin()->Colors.Label.Highlight ); }

				virtual TextObject GetValue() { return GetText(); }
				virtual void SetValue( const TextObject & strValue ) { return SetText( strValue ); }

				virtual bool Wrap() { return m_Text->Wrap(); }
				virtual void SetWrap( bool b ) { m_Text->SetWrap( b ); }

				virtual void OnBoundsChanged( gwen::Rect oldChildBounds );

			protected:

				virtual void OnTextChanged() {};

				gwen::Font*					m_CreatedFont;
				ControlsInternal::Text*		m_Text;
				int m_iAlign;


		};
	}
}
#endif
