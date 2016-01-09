/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#ifndef GWEN_CONTROLS_RADIOBOTTONCONTROLLER_H
#define GWEN_CONTROLS_RADIOBOTTONCONTROLLER_H

#include "gwen/Controls/Base.h"
#include "gwen/Controls/Label.h"
#include "gwen/Controls/RadioButton.h"


namespace gwen
{
	namespace Controls
	{

		class GWEN_EXPORT RadioButtonController : public Base
		{
			public:

				GWEN_CONTROL( RadioButtonController, Base );

				virtual void Render( Skin::Base* /*skin*/ ) {};
				virtual void OnRadioClicked( Base* pFromPanel );

				virtual void OnChange();

				virtual LabeledRadioButton* AddOption( const gwen::String & strText, const gwen::String & strOptionName = "" );
				virtual LabeledRadioButton* AddOption( const gwen::UnicodeString & strText, const gwen::String & strOptionName = "" );

				virtual LabeledRadioButton*	GetSelected() { return m_Selected; }

				virtual const gwen::String & GetSelectedName() { return m_Selected->GetName(); }
				virtual const TextObject & GetSelectedLabel() { return m_Selected->GetLabel()->GetText(); }

				Event::Caller		onSelectionChange;

			private:

				LabeledRadioButton* m_Selected;
		};
	}
}
#endif
