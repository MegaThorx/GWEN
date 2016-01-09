/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#ifndef GWEN_CONTROLS_PROPERTYTREE_H
#define GWEN_CONTROLS_PROPERTYTREE_H

#include "gwen/Controls/Base.h"
#include "gwen/Controls/Label.h"
#include "gwen/Gwen.h"
#include "gwen/Skin.h"
#include "gwen/Controls/TreeControl.h"
#include "gwen/Controls/Properties.h"


namespace gwen
{
	namespace Controls
	{
		class PropertyTreeNode : public TreeNode
		{
			public:

				GWEN_CONTROL_INLINE( PropertyTreeNode, TreeNode )
				{
					m_Title->SetTextColorOverride( GetSkin()->Colors.Properties.Title );
				}

				virtual void Render( Skin::Base* skin )
				{
					skin->DrawPropertyTreeNode( this, m_InnerPanel->X(), m_InnerPanel->Y() );
				}

		};

		class PropertyTree : public TreeControl
		{
			public:

				GWEN_CONTROL_INLINE( PropertyTree, TreeControl )
				{
				}

				Properties* Add( const TextObject & text );
				Properties* Find( const TextObject & text );
		};

	}
}
#endif
