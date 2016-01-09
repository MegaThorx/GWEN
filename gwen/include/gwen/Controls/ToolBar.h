/*
	GWEN
	Copyright (c) 2011 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#ifndef GWEN_CONTROLS_TOOLBAR_H
#define GWEN_CONTROLS_TOOLBAR_H

#include "gwen/BaseRender.h"
#include "gwen/Controls/Base.h"
#include "gwen/Skin.h"

namespace gwen
{
	namespace Controls
	{

		class ToolBarButton : public gwen::Controls::Button
		{
				GWEN_CONTROL_INLINE( ToolBarButton, gwen::Controls::Button )
				{
					SetSize( 20, 20 );
					Dock( Pos::Left );
				}

				virtual bool ShouldDrawBackground()
				{
					return IsHovered();
				}

		};

		class ToolBarStrip : public Base
		{
				GWEN_CONTROL_INLINE( ToolBarStrip, Base )
				{
					SetSize( 25, 25 );
					SetPadding( Padding( 2, 2, 2, 2 ) );
				}

				virtual void Render( Skin::Base* skin )
				{
					skin->DrawMenuStrip( this );
				}

				virtual ToolBarButton* Add( const TextObject & Text, const TextObject & Icon )
				{
					ToolBarButton* pButton = new ToolBarButton( this );
					pButton->SetToolTip( Text );
					pButton->SetImage( Icon );
					return pButton;
				}

		};


	}

}
#endif
