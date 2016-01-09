/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/


#include "gwen/Controls/HSVColorPicker.h"
#include "gwen/Controls/ColorControls.h"
#include "gwen/Controls/ColorPicker.h"
#include "gwen/Controls/TextBox.h"
#include "gwen/Controls/Label.h"
#include "gwen/Utility.h"

using namespace gwen;
using namespace gwen::Controls;


GWEN_CONTROL_CONSTRUCTOR( HSVColorPicker )
{
	SetMouseInputEnabled( true );
	SetSize( 256, 64 );
	SetCacheToTexture();
	m_LerpBox = new gwen::Controls::ColorLerpBox( this );
	m_LerpBox->onSelectionChanged.Add( this, &HSVColorPicker::ColorBoxChanged );
	m_LerpBox->Dock( Pos::Left );
	m_ColorSlider = new gwen::Controls::ColorSlider( this );
	m_ColorSlider->SetPos( m_LerpBox->Width() + 15, 5 );
	m_ColorSlider->onSelectionChanged.Add( this, &HSVColorPicker::ColorSliderChanged );
	m_ColorSlider->Dock( Pos::Left );
	m_After = new gwen::ControlsInternal::ColorDisplay( this );
	m_After->SetSize( 48, 24 );
	m_After->SetPos( m_ColorSlider->X() + m_ColorSlider->Width() + 15, 5 );
	m_Before = new gwen::ControlsInternal::ColorDisplay( this );
	m_Before->SetSize( 48, 24 );
	m_Before->SetPos( m_After->X(), 28 );
	int x = m_Before->X();
	int y = m_Before->Y() + 30;
	{
		Label* label = new Label( this );
		label->SetText( L"R:" );
		label->SizeToContents();
		label->SetPos( x, y );
		TextBoxNumeric* numeric = new TextBoxNumeric( this );
		numeric->SetName( "RedBox" );
		numeric->SetPos( x + 15, y - 1 );
		numeric->SetSize( 26, 16 );
		numeric->SetSelectAllOnFocus( true );
		numeric->onTextChanged.Add( this, &HSVColorPicker::NumericTyped );
	}
	y += 20;
	{
		Label* label = new Label( this );
		label->SetText( L"G:" );
		label->SizeToContents();
		label->SetPos( x, y );
		TextBoxNumeric* numeric = new TextBoxNumeric( this );
		numeric->SetName( "GreenBox" );
		numeric->SetPos( x + 15, y - 1 );
		numeric->SetSize( 26, 16 );
		numeric->SetSelectAllOnFocus( true );
		numeric->onTextChanged.Add( this, &HSVColorPicker::NumericTyped );
	}
	y += 20;
	{
		Label* label = new Label( this );
		label->SetText( L"B:" );
		label->SizeToContents();
		label->SetPos( x, y );
		TextBoxNumeric* numeric = new TextBoxNumeric( this );
		numeric->SetName( "BlueBox" );
		numeric->SetPos( x + 15, y - 1 );
		numeric->SetSize( 26, 16 );
		numeric->SetSelectAllOnFocus( true );
		numeric->onTextChanged.Add( this, &HSVColorPicker::NumericTyped );
	}
}

void HSVColorPicker::NumericTyped( gwen::Controls::Base* control )
{
	TextBoxNumeric* box = gwen_cast<TextBoxNumeric> ( control );

	if ( !box ) { return; }

	if ( box->GetText() == L"" )	{ return; }

	int textValue = atoi( box->GetText().c_str() );

	if ( textValue < 0 ) { textValue = 0; }

	if ( textValue > 255 ) { textValue = 255; }

	gwen::Color newColor = GetColor();

	if ( box->GetName().find( "Red" ) != gwen::String::npos )
	{
		newColor.r = textValue;
	}
	else if ( box->GetName().find( "Green" ) != gwen::String::npos )
	{
		newColor.g = textValue;
	}
	else if ( box->GetName().find( "Blue" ) != gwen::String::npos )
	{
		newColor.b = textValue;
	}
	else if ( box->GetName().find( "Alpha" ) != gwen::String::npos )
	{
		newColor.a = textValue;
	}

	SetColor( newColor );
}

void HSVColorPicker::UpdateControls( gwen::Color color )
{
	// What in the FUCK
	TextBoxNumeric* redBox = gwen_cast<TextBoxNumeric> ( FindChildByName( "RedBox",   false ) );

	if ( redBox )    { redBox->SetText( gwen::Utility::ToString( ( int ) color.r ), false ); }

	TextBoxNumeric* greenBox = gwen_cast<TextBoxNumeric> ( FindChildByName( "GreenBox",   false ) );

	if ( greenBox )  { greenBox->SetText( gwen::Utility::ToString( ( int ) color.g ), false ); }

	TextBoxNumeric* blueBox = gwen_cast<TextBoxNumeric> ( FindChildByName( "BlueBox",   false ) );

	if ( blueBox )   { blueBox->SetText( gwen::Utility::ToString( ( int ) color.b ), false ); }

	m_After->SetColor( color );
}
void HSVColorPicker::SetColor( gwen::Color color, bool onlyHue, bool reset )
{
	UpdateControls( color );

	if ( reset )
	{ m_Before->SetColor( color ); }

	m_ColorSlider->SetColor( color );
	m_LerpBox->SetColor( color,  onlyHue );
	m_After->SetColor( color );
}

gwen::Color HSVColorPicker::GetColor()
{
	return m_LerpBox->GetSelectedColor();
}

void HSVColorPicker::ColorBoxChanged( gwen::Controls::Base* /*pControl*/ )
{
	onColorChanged.Call( this );
	UpdateControls( GetColor() );
	Invalidate();
}
void HSVColorPicker::ColorSliderChanged( gwen::Controls::Base* /*pControl*/ )
{
	if ( m_LerpBox )
	{ m_LerpBox->SetColor( m_ColorSlider->GetSelectedColor(),  true ); }

	Invalidate();
}