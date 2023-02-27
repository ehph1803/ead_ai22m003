#pragma once

#include "Core.h"

namespace GEE {
	class GEE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}
