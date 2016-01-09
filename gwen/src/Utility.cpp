/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#include "gwen/ToolTip.h"
#include "gwen/Utility.h"

#include <cstdio>

using namespace gwen;

#ifdef _MSC_VER
#pragma warning(disable:4267)// conversion from 'size_t' to 'int', possible loss of data
#endif

#ifdef __MINGW32__
#undef vswprintf
#define vswprintf _vsnwprintf
#endif

#ifdef _MSC_VER
#define GWEN_FNULL "NUL"
#define va_copy(d,s) ((d) = (s))
#else
#define GWEN_FNULL "/dev/null"
#endif

UnicodeString gwen::Utility::Format( const wchar_t* fmt, ... )
{
	va_list s;
	int len = 0;
	
	va_start( s, fmt );
	
	// Determine the length of the resulting string, this method is much faster
	// than looping and reallocating a bigger buffer size.
	{	
		FILE* fnull = fopen( GWEN_FNULL, "wb" );
		va_list c;
		va_copy( c, s );
		len = vfwprintf( fnull, fmt, c );
		va_end( c );
		fclose( fnull );
	} 
	
	UnicodeString strOut;
	
	if (len > 0)
	{
		strOut.resize( len + 1 );
		va_list c;
		va_copy( c, s );
		len = vswprintf( &strOut[0], strOut.size(), fmt, c );
		va_end( c );
		strOut.resize( len );
	}
	
	va_end( s );
	
	return strOut;
}



void gwen::Utility::Strings::Split( const gwen::String & str, const gwen::String & seperator, Strings::List & outbits, bool bLeave )
{
	int iOffset = 0;
	int iLength = str.length();
	int iSepLen = seperator.length();
	size_t i = str.find( seperator, 0 );

	while ( i != std::string::npos )
	{
		outbits.push_back( str.substr( iOffset, i - iOffset ) );
		iOffset = i + iSepLen;
		i = str.find( seperator, iOffset );

		if ( bLeave ) { iOffset -= iSepLen; }
	}

	outbits.push_back( str.substr( iOffset, iLength - iOffset ) );
}

void gwen::Utility::Strings::Split( const gwen::UnicodeString & str, const gwen::UnicodeString & seperator, Strings::UnicodeList & outbits, bool bLeave )
{
	int iOffset = 0;
	int iLength = str.length();
	int iSepLen = seperator.length();
	size_t i = str.find( seperator, 0 );

	while ( i != std::wstring::npos )
	{
		outbits.push_back( str.substr( iOffset, i - iOffset ) );
		iOffset = i + iSepLen;
		i = str.find( seperator, iOffset );

		if ( bLeave ) { iOffset -= iSepLen; }
	}

	outbits.push_back( str.substr( iOffset, iLength - iOffset ) );
}

int gwen::Utility::Strings::To::Int( const gwen::String & str )
{
	if ( str == "" ) { return 0; }

	return atoi( str.c_str() );
}

float gwen::Utility::Strings::To::Float( const gwen::String & str )
{
	if ( str == "" ) { return 0.0f; }

	return ( float ) atof( str.c_str() );
}

float gwen::Utility::Strings::To::Float( const gwen::UnicodeString & str )
{
	return wcstod( str.c_str(), NULL );
}

bool gwen::Utility::Strings::To::Bool( const gwen::String & str )
{
	if ( str.size() == 0 ) { return false; }

	if ( str[0] == 'T' || str[0] == 't' || str[0] == 'y' || str[0] == 'Y' ) { return true; }

	if ( str[0] == 'F' || str[0] == 'f' || str[0] == 'n' || str[0] == 'N' ) { return false; }

	if ( str[0] == '0' ) { return false; }

	return true;
}

bool gwen::Utility::Strings::To::Floats( const gwen::String & str, float* f, size_t iCount )
{
	Strings::List lst;
	Strings::Split( str, " ", lst );

	if ( lst.size() != iCount ) { return false; }

	for ( size_t i = 0; i < iCount; i++ )
	{
		f[i] = Strings::To::Float( lst[i] );
	}

	return true;
}


bool gwen::Utility::Strings::Wildcard( const TextObject & strWildcard, const TextObject & strHaystack )
{
	const UnicodeString & W = strWildcard.GetUnicode();
	const UnicodeString & H = strHaystack.GetUnicode();

	if ( strWildcard == "*" ) { return true; }

	int iPos = W.find( L"*", 0 );

	if ( iPos == UnicodeString::npos ) { return strWildcard == strHaystack; }

	// First half matches
	if ( iPos > 0 && W.substr( 0, iPos ) != H.substr( 0, iPos ) )
	{ return false; }

	// Second half matches
	if ( iPos != W.length() - 1 )
	{
		UnicodeString strEnd = W.substr( iPos + 1, W.length() );

		if ( strEnd != H.substr( H.length() - strEnd.length(), H.length() ) )
		{ return false; }
	}

	return true;
}



void gwen::Utility::Strings::ToUpper( gwen::UnicodeString & str )
{
	transform( str.begin(), str.end(), str.begin(), towupper );
}

void gwen::Utility::Strings::Strip( gwen::UnicodeString & str, const gwen::UnicodeString & chars )
{
	gwen::UnicodeString Source = str;
	str = L"";

	for ( unsigned int i = 0; i < Source.length(); i++ )
	{
		if ( chars.find( Source[i] ) != gwen::UnicodeString::npos )
		{ continue; }

		str += Source[i];
	}
}



