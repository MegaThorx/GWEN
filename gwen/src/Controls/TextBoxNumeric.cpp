/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/


#include "gwen/Gwen.h"
#include "gwen/Controls/TextBox.h"
#include "gwen/Skin.h"
#include "gwen/Utility.h"
#include "gwen/Platform.h"


using namespace gwen;
using namespace gwen::Controls;

GWEN_CONTROL_CONSTRUCTOR( TextBoxNumeric )
{
	SetText( L"0" );
}

bool TextBoxNumeric::IsTextAllowed( const gwen::UnicodeString & str, int iPos )
{
	const UnicodeString & strString = GetText().GetUnicode();

	if ( str.length() == 0 )
	{ return true; }

	for ( size_t i = 0; i < str.length(); i++ )
	{
		if ( str[i] == L'-' )
		{
			// Has to be at the start
			if ( i != 0 || iPos != 0 )
			{ return false; }

			// Can only be one
			if ( std::count( strString.begin(), strString.end(), L'-' ) > 0 )
			{ return false; }

			continue;
		}

		if ( str[i] == L'0' ) { continue; }

		if ( str[i] == L'1' ) { continue; }

		if ( str[i] == L'2' ) { continue; }

		if ( str[i] == L'3' ) { continue; }

		if ( str[i] == L'4' ) { continue; }

		if ( str[i] == L'5' ) { continue; }

		if ( str[i] == L'6' ) { continue; }

		if ( str[i] == L'7' ) { continue; }

		if ( str[i] == L'8' ) { continue; }

		if ( str[i] == L'9' ) { continue; }

		if ( str[i] == L'.' )
		{
			// Already a fullstop
			if ( std::count( strString.begin(), strString.end(), L'.' ) > 0 )
			{ return false; }

			continue;
		}

		return false;
	}

	return true;
}

float TextBoxNumeric::GetFloatFromText()
{
	double temp = gwen::Utility::Strings::To::Float( GetText().GetUnicode() );
	return temp;
}