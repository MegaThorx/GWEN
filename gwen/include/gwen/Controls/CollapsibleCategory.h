/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#ifndef GWEN_CONTROLS_COLLAPSIBLECATEGORY_H
#define GWEN_CONTROLS_COLLAPSIBLECATEGORY_H

#include "gwen/Controls/Base.h"
#include "gwen/Controls/Button.h"
#include "gwen/Gwen.h"
#include "gwen/Skin.h"


namespace gwen
{
	namespace Controls
	{
		class CollapsibleList;

		class GWEN_EXPORT CollapsibleCategory : public gwen::Controls::Base
		{
			public:

				GWEN_CONTROL( CollapsibleCategory, gwen::Controls::Base );

				virtual void Render( Skin::Base* skin );

				virtual void SetText( const TextObject & text );

				virtual Button* Add( const TextObject & name );

				virtual void PostLayout( Skin::Base* /*skin*/ );

				virtual void SetList( Controls::CollapsibleList* p ) { m_pList = p; }

				virtual void UnselectAll();
				virtual Button* GetSelected();

			public:

				gwen::Event::Caller	onSelection;

			protected:

				virtual void OnSelection( Controls::Base* control );

				Controls::Button*			m_pButton;
				Controls::CollapsibleList*	m_pList;
		};

	}
}
#endif
