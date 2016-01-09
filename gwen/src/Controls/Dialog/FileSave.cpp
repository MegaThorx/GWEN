/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#include "gwen/Gwen.h"
#include "gwen/Platform.h"
#include "gwen/Controls/Dialogs/FileSave.h"

using namespace gwen;
using namespace gwen::Dialogs;

void gwen::Dialogs::FileSaveEx( bool bUseSystem, const String & Name, const String & StartPath, const String & Extension, gwen::Event::Handler* pHandler, gwen::Event::Handler::FunctionWithInformation fnCallback )
{
	if ( bUseSystem && gwen::Platform::FileSave( Name, StartPath, Extension, pHandler, fnCallback ) )
	{
		return;
	}

	//
	// TODO: SHOW GWEN FILE SELECTION DIALOG
	//
}