#include "Application.h"
#include "GEE/Events/ApplicationEvent.h"
#include "GEE/Log.h"

namespace GEE {
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run() {
		WindowResizeEvent e(1200, 720);

		if(e.IsInCategory(EventCategoryApplication))
			GEE_INFO(e);
		if (e.IsInCategory(EventCategoryInput))
			GEE_INFO(e);


		while (true);
	}
}