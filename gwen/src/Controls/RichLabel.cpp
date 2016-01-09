/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/


#include "gwen/Gwen.h"
#include "gwen/Controls/RichLabel.h"
#include "gwen/Controls/Label.h"
#include "gwen/Utility.h"

using namespace gwen;
using namespace gwen::Controls;

const unsigned char Type_Text = 0;
const unsigned char Type_Newline = 1;

GWEN_CONTROL_CONSTRUCTOR( RichLabel )
{
	m_bNeedsRebuild = false;
}

void RichLabel::AddLineBreak()
{
	DividedText t;
	t.type = Type_Newline;
	m_TextBlocks.push_back( t );
}

void RichLabel::AddText( const gwen::TextObject & text, gwen::Color color, gwen::Font* font )
{
	if ( text.length() == 0 ) { return; }

	gwen::Utility::Strings::UnicodeList lst;
	gwen::Utility::Strings::Split( text.GetUnicode(), L"\n", lst, false );

	for ( size_t i = 0; i < lst.size(); i++ )
	{
		if ( i > 0 ) { AddLineBreak(); }

		DividedText t;
		t.type = Type_Text;
		t.text = lst[i];
		t.color = color;
		t.font = font;
		m_TextBlocks.push_back( t );
		m_bNeedsRebuild = true;
		Invalidate();
	}
}

bool RichLabel::SizeToChildren( bool w, bool h )
{
	Rebuild();
	return BaseClass::SizeToChildren( w, h );
}

void RichLabel::SplitLabel( const gwen::UnicodeString & text, gwen::Font* pFont, const DividedText & txt, int & x, int & y, int & lineheight )
{
	gwen::Utility::Strings::UnicodeList lst;
	gwen::Utility::Strings::Split( text, L" ", lst, true );

	if ( lst.size() == 0 ) { return; }

	int iSpaceLeft = Width() - x;
	// Does the whole word fit in?
	{
		gwen::Point StringSize = GetSkin()->GetRender()->MeasureText( pFont, text );

		if ( iSpaceLeft > StringSize.x )
		{
			return CreateLabel( text, txt, x, y, lineheight, true );
		}
	}
	// If the first word is bigger than the line, just give up.
	{
		gwen::Point WordSize = GetSkin()->GetRender()->MeasureText( pFont, lst[0] );

		if ( WordSize.x >= iSpaceLeft )
		{
			CreateLabel( lst[0], txt, x, y, lineheight, true );

			if ( lst[0].size() >= text.size() ) { return; }

			gwen::UnicodeString LeftOver = text.substr( lst[0].size() + 1 );
			return SplitLabel( LeftOver, pFont, txt, x, y, lineheight );
		}
	}
	gwen::UnicodeString strNewString = L"";

	for ( size_t i = 0; i < lst.size(); i++ )
	{
		gwen::Point WordSize = GetSkin()->GetRender()->MeasureText( pFont, strNewString + lst[i] );

		if ( WordSize.x > iSpaceLeft )
		{
			CreateLabel( strNewString, txt, x, y, lineheight, true );
			x = 0;
			y += lineheight;
			break;;
		}

		strNewString += lst[i];
	}

	if ( strNewString.size() >= text.size() ) return;
	gwen::UnicodeString LeftOver = text.substr( strNewString.size() + 1 );
	return SplitLabel( LeftOver, pFont, txt, x, y, lineheight );
}

void RichLabel::CreateLabel( const gwen::UnicodeString & text, const DividedText & txt, int & x, int & y, int & lineheight, bool NoSplit )
{
	//
	// Use default font or is one set?
	//
	gwen::Font* pFont = GetSkin()->GetDefaultFont();

	if ( txt.font ) { pFont = txt.font; }

	//
	// This string is too long for us, split it up.
	//
	gwen::Point p = GetSkin()->GetRender()->MeasureText( pFont, text );

	if ( lineheight == -1 )
	{
		lineheight = p.y;
	}

	if ( !NoSplit )
	{
		if ( x + p.x > Width() )
		{
			return SplitLabel( text, pFont, txt, x, y, lineheight );
		}
	}

	//
	// Wrap
	//
	if ( x + p.x >= Width() )
	{
		CreateNewline( x, y, lineheight );
	}

	gwen::Controls::Label*	pLabel = new gwen::Controls::Label( this );
	pLabel->SetText( x == 0 ? gwen::Utility::Strings::TrimLeft<gwen::UnicodeString> ( text, L" " ) : text );
	pLabel->SetTextColor( txt.color );
	pLabel->SetFont( pFont );
	pLabel->SizeToContents();
	pLabel->SetPos( x, y );
	//lineheight = (lineheight + pLabel->Height()) / 2;
	x += pLabel->Width();

	if ( x >= Width() )
	{
		CreateNewline( x, y, lineheight );
	}
}

void RichLabel::CreateNewline( int & x, int & y, int & lineheight )
{
	x = 0;
	y += lineheight;
}

void RichLabel::Rebuild()
{
	RemoveAllChildren();
	int x = 0;
	int y = 0;
	int lineheight = -1;

	for ( DividedText::List::iterator it = m_TextBlocks.begin(); it != m_TextBlocks.end(); ++it )
	{
		if ( it->type == Type_Newline )
		{
			CreateNewline( x, y, lineheight );
			continue;
		}

		if ( it->type == Type_Text )
		{
			CreateLabel( ( *it ).text, *it, x, y, lineheight, false );
			continue;
		}
	}

	m_bNeedsRebuild = false;
}

void RichLabel::OnBoundsChanged( gwen::Rect oldBounds )
{
	BaseClass::OnBoundsChanged( oldBounds );
	Rebuild();
}

void RichLabel::Layout( gwen::Skin::Base* skin )
{
	BaseClass::Layout( skin );

	if ( m_bNeedsRebuild )
	{
		Rebuild();
	}
}