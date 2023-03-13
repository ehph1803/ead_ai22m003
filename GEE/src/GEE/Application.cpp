#include "geepch.h"
#include "Application.h"

#include "GEE/Events/ApplicationEvent.h"

#include <GLFW/glfw3.h>

namespace GEE {
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}

	void Application::Run() {
		WindowResizeEvent e(1200, 720);

		while (true) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}