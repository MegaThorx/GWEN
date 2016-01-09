#pragma once
#ifndef GWEN_WINDOW_PROVIDER_H
#define GWEN_WINDOW_PROVIDER_H

namespace gwen
{
	class WindowProvider
	{
		public:

			virtual void* GetWindow() = 0;
	};

}

#endif
