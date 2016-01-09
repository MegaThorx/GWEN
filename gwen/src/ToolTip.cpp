/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/


#include "gwen/ToolTip.h"
#include "gwen/Utility.h"

using namespace gwen;
using namespace gwen::Controls;

namespace ToolTip
{
	Base* g_ToolTip = NULL;

	GWEN_EXPORT bool TooltipActive()
	{
		return g_ToolTip != NULL;
	}

	void Enable( Controls::Base* pControl )
	{
		if ( !pControl->GetToolTip() )
		{ return; }

		g_ToolTip = pControl;
	}

	void Disable( Controls::Base* pControl )
	{
		if ( g_ToolTip == pControl )
		{
			g_ToolTip = NULL;
		}
	}

	void RenderToolTip( Skin::Base* skin )
	{
		if ( !g_ToolTip ) { return; }

		gwen::Renderer::Base* render = skin->GetRender();
		gwen::Point pOldRenderOffset = render->GetRenderOffset();
		gwen::Point MousePos = Input::GetMousePosition();
		gwen::Rect Bounds = g_ToolTip->GetToolTip()->GetBounds();
		gwen::Rect rOffset = gwen::Rect( MousePos.x - Bounds.w * 0.5f, MousePos.y - Bounds.h - 10, Bounds.w, Bounds.h );
		rOffset = Utility::ClampRectToRect( rOffset, g_ToolTip->GetCanvas()->GetBounds() );
		//Calculate offset on screen bounds
		render->AddRenderOffset( rOffset );
		render->EndClip();
		skin->DrawToolTip( g_ToolTip->GetToolTip() );
		g_ToolTip->GetToolTip()->DoRender( skin );
		render->SetRenderOffset( pOldRenderOffset );
	}

	void ControlDeleted( Controls::Base* pControl )
	{
		Disable( pControl );
	}
}
