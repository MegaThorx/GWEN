/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#ifndef GWEN_CONTROLS_COLLAPSIBLELIST_H
#define GWEN_CONTROLS_COLLAPSIBLELIST_H

#include "gwen/Controls/Base.h"
#include "gwen/Controls/Button.h"
#include "gwen/Controls/ScrollControl.h"
#include "gwen/Gwen.h"
#include "gwen/Skin.h"
#include "gwen/Controls/CollapsibleCategory.h"


namespace gwen
{
	namespace Controls
	{
		class GWEN_EXPORT CollapsibleList : public gwen::Controls::ScrollControl
		{
			public:

				gwen::Event::Caller	onSelection;

			public:

				GWEN_CONTROL_INLINE( CollapsibleList, gwen::Controls::ScrollControl )
				{
					SetScroll( false, true );
					SetAutoHideBars( true );
				}

				virtual void Add( gwen::Controls::CollapsibleCategory* pCategory )
				{
					pCategory->SetParent( this );
					pCategory->Dock( Pos::Top );
					pCategory->SetMargin( Margin( 1, 0, 1, 1 ) );
					pCategory->SetList( this );
					pCategory->onSelection.Add( this, &ThisClass::OnSelectionEvent );
				}

				virtual gwen::Controls::CollapsibleCategory* Add( const TextObject & name )
				{
					gwen::Controls::CollapsibleCategory* pCategory = new CollapsibleCategory( this );
					pCategory->SetText( name );
					Add( pCategory );
					return pCategory;
				}

				virtual void Render( Skin::Base* skin )
				{
					skin->DrawCategoryHolder( this );
				}

				virtual void UnselectAll()
				{
					Base::List & children = GetChildren();

					for ( Base::List::iterator iter = children.begin(); iter != children.end(); ++iter )
					{
						gwen::Controls::CollapsibleCategory* pChild = gwen_cast<gwen::Controls::CollapsibleCategory> ( *iter );

						if ( !pChild ) { continue; }

						pChild->UnselectAll();
					}
				}

				virtual gwen::Controls::Button* GetSelected()
				{
					Base::List & children = GetChildren();

					for ( Base::List::iterator iter = children.begin(); iter != children.end(); ++iter )
					{
						gwen::Controls::CollapsibleCategory* pChild = gwen_cast<gwen::Controls::CollapsibleCategory> ( *iter );

						if ( !pChild ) { continue; }

						gwen::Controls::Button* pSelected = pChild->GetSelected();

						if ( pSelected ) { return pSelected; }
					}

					return NULL;
				}

			protected:

				virtual void OnSelection( gwen::Controls::CollapsibleCategory* pControl, gwen::Controls::Button* pSelected )
				{
					onSelection.Call( this );
				}

				void OnSelectionEvent( Controls::Base* pControl )
				{
					gwen::Controls::CollapsibleCategory* pChild = gwen_cast<gwen::Controls::CollapsibleCategory> ( pControl );

					if ( !pChild ) { return; }

					OnSelection( pChild, pChild->GetSelected() );
				}
		};

	}
}
#endif
