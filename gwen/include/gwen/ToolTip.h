/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/


#pragma once
#ifndef GWEN_TOOLTIP_H
#define GWEN_TOOLTIP_H

#include "gwen/Controls/Base.h"
#include "gwen/Gwen.h"
#include "gwen/Skin.h"

using namespace gwen;
using namespace gwen::Controls;

namespace ToolTip
{
	GWEN_EXPORT bool TooltipActive();

	GWEN_EXPORT void Enable( Controls::Base* pControl );
	GWEN_EXPORT void Disable( Controls::Base* pControl );

	GWEN_EXPORT void ControlDeleted( Controls::Base* pControl );

	GWEN_EXPORT void RenderToolTip( Skin::Base* skin );
}

#endif
