/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#include "gwen/Gwen.h"
#include "gwen/Platform.h"
#include "gwen/Controls/Dialogs/FolderOpen.h"

using namespace gwen;
using namespace gwen::Dialogs;

void gwen::Dialogs::FolderOpenEx( bool bUseSystem, const String & Name, const String & StartPath, gwen::Event::Handler* pHandler, gwen::Event::Handler::FunctionWithInformation fnCallback )
{
	if ( bUseSystem && gwen::Platform::FolderOpen( Name, StartPath, pHandler, fnCallback ) )
	{
		return;
	}

	//
	// TODO: SHOW GWEN FOLDER SELECTION DIALOG
	//
}