/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#ifndef GWEN_CONTROLS_TABTITLEBAR_H
#define GWEN_CONTROLS_TABTITLEBAR_H

#include "gwen/Controls/Base.h"
#include "gwen/Controls/Label.h"
#include "gwen/Controls/TabButton.h"
#include "gwen/DragAndDrop.h"
#include "gwen/Skin.h"

namespace gwen
{
	namespace Controls
	{
		class GWEN_EXPORT TabTitleBar : public Label
		{
			public:

				GWEN_CONTROL_INLINE( TabTitleBar, Label )
				{
					SetMouseInputEnabled( true );
					SetTextPadding( gwen::Padding( 5, 2, 5, 2 ) );
					SetPadding( gwen::Padding( 1, 2, 1, 2 ) );
					DragAndDrop_SetPackage( true, "TabWindowMove" );
				}

				void Render( Skin::Base* skin )
				{
					skin->DrawTabTitleBar( this );
				}

				void DragAndDrop_StartDragging( gwen::DragAndDrop::Package* pPackage, int x, int y )
				{
					DragAndDrop::SourceControl = GetParent();
					DragAndDrop::SourceControl->DragAndDrop_StartDragging( pPackage, x, y );
				}

				void UpdateFromTab( TabButton* pButton )
				{
					SetText( pButton->GetText() );
					SizeToContents();
				}

			private:

		};
	}
}
#endif
