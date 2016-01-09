#include "gwen/UnitTest/UnitTest.h"
#include "gwen/Controls/CrossSplitter.h"
#include "gwen/Controls/StatusBar.h"
#include "gwen/Controls/Button.h"

using namespace gwen;

class CrossSplitter : public GUnit
{
	public:

		GWEN_CONTROL_INLINE( CrossSplitter, GUnit )
		{
			Dock( Pos::Fill );
			m_bSplittersVisible = false;
			m_iCurZoom = 0;
			m_Splitter = new gwen::Controls::CrossSplitter( this );
			m_Splitter->SetPos( 0, 0 );
			m_Splitter->Dock( Pos::Fill );
			{
				gwen::Controls::Button* testButton =  new gwen::Controls::Button( m_Splitter );
				testButton->SetText( "TOPLEFT" );
				m_Splitter->SetPanel( 0, testButton );
			}
			{
				gwen::Controls::Button* testButton =  new gwen::Controls::Button( m_Splitter );
				testButton->SetText( "TOPRIGHT" );
				m_Splitter->SetPanel( 1, testButton );
			}
			{
				gwen::Controls::Button* testButton =  new gwen::Controls::Button( m_Splitter );
				testButton->SetText( "BOTTOMRIGHT" );
				m_Splitter->SetPanel( 2, testButton );
			}
			{
				gwen::Controls::Button* testButton =  new gwen::Controls::Button( m_Splitter );
				testButton->SetText( "BOTTOMLEFT" );
				m_Splitter->SetPanel( 3, testButton );
			}
			//Status bar to hold unit testing buttons
			gwen::Controls::StatusBar* pStatus = new gwen::Controls::StatusBar( this );
			pStatus->Dock( Pos::Bottom );
			{
				gwen::Controls::Button* pButton = new gwen::Controls::Button( pStatus );
				pButton->SetText( "Zoom" );
				pButton->onPress.Add( this, &CrossSplitter::ZoomTest );
				pStatus->AddControl( pButton, false );
			}
			{
				gwen::Controls::Button* pButton = new gwen::Controls::Button( pStatus );
				pButton->SetText( "UnZoom" );
				pButton->onPress.Add( this, &CrossSplitter::UnZoomTest );
				pStatus->AddControl( pButton, false );
			}
			{
				gwen::Controls::Button* pButton = new gwen::Controls::Button( pStatus );
				pButton->SetText( "CenterPanels" );
				pButton->onPress.Add( this, &CrossSplitter::CenterPanels );
				pStatus->AddControl( pButton, true );
			}
		}

		void ZoomTest( gwen::Controls::Base* pFromPanel )
		{
			m_Splitter->Zoom( m_iCurZoom );
			m_iCurZoom++;

			if ( m_iCurZoom == 4 )
			{ m_iCurZoom = 0; }
		}

		void UnZoomTest( gwen::Controls::Base* pFromPanel )
		{
			m_Splitter->UnZoom();
		}

		void CenterPanels( gwen::Controls::Base* pFromPanel )
		{
			m_Splitter->CenterPanels();
			m_Splitter->UnZoom();
		}

		void Layout( gwen::Skin::Base* skin ) {}

		bool m_bSplittersVisible;
		int	m_iCurZoom;
		Controls::CrossSplitter* m_Splitter;

};



DEFINE_UNIT_TEST( CrossSplitter, L"CrossSplitter" );