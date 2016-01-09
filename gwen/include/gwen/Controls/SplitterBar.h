#pragma once
#ifndef GWEN_CONTROLS_SPLITTERBAR_H
#define GWEN_CONTROLS_SPLITTERBAR_H

#include "gwen/Gwen.h"
#include "gwen/Controls/Base.h"
#include "gwen/Controls/Dragger.h"

namespace gwen
{
	namespace Controls
	{
		class GWEN_EXPORT SplitterBar : public ControlsInternal::Dragger
		{
			public:

				GWEN_CONTROL( SplitterBar, ControlsInternal::Dragger );

				void Layout( Skin::Base* skin );
		};
	}
}
#endif
