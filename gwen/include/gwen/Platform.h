/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#ifndef GWEN_PLATFORM_H
#define GWEN_PLATFORM_H

#include "gwen/Structures.h"
#include "gwen/Events.h"

namespace gwen
{
	namespace Platform
	{
		//
		// Do nothing for this many milliseconds
		//
		GWEN_EXPORT void Sleep( unsigned int iMS );

		//
		// Set the system cursor to iCursor
		// Cursors are defined in Structures.h
		//
		GWEN_EXPORT void SetCursor( unsigned char iCursor );

		//
		//
		//
		GWEN_EXPORT void GetCursorPos( gwen::Point & p );
		GWEN_EXPORT void GetDesktopSize( int & w, int & h );

		//
		// Used by copy/paste
		//
		GWEN_EXPORT UnicodeString GetClipboardText();
		GWEN_EXPORT bool SetClipboardText( const UnicodeString & str );

		//
		// Needed for things like double click
		//
		GWEN_EXPORT float GetTimeInSeconds();

		//
		// System Dialogs ( Can return false if unhandled )
		//
		GWEN_EXPORT bool FileOpen( const String & Name, const String & StartPath, const String & Extension, gwen::Event::Handler* pHandler, Event::Handler::FunctionWithInformation fnCallback );
		GWEN_EXPORT bool FileSave( const String & Name, const String & StartPath, const String & Extension, gwen::Event::Handler* pHandler, Event::Handler::FunctionWithInformation fnCallback );
		GWEN_EXPORT bool FolderOpen( const String & Name, const String & StartPath, gwen::Event::Handler* pHandler, Event::Handler::FunctionWithInformation fnCallback );


		//
		// Window Creation
		//
		GWEN_EXPORT void* CreatePlatformWindow( int x, int y, int w, int h, const gwen::String & strWindowTitle );
		GWEN_EXPORT void DestroyPlatformWindow( void* pPtr );
		GWEN_EXPORT void SetBoundsPlatformWindow( void* pPtr, int x, int y, int w, int h );
		GWEN_EXPORT void MessagePump( void* pWindow, gwen::Controls::Canvas* ptarget );
		GWEN_EXPORT bool HasFocusPlatformWindow( void* pPtr );
		GWEN_EXPORT void SetWindowMaximized( void* pPtr, bool bMaximized, gwen::Point & pNewPos, gwen::Point & pNewSize );
		GWEN_EXPORT void SetWindowMinimized( void* pPtr, bool bMinimized );
	}

}
#endif
