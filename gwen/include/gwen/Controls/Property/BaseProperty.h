/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#ifndef GWEN_CONTROLS_PROPERTY_BASEPROPERTY_H
#define GWEN_CONTROLS_PROPERTY_BASEPROPERTY_H

#include "gwen/Controls/Base.h"
#include "gwen/Gwen.h"
#include "gwen/Skin.h"
#include "gwen/Utility.h"


namespace gwen
{
	namespace Controls
	{
		namespace Property
		{
			class GWEN_EXPORT Base : public gwen::Controls::Base
			{
				public:

					GWEN_CONTROL_INLINE( Base, gwen::Controls::Base )
					{
						SetHeight( 17 );
					}

					virtual TextObject GetPropertyValue() = 0;

					virtual void SetPropertyValue( const TextObject & v, bool bFireChangeEvents = false ) = 0;

					virtual bool IsEditing() = 0;

					virtual void DoChanged()
					{
						Event::Information info;
						info.String = GetPropertyValue();
						onChange.Call( this, info );
					}

					void OnPropertyValueChanged( gwen::Controls::Base* /*control*/ )
					{
						DoChanged();
					}

					Event::Caller	onChange;
			};
		}
	}
}
#endif
