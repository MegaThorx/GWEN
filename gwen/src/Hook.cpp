/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/


#include "gwen/Hook.h"

#ifdef GWEN_HOOKSYSTEM

using namespace gwen;
using namespace gwen::Hook;

std::list<BaseHook*>	g_HookList;

void gwen::Hook::AddHook( BaseHook* pHook )
{
	g_HookList.push_back( pHook );
}

void gwen::Hook::RemoveHook( BaseHook* pHook )
{
	g_HookList.remove( pHook );
}

HookList & gwen::Hook::GetHookList()
{
	return g_HookList;
}

#endif