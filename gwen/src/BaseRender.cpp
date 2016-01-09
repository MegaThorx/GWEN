/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/


#include "gwen/Gwen.h"
#include "gwen/BaseRender.h"
#include "gwen/Utility.h"
#include "gwen/Platform.h"

#include <math.h>

namespace gwen
{
	namespace Renderer
	{

		Base::Base()
		{
			m_RenderOffset = gwen::Point( 0, 0 );
			m_fScale = 1.0f;
		}

		Base::~Base()
		{
			if ( GetCTT() )
			{ GetCTT()->ShutDown(); }
		}

		void Base::RenderText( gwen::Font* pFont, gwen::Point pos, const gwen::String & text )
		{
			gwen::UnicodeString str = gwen::Utility::StringToUnicode( text );
			RenderText( pFont, pos, str );
		}

		gwen::Point Base::MeasureText( gwen::Font* pFont, const gwen::String & text )
		{
			gwen::UnicodeString str = gwen::Utility::StringToUnicode( text );
			return MeasureText( pFont, str );
		}

		void Base::DrawLinedRect( gwen::Rect rect )
		{
			DrawFilledRect( gwen::Rect( rect.x, rect.y, rect.w, 1 ) );
			DrawFilledRect( gwen::Rect( rect.x, rect.y + rect.h - 1, rect.w, 1 ) );
			DrawFilledRect( gwen::Rect( rect.x, rect.y, 1, rect.h ) );
			DrawFilledRect( gwen::Rect( rect.x + rect.w - 1, rect.y, 1, rect.h ) );
		};

		void Base::DrawPixel( int x, int y )
		{
			DrawFilledRect( gwen::Rect( x, y, 1, 1 ) );
		}

		void Base::DrawShavedCornerRect( gwen::Rect rect, bool bSlight )
		{
			// Draw INSIDE the w/h.
			rect.w -= 1;
			rect.h -= 1;

			if ( bSlight )
			{
				DrawFilledRect( gwen::Rect( rect.x + 1, rect.y, rect.w - 1, 1 ) );
				DrawFilledRect( gwen::Rect( rect.x + 1, rect.y + rect.h, rect.w - 1, 1 ) );
				DrawFilledRect( gwen::Rect( rect.x, rect.y + 1, 1, rect.h - 1 ) );
				DrawFilledRect( gwen::Rect( rect.x + rect.w, rect.y + 1, 1, rect.h - 1 ) );
				return;
			}

			DrawPixel( rect.x + 1, rect.y + 1 );
			DrawPixel( rect.x + rect.w - 1, rect.y + 1 );
			DrawPixel( rect.x + 1, rect.y + rect.h - 1 );
			DrawPixel( rect.x + rect.w - 1, rect.y + rect.h - 1 );
			DrawFilledRect( gwen::Rect( rect.x + 2, rect.y, rect.w - 3, 1 ) );
			DrawFilledRect( gwen::Rect( rect.x + 2, rect.y + rect.h, rect.w - 3, 1 ) );
			DrawFilledRect( gwen::Rect( rect.x, rect.y + 2, 1, rect.h - 3 ) );
			DrawFilledRect( gwen::Rect( rect.x + rect.w, rect.y + 2, 1, rect.h - 3 ) );
		}

		void Base::Translate( int & x, int & y )
		{
			x += m_RenderOffset.x;
			y += m_RenderOffset.y;
			x = ceilf( ( ( float ) x ) * m_fScale );
			y = ceilf( ( ( float ) y ) * m_fScale );
		}

		void Base::Translate( gwen::Rect & rect )
		{
			Translate( rect.x, rect.y );
			rect.w = ceilf( ( ( float ) rect.w ) * m_fScale );
			rect.h = ceilf( ( ( float ) rect.h ) * m_fScale );
		}

		void gwen::Renderer::Base::SetClipRegion( gwen::Rect rect )
		{
			m_rectClipRegion = rect;
		}

		void Base::AddClipRegion( gwen::Rect rect )
		{
			rect.x = m_RenderOffset.x;
			rect.y = m_RenderOffset.y;
			gwen::Rect out = rect;

			if ( rect.x < m_rectClipRegion.x )
			{
				out.w -= ( m_rectClipRegion.x - out.x );
				out.x = m_rectClipRegion.x;
			}

			if ( rect.y < m_rectClipRegion.y )
			{
				out.h -= ( m_rectClipRegion.y - out.y );
				out.y = m_rectClipRegion.y;
			}

			if ( rect.x + rect.w > m_rectClipRegion.x + m_rectClipRegion.w )
			{
				out.w = ( m_rectClipRegion.x + m_rectClipRegion.w ) - out.x;
			}

			if ( rect.y + rect.h > m_rectClipRegion.y + m_rectClipRegion.h )
			{
				out.h = ( m_rectClipRegion.y + m_rectClipRegion.h ) - out.y;
			}

			m_rectClipRegion = out;
		}

		const gwen::Rect & Base::ClipRegion() const
		{
			return m_rectClipRegion;
		}

		bool Base::ClipRegionVisible()
		{
			if ( m_rectClipRegion.w <= 0 || m_rectClipRegion.h <= 0 )
			{ return false; }

			return true;
		}

		void Base::DrawMissingImage( gwen::Rect pTargetRect )
		{
			SetDrawColor( Colors::Red );
			DrawFilledRect( pTargetRect );
		}


		/*
			If they haven't defined these font functions in their renderer code
			we just draw some rects where the letters would be to give them an idea.
		*/

		void Base::RenderText( gwen::Font* pFont, gwen::Point pos, const gwen::UnicodeString & text )
		{
			float fSize = pFont->size * Scale();

			for ( float i = 0; i < text.length(); i++ )
			{
				wchar_t chr = text[i];

				if ( chr == ' ' ) { continue; }

				gwen::Rect r( pos.x + i * fSize * 0.4, pos.y, fSize * 0.4 - 1, fSize );

				/*
					This isn't important, it's just me messing around changing the
					shape of the rect based on the letter.. just for fun.
				*/
				if ( chr == 'l' || chr == 'i' || chr == '!' || chr == 't' )
				{
					r.w = 1;
				}
				else if ( chr >= 'a' && chr <= 'z' )
				{
					r.y += fSize * 0.5f;
					r.h -= fSize * 0.4f;
				}
				else if ( chr == '.' || chr == ',' )
				{
					r.x += 2;
					r.y += r.h - 2;
					r.w = 2;
					r.h = 2;
				}
				else if ( chr == '\'' || chr == '`'  || chr == '"' )
				{
					r.x += 3;
					r.w = 2;
					r.h = 2;
				}

				if ( chr == 'o' || chr == 'O' || chr == '0' )
				{ DrawLinedRect( r ); }
				else
				{ DrawFilledRect( r ); }
			}
		}

		gwen::Point Base::MeasureText( gwen::Font* pFont, const gwen::UnicodeString & text )
		{
			gwen::Point p;
			p.x = pFont->size * Scale() * ( float ) text.length() * 0.4;
			p.y = pFont->size * Scale();
			return p;
		}
	}
}