/*
	GWEN
	Copyright (c) 2011 Facepunch Studios
	See license in Gwen.h
*/


#pragma once
#ifndef GWEN_UNITTEST_UNITTEST_H
#define GWEN_UNITTEST_UNITTEST_H

#include "gwen/Gwen.h"
#include "gwen/Align.h"
#include "gwen/Utility.h"
#include "gwen/Controls/WindowControl.h"
#include "gwen/Controls/TabControl.h"
#include "gwen/Controls/ListBox.h"
#include "gwen/Controls/DockBase.h"
#include "gwen/Controls/StatusBar.h"

class UnitTest;

class GUnit : public gwen::Controls::Base
{
	public:

		GWEN_CONTROL_INLINE( GUnit, gwen::Controls::Base )
		{
			m_pUnitTest = NULL;
		}

		void SetUnitTest( UnitTest* u ) { m_pUnitTest = u; }

		void UnitPrint( gwen::UnicodeString str );
		void UnitPrint( gwen::String str );

		void Layout( gwen::Skin::Base* skin )
		{
			if ( GetDock() != gwen::Pos::None ) { return; }

			SizeToChildren( true, true );
		}


		UnitTest* m_pUnitTest;
};

class UnitTest : public gwen::Controls::DockBase
{
	public:

		GWEN_CONTROL( UnitTest, gwen::Controls::DockBase );

		void PrintText( const gwen::UnicodeString & str );

		void Render( gwen::Skin::Base* skin );


	private:

		void OnCategorySelect( gwen::Event::Info info );

		gwen::Controls::TabControl*	m_TabControl;
		gwen::Controls::ListBox*	m_TextOutput;
		gwen::Controls::StatusBar*	m_StatusBar;
		unsigned int				m_iFrames;
		float						m_fLastSecond;

		gwen::Controls::Base*		m_pLastControl;

};

#define DEFINE_UNIT_TEST( name, displayname ) GUnit* RegisterUnitTest_##name( gwen::Controls::Base* tab ){ return new name( tab ); }
#endif
