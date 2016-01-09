/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#ifndef GWEN_CONTROLS_RESIZER_H
#define GWEN_CONTROLS_RESIZER_H

#include "gwen/Controls/Base.h"
#include "gwen/Gwen.h"
#include "gwen/Skin.h"
#include "gwen/Controls/Dragger.h"


namespace gwen
{
	namespace ControlsInternal
	{
		class GWEN_EXPORT Resizer : public Dragger
		{
			public:

				GWEN_CONTROL( Resizer, Dragger );

				virtual void OnMouseMoved( int x, int y, int deltaX, int deltaY );
				virtual void SetResizeDir( int dir );

				Event::Caller	onResize;

			protected:

				int		m_iResizeDir;

		};
	}
}
#endif
