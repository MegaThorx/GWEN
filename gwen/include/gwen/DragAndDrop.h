/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#ifndef GWEN_DRAGANDDROP_H
#define GWEN_DRAGANDDROP_H

#include <sstream>

#include "gwen/Skin.h"
#include "gwen/Structures.h"

namespace gwen
{
	namespace DragAndDrop
	{
		extern GWEN_EXPORT Package*	CurrentPackage;
		extern GWEN_EXPORT gwen::Controls::Base*	SourceControl;
		extern GWEN_EXPORT gwen::Controls::Base*	HoveredControl;

		bool GWEN_EXPORT Start( gwen::Controls::Base* pControl, Package* pPackage );

		bool GWEN_EXPORT OnMouseButton( gwen::Controls::Base* pHoveredControl, int x, int y, bool bDown );
		void GWEN_EXPORT OnMouseMoved( gwen::Controls::Base* pHoveredControl, int x, int y );

		void GWEN_EXPORT RenderOverlay( gwen::Controls::Canvas* pCanvas, Skin::Base* skin );

		void GWEN_EXPORT ControlDeleted( gwen::Controls::Base* pControl );
	}

}
#endif
