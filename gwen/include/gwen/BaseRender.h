/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#ifndef GWEN_BASERENDER_H
#define GWEN_BASERENDER_H

#include "gwen/Structures.h"

namespace gwen
{
	struct Font;
	struct Texture;
	class WindowProvider;

	namespace Renderer
	{
		class Base;

		class ICacheToTexture
		{
			public:

				virtual ~ICacheToTexture() {}
				virtual void Initialize() = 0;
				virtual void ShutDown() = 0;
				virtual void SetupCacheTexture( gwen::Controls::Base* control ) = 0;
				virtual void FinishCacheTexture( gwen::Controls::Base* control ) = 0;
				virtual void DrawCachedControlTexture( gwen::Controls::Base* control ) = 0;
				virtual void CreateControlCacheTexture( gwen::Controls::Base* control ) = 0;
				virtual void UpdateControlCacheTexture( gwen::Controls::Base* control ) = 0;
				virtual void SetRenderer( gwen::Renderer::Base* renderer ) = 0;

		};

		class GWEN_EXPORT Base
		{
			public:

				Base();
				virtual ~Base();

				virtual void Init() {};

				virtual void Begin() {};
				virtual void End() {};

				virtual void SetDrawColor( Color color ) {};

				virtual void DrawFilledRect( gwen::Rect rect ) {};;

				virtual void StartClip() {};
				virtual void EndClip() {};

				virtual void LoadTexture( gwen::Texture* pTexture ) {};
				virtual void FreeTexture( gwen::Texture* pTexture ) {};
				virtual void DrawTexturedRect( gwen::Texture* pTexture, gwen::Rect pTargetRect, float u1 = 0.0f, float v1 = 0.0f, float u2 = 1.0f, float v2 = 1.0f ) {};
				virtual void DrawMissingImage( gwen::Rect pTargetRect );
				virtual gwen::Color PixelColour( gwen::Texture* pTexture, unsigned int x, unsigned int y, const gwen::Color & col_default = gwen::Color( 255, 255, 255, 255 ) ) { return col_default; }

				virtual ICacheToTexture* GetCTT() { return NULL; }

				virtual void LoadFont( gwen::Font* pFont ) {};
				virtual void FreeFont( gwen::Font* pFont ) {};
				virtual void RenderText( gwen::Font* pFont, gwen::Point pos, const gwen::UnicodeString & text );
				virtual gwen::Point MeasureText( gwen::Font* pFont, const gwen::UnicodeString & text );

				//
				// No need to implement these functions in your derived class, but if
				// you can do them faster than the default implementation it's a good idea to.
				//
				virtual void DrawLinedRect( gwen::Rect rect );
				virtual void DrawPixel( int x, int y );
				virtual void DrawShavedCornerRect( gwen::Rect rect, bool bSlight = false );
				virtual gwen::Point MeasureText( gwen::Font* pFont, const gwen::String & text );
				virtual void RenderText( gwen::Font* pFont, gwen::Point pos, const gwen::String & text );

			public:

				//
				// Translate a panel's local drawing coordinate
				//  into view space, taking Offset's into account.
				//
				void Translate( int & x, int & y );
				void Translate( gwen::Rect & rect );

				//
				// Set the rendering offset. You shouldn't have to
				// touch these, ever.
				//
				void SetRenderOffset( const gwen::Point & offset ) { m_RenderOffset = offset; }
				void AddRenderOffset( const gwen::Rect & offset ) { m_RenderOffset.x += offset.x; m_RenderOffset.y += offset.y; }
				const gwen::Point & GetRenderOffset() const { return m_RenderOffset; }

			private:

				gwen::Point m_RenderOffset;

			public:

				void SetClipRegion( gwen::Rect rect );
				void AddClipRegion( gwen::Rect rect );
				bool ClipRegionVisible();
				const gwen::Rect & ClipRegion() const;

			private:

				gwen::Rect m_rectClipRegion;
				ICacheToTexture* m_RTT;

			public:

				void SetScale( float fScale ) { m_fScale = fScale; }
				float Scale() const { return m_fScale; }

				float m_fScale;


			public:

				//
				// Self Initialization, shutdown
				//

				virtual bool InitializeContext( gwen::WindowProvider* pWindow ) { return false; }
				virtual bool ShutdownContext( gwen::WindowProvider* pWindow ) { return false; }
				virtual bool ResizedContext( gwen::WindowProvider* pWindow, int w, int h ) { return false; }

				virtual bool BeginContext( gwen::WindowProvider* pWindow ) { return false; }
				virtual bool EndContext( gwen::WindowProvider* pWindow ) { return false; }
				virtual bool PresentContext( gwen::WindowProvider* pWindow ) { return false; }



		};
	}
}
#endif
