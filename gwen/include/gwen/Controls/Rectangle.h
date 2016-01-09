/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#ifndef GWEN_CONTROLS_RECTANGLE_H
#define GWEN_CONTROLS_RECTANGLE_H

#include "gwen/Controls/Base.h"
#include "gwen/Controls/Label.h"
#include "gwen/Gwen.h"
#include "gwen/Skin.h"


namespace gwen
{
	namespace Controls
	{

		class GWEN_EXPORT Rectangle : public Controls::Base
		{
			public:

				GWEN_CONTROL( Rectangle, Controls::Base );

				virtual void Render( Skin::Base* skin );

				const gwen::Color & GetColor() { return m_Color; }
				void SetColor( const gwen::Color & col ) { m_Color = col; }

			protected:

				gwen::Color		m_Color;

		};
	}
}
#endif
