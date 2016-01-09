/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#ifndef GWEN_CONTROLS_RESIZABLECONTROL_H
#define GWEN_CONTROLS_RESIZABLECONTROL_H

#include "gwen/Controls/Base.h"
#include "gwen/Controls/Label.h"
#include "gwen/Controls/Button.h"
#include "gwen/Controls/Dragger.h"
#include "gwen/Controls/Label.h"
#include "gwen/Controls/Resizer.h"
#include "gwen/Gwen.h"
#include "gwen/Skin.h"

namespace gwen
{
	namespace Controls
	{

		class GWEN_EXPORT ResizableControl : public Base
		{
			public:

				GWEN_CONTROL( ResizableControl, Base );

				virtual void SetClampMovement( bool shouldClamp ) { m_bClampMovement = shouldClamp; }
				virtual bool GetClampMovement() { return m_bClampMovement; }

				virtual void SetMinimumSize( const gwen::Point & minSize ) { m_MinimumSize = minSize; }
				virtual gwen::Point GetMinimumSize() { return m_MinimumSize; }

				virtual void DisableResizing();

				virtual bool SetBounds( int x, int y, int w, int h );

				virtual void OnResized() {};

				Event::Caller	onResize;

				virtual ControlsInternal::Resizer* GetResizer( int iResizer ) { return m_Resizer[iResizer]; }

			protected:

				void OnResizedInternal( Controls::Base* pControl );

				gwen::Point m_MinimumSize;
				bool m_bClampMovement;
				bool m_bResizable;

				ControlsInternal::Resizer* m_Resizer[10];


		};
	}
}
#endif
