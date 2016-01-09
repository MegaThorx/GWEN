/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#ifndef GWEN_CONTROLS_DRAGGER_H
#define GWEN_CONTROLS_DRAGGER_H

#include "gwen/Controls/Base.h"
#include "gwen/Gwen.h"
#include "gwen/Skin.h"


namespace gwen
{
	namespace ControlsInternal
	{
		class GWEN_EXPORT Dragger : public Controls::Base
		{
			public:

				GWEN_CONTROL( Dragger, Controls::Base );

				virtual void OnMouseMoved( int x, int y, int deltaX, int deltaY );

				virtual void OnMouseClickLeft( int x, int y, bool bDown );
				virtual void Render( Skin::Base* skin );

				virtual void SetTarget( Controls::Base* pBase ) { m_pTarget = pBase; }
				virtual bool IsDepressed() { return m_bDepressed; }

				virtual void SetDoMove( bool b ) { m_bDoMove = b; }

				virtual void OnMouseDoubleClickLeft( int x, int y );

				gwen::Event::Caller	onDragged;
				gwen::Event::Caller	onDragStart;

				gwen::Event::Caller	onDoubleClickLeft;

			protected:

				bool				m_bDepressed;
				gwen::Point			m_HoldPos;
				Controls::Base*		m_pTarget;
				bool				m_bDoMove;
		};
	}
}
#endif
