/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#include "gwen/UnitTest/UnitTest.h"
#include "gwen/Controls/DockedTabControl.h"
#include "gwen/Controls/WindowControl.h"
#include "gwen/Controls/CollapsibleList.h"
#include "gwen/Controls/Layout/Position.h"
#include "gwen/Platform.h"

using namespace gwen;

#define ADD_UNIT_TEST( name )\
	GUnit* RegisterUnitTest_##name( gwen::Controls::Base* tab );\
	{\
		Controls::Button* pButton = cat->Add( #name );\
		pButton->SetName( #name );\
		GUnit* test = RegisterUnitTest_##name( pCenter );\
		test->Hide();\
		test->SetUnitTest( this );\
		pButton->onPress.Add( this, &ThisClass::OnCategorySelect, test );\
	}\

gwen::Controls::TabButton* pButton = NULL;

GWEN_CONTROL_CONSTRUCTOR( UnitTest )
{
	m_pLastControl = NULL;
	Dock( Pos::Fill );
	SetSize( 1024, 768 );
	Controls::CollapsibleList* pList = new Controls::CollapsibleList( this );
	GetLeft()->GetTabControl()->AddPage( "CollapsibleList", pList );
	GetLeft()->SetWidth( 150 );
	m_TextOutput = new Controls::ListBox( GetBottom() );
	pButton = GetBottom()->GetTabControl()->AddPage( "Output", m_TextOutput );
	GetBottom()->SetHeight( 200 );
	m_StatusBar = new Controls::StatusBar( this );
	m_StatusBar->Dock( Pos::Bottom );
	Controls::Layout::Center* pCenter = new Controls::Layout::Center( this );
	pCenter->Dock( Pos::Fill );
	{
		Controls::CollapsibleCategory* cat = pList->Add( "Basic" );
		ADD_UNIT_TEST( Button );
		ADD_UNIT_TEST( Label );
		ADD_UNIT_TEST( LabelMultiline );
	}
	{
		Controls::CollapsibleCategory* cat = pList->Add( "Non-Interactive" );
		ADD_UNIT_TEST( ProgressBar );
		ADD_UNIT_TEST( GroupBox );
		ADD_UNIT_TEST( ImagePanel );
		ADD_UNIT_TEST( StatusBar );
	}
	{
		Controls::CollapsibleCategory* cat = pList->Add( "Controls" );
		ADD_UNIT_TEST( ComboBox );
		ADD_UNIT_TEST( TextBox );
		ADD_UNIT_TEST( ListBox );
		ADD_UNIT_TEST( CrossSplitter );
		ADD_UNIT_TEST( RadioButton );
		ADD_UNIT_TEST( Checkbox );
		ADD_UNIT_TEST( Numeric );
		ADD_UNIT_TEST( Slider );
		ADD_UNIT_TEST( MenuStrip );
	}
	{
		Controls::CollapsibleCategory* cat = pList->Add( "Containers" );
		ADD_UNIT_TEST( Window );
		ADD_UNIT_TEST( TreeControl );
		ADD_UNIT_TEST( Properties );
		ADD_UNIT_TEST( TabControl );
		ADD_UNIT_TEST( ScrollControl );
		ADD_UNIT_TEST( PageControl );
	}
	{
		Controls::CollapsibleCategory* cat = pList->Add( "Non-Standard" );
		ADD_UNIT_TEST( CollapsibleList );
		ADD_UNIT_TEST( ColorPicker );
	}
	m_StatusBar->SendToBack();
	PrintText( L"Unit Test Started.\n" );
	m_fLastSecond = gwen::Platform::GetTimeInSeconds();
	m_iFrames = 0;
	pList->GetNamedChildren( "MenuStrip" ).DoAction();
}

void UnitTest::OnCategorySelect( gwen::Event::Info info )
{
	if ( m_pLastControl )
	{
		m_pLastControl->Hide();
	}

	static_cast<gwen::Controls::Base*>(info.Data)->Show();
	m_pLastControl = static_cast<gwen::Controls::Base*>(info.Data);
}

void UnitTest::PrintText( const gwen::UnicodeString & str )
{
	m_TextOutput->AddItem( str );
	m_TextOutput->ScrollToBottom();
}

void UnitTest::Render( gwen::Skin::Base* skin )
{
	m_iFrames++;

	if ( m_fLastSecond < gwen::Platform::GetTimeInSeconds() )
	{
		m_StatusBar->SetText( gwen::Utility::Format( L"GWEN Unit Test - %i fps", m_iFrames * 2 ) );
		m_fLastSecond = gwen::Platform::GetTimeInSeconds() + 0.5f;
		m_iFrames = 0;
	}

	BaseClass::Render( skin );
}

void GUnit::UnitPrint( gwen::UnicodeString str )
{
	m_pUnitTest->PrintText( str );
}

void GUnit::UnitPrint( gwen::String str )
{
	UnitPrint( Utility::StringToUnicode( str ) );
}

