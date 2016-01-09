/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#ifndef GWEN_CONTROLS_FIELDLABEL_H
#define GWEN_CONTROLS_FIELDLABEL_H

#include "gwen/BaseRender.h"
#include "gwen/Controls/Label.h"

namespace gwen
{
	namespace Controls
	{
		class GWEN_EXPORT FieldLabel : public Controls::Label
		{
			public:

				static inline FieldLabel* Setup( Controls::Base* pControl, const gwen::TextObject & text )
				{
					FieldLabel* plbl = new FieldLabel( pControl->GetParent() );
					plbl->SetText( text );
					plbl->SetSize( pControl->Width(), pControl->Height() );
					plbl->Dock( pControl->GetDock() );
					plbl->SetField( pControl );
					return plbl;
				}

			public:

				GWEN_CONTROL_INLINE( FieldLabel, Controls::Label )
				{
					m_pField = NULL;
					SetMargin( Margin( 0, 1, 0, 1 ) );
					SetAlignment( Pos::CenterV | Pos::Left );
				}

				void SetField( Controls::Base* pField )
				{
					pField->SetParent( this );
					pField->Dock( Pos::Right );
					m_pField = pField;
				}

				void Layout( gwen::Skin::Base* pskin )
				{
					m_pField->SetWidth( Width() - 70 );
					BaseClass::Layout( pskin );
				}

			protected:

				Controls::Base* m_pField;

		};
	}
}

#endif
