/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#ifndef GWEN_CONTROLS_HIGHLIGHT_H
#define GWEN_CONTROLS_HIGHLIGHT_H

#include "gwen/BaseRender.h"
#include "gwen/Controls/Base.h"
#include "gwen/Skin.h"

namespace gwen
{
	namespace ControlsInternal
	{
		class GWEN_EXPORT Highlight : public Controls::Base
		{
			public:

				GWEN_CONTROL_INLINE( Highlight, Controls::Base )
				{
				}

				void Render( Skin::Base* skin )
				{
					skin->DrawHighlight( this );
				}
		};
	}

}
#endif
