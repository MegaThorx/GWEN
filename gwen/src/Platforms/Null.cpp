/*
	GWEN
	Copyright (c) 2012 Facepunch Studios
	See license in Gwen.h
*/

#include "gwen/Macros.h"
#include "gwen/Platform.h"

#if !defined(_WIN32) && !defined(GWEN_ALLEGRO_PLATFORM)

#include <time.h>

static gwen::UnicodeString gs_ClipboardEmulator;

void gwen::Platform::Sleep( unsigned int iMS )
{
	// TODO.
}

void gwen::Platform::SetCursor( unsigned char iCursor )
{
	// No platform independent way to do this
}

gwen::UnicodeString gwen::Platform::GetClipboardText()
{
	return gs_ClipboardEmulator;
}

bool gwen::Platform::SetClipboardText( const gwen::UnicodeString & str )
{
	gs_ClipboardEmulator = str;
	return true;
}

float gwen::Platform::GetTimeInSeconds()
{
	float fSeconds = ( float ) clock() / ( float ) CLOCKS_PER_SEC;
	return fSeconds;
}

bool gwen::Platform::FileOpen( const String & Name, const String & StartPath, const String & Extension, gwen::Event::Handler* pHandler, Event::Handler::FunctionWithInformation fnCallback )
{
	// No platform independent way to do this.
	// Ideally you would open a system dialog here
	return false;
}

bool gwen::Platform::FileSave( const String & Name, const String & StartPath, const String & Extension, gwen::Event::Handler* pHandler, gwen::Event::Handler::FunctionWithInformation fnCallback )
{
	// No platform independent way to do this.
	// Ideally you would open a system dialog here
	return false;
}

bool gwen::Platform::FolderOpen( const String & Name, const String & StartPath, gwen::Event::Handler* pHandler, Event::Handler::FunctionWithInformation fnCallback )
{
	return false;
}

void* gwen::Platform::CreatePlatformWindow( int x, int y, int w, int h, const gwen::String & strWindowTitle )
{
	return NULL;
}

void gwen::Platform::DestroyPlatformWindow( void* pPtr )
{
}

void gwen::Platform::MessagePump( void* pWindow, gwen::Controls::Canvas* ptarget )
{
}

void gwen::Platform::SetBoundsPlatformWindow( void* pPtr, int x, int y, int w, int h )
{
}

void gwen::Platform::SetWindowMaximized( void* pPtr, bool bMax, gwen::Point & pNewPos, gwen::Point & pNewSize )
{
}

void gwen::Platform::SetWindowMinimized( void* pPtr, bool bMinimized )
{
}

bool gwen::Platform::HasFocusPlatformWindow( void* pPtr )
{
	return true;
}

void gwen::Platform::GetDesktopSize( int & w, int & h )
{
	w = 1024;
	h = 768;
}

void gwen::Platform::GetCursorPos( gwen::Point & po )
{
}

#endif // ndef WIN32