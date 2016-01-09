
#pragma once

#include "gwen/Gwen.h"
#include "gwen/Controls.h"
#include "gwen/Util/ControlFactory.h"

using namespace gwen;

namespace gwen
{
	namespace ImportExport
	{
		class Base
		{
			public:

				Base();

				virtual gwen::String Name() = 0;

				virtual bool CanImport() = 0;
				virtual void Import( gwen::Controls::Base* pRoot, const gwen::String & strFilename ) = 0;

				virtual bool CanExport() = 0;
				virtual void Export( gwen::Controls::Base* pRoot, const gwen::String & strFilename ) = 0;

			public:

				typedef std::list<ImportExport::Base*> List;

			protected:

		};

		ImportExport::Base::List & GetList();
		ImportExport::Base* Find( gwen::String strName );

		namespace Tools
		{
			ControlList GetExportableChildren( gwen::Controls::Base* pRoot );
		}
	}
}

#define GWEN_IMPORTEXPORT( name )\
void GWENIMPORTEXPORT_##name()\
{\
	static name my_instance;\
}

#define DECLARE_GWEN_IMPORTEXPORT( name )\
void GWENIMPORTEXPORT_##name();\
GWENIMPORTEXPORT_##name();