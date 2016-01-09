/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#ifndef GWEN_TEXTURE_H
#define GWEN_TEXTURE_H

#include <string>

#include "gwen/BaseRender.h"

namespace gwen
{
	//
	// Texture
	//
	struct Texture
	{
		typedef std::list<Texture*>		List;

		TextObject	name;
		void*	data;
		bool	failed;
		int		width;
		int		height;

		Texture()
		{
			data = NULL;
			width = 4;
			height = 4;
			failed = false;
		}

		~Texture()
		{
		}

		void Load( const TextObject & str, gwen::Renderer::Base* render )
		{
			name = str;
			gwen::Debug::AssertCheck( render != NULL, "No renderer!" );
			render->LoadTexture( this );
		}

		void Release( gwen::Renderer::Base* render )
		{
			render->FreeTexture( this );
		}

		bool FailedToLoad() const
		{
			return failed;
		}
	};

}
#endif
