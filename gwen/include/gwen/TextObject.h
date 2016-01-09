/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#ifndef GWEN_TEXTOBJECT_H
#define GWEN_TEXTOBJECT_H

#include "gwen/Utility.h"

namespace gwen
{
	/*

		TextObjects can be either a UnicodeString or a String

		Just makes things easier instead of having a function taking both.

	*/
	class TextObject
	{
		public:

			TextObject() {}

			TextObject( const gwen::String & text )
			{
				m_String = text;
				m_Unicode = gwen::Utility::StringToUnicode( m_String );
			}

			TextObject( const char* text )
			{
				m_String = text;
				m_Unicode = gwen::Utility::StringToUnicode( m_String );
			}

			TextObject( const wchar_t* text )
			{
				m_Unicode = text;
				m_String = gwen::Utility::UnicodeToString( m_Unicode );
			}

			TextObject( const gwen::UnicodeString & unicode )
			{
				*this = unicode;
			}

			operator const gwen::String & () { return m_String; }
			operator const gwen::UnicodeString & () { return m_Unicode; }

			void operator = ( const char* str )
			{
				m_String = str;
				m_Unicode = gwen::Utility::StringToUnicode( m_String );
			}

			void operator = ( const gwen::String & str )
			{
				m_String = str;
				m_Unicode = gwen::Utility::StringToUnicode( m_String );
			}

			void operator = ( const gwen::UnicodeString & unicodeStr )
			{
				m_Unicode = unicodeStr;
				m_String = gwen::Utility::UnicodeToString( m_Unicode );
			}

			bool operator == ( const TextObject & to ) const
			{
				return m_Unicode == to.m_Unicode;
			}

			const gwen::String & Get() const
			{
				return m_String;
			}

			const char* c_str() const
			{
				return m_String.c_str();
			}

			const gwen::UnicodeString & GetUnicode() const
			{
				return m_Unicode;
			}

			int length() const { return m_Unicode.length(); }

			gwen::UnicodeString		m_Unicode;
			gwen::String			m_String;
	};
}
#endif
