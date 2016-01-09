#include "gwen/UnitTest/UnitTest.h"
#include "gwen/Controls/TextBox.h"

using namespace gwen;

class TextBox : public GUnit
{
	public:

		GWEN_CONTROL_INLINE( TextBox, GUnit )
		{
			{
				gwen::Controls::TextBox* label = new gwen::Controls::TextBox( this );
				label->SetText( "" );
				label->SetPos( 10, 10 );
				label->onTextChanged.Add( this, &ThisClass::OnEdit );
				label->onReturnPressed.Add( this, &ThisClass::OnSubmit );
			}
			{
				gwen::Controls::TextBox* label = new gwen::Controls::TextBox( this );
				label->SetText( "Normal Everyday Label" );
				label->SetPos( 10, 10 + 25 );
			}
			{
				gwen::Controls::TextBox* label = new gwen::Controls::TextBox( this );
				label->SetText( "Select All Text On Focus" );
				label->SetPos( 10, 10 + 25 * 2 );
				label->SetSelectAllOnFocus( true );
			}
			{
				gwen::Controls::TextBox* label = new gwen::Controls::TextBox( this );
				label->SetText( L"Different Coloured Text, for some reason" );
				label->SetTextColor( gwen::Color( 255, 0, 255, 255 ) );
				label->SetPos( 10, 10 + 25 * 3 );
			}
			{
				gwen::Controls::TextBoxNumeric* label = new gwen::Controls::TextBoxNumeric( this );
				label->SetText( L"2004" );
				label->SetTextColor( gwen::Color( 255, 0, 255, 255 ) );
				label->SetPos( 10, 10 + 25 * 4 );
			}
			{
				m_Font.facename = L"Impact";
				m_Font.size = 50;
				gwen::Controls::TextBox* label = new gwen::Controls::TextBox( this );
				label->SetText( L"Different Font" );
				label->SetPos( 10, 10 + 25 * 5 );
				label->SetFont( &m_Font );
				label->SetSize( 200, 55 );
			}
			{
				gwen::Controls::TextBoxMultiline* label = new gwen::Controls::TextBoxMultiline( this );
				label->SetText( "I think we're losing sight of the real issue here, which is: what are we gonna call ourselves?\n\nErm, and I think it comes down to a choice between \"The League Against Salivating Monsters\" or my own personal preference, which is \"The Committee for the Liberation and Integration of Terrifying Organisms and their Rehabilitation Into Society.\" Erm, one drawback with that: the abbreviation is \"CLITORIS.\"" );
				label->SetPos( 220, 10 );
				label->SetSize( 200, 180 );
			}
		}

		void OnEdit( gwen::Controls::Base* pControl )
		{

			gwen::Controls::TextBox* textbox = ( gwen::Controls::TextBox* )( pControl );
			UnitPrint( Utility::Format( L"Textbox Edit: [%ls]\n", textbox->GetText().GetUnicode().c_str() ) );
		}

		void OnSubmit( gwen::Controls::Base* pControl )
		{
			gwen::Controls::TextBox* textbox = ( gwen::Controls::TextBox* )( pControl );
			UnitPrint( Utility::Format( L"Textbox Submit: [%ls]\n", textbox->GetText().GetUnicode().c_str() ) );
		}

		gwen::Font	m_Font;
};



DEFINE_UNIT_TEST( TextBox, L"TextBox" );
