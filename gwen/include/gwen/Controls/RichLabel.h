/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#ifndef GWEN_CONTROLS_RICHLABEL_H
#define GWEN_CONTROLS_RICHLABEL_H

#include "gwen/BaseRender.h"
#include "gwen/Controls/Base.h"
#include "gwen/Controls/Text.h"


namespace gwen
{
	namespace Controls
	{
		class GWEN_EXPORT RichLabel : public Controls::Base
		{
			public:

				GWEN_CONTROL( RichLabel, gwen::Controls::Base );

				void AddLineBreak();
				void AddText( const gwen::TextObject & text, gwen::Color color, gwen::Font* font = NULL );

				virtual bool SizeToChildren( bool w = true, bool h = true );

			protected:

				struct DividedText
				{
					typedef std::list<DividedText> List;
					DividedText()
					{
						type = 0;
						font = NULL;
					}

					unsigned char			type;
					gwen::UnicodeString		text;
					gwen::Color				color;
					gwen::Font*				font;
				};

				void Layout( gwen::Skin::Base* skin );
				void SplitLabel( const gwen::UnicodeString & text, gwen::Font* pFont, const DividedText & txt, int & x, int & y, int & lineheight );
				void CreateNewline( int & x, int & y, int & lineheight );
				void CreateLabel( const gwen::UnicodeString & text, const DividedText & txt, int & x, int & y, int & lineheight, bool NoSplit );
				void Rebuild();

				void OnBoundsChanged( gwen::Rect oldBounds );

				DividedText::List	m_TextBlocks;
				bool				m_bNeedsRebuild;
		};
	}
}
#endif
