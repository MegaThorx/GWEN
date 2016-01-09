#pragma once
#ifndef GWEN_CONTROLS_DIALOGS_FILEOPEN_H
#define GWEN_CONTROLS_DIALOGS_FILEOPEN_H

#include "gwen/Gwen.h"

namespace gwen
{
	namespace Dialogs
	{
		// Usage:
		//
		// gwen::Dialogs::FileOpen( true, "Open Map", "C:\my\folder\", "My Map Format|*.bmf", this, &MyClass::OpenFilename );
		//

		//
		// The REAL function.
		// If bUseSystem is used, it may use the system's modal dialog - which
		// will steal focus and pause the rest of GWEN until it's continued.
		//
		void GWEN_EXPORT FileOpenEx( bool bUseSystem, const String & Name, const String & StartPath, const String & Extension, gwen::Event::Handler* pHandler = NULL, gwen::Event::Handler::FunctionWithInformation fnCallback = NULL );

		//
		// Templated function simply to avoid having to manually cast the callback function.
		//
		template< typename A>
		void FileOpen( bool bUseSystem, const String & Name, const String & StartPath, const String & Extension, gwen::Event::Handler* pHandler = NULL, A fnCallback = NULL )
		{
			FileOpenEx( bUseSystem, Name, StartPath, Extension, pHandler, static_cast<gwen::Event::Handler::FunctionWithInformation>( fnCallback ) );
		}


	}
}
#endif
