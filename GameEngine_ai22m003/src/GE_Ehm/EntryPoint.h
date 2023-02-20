#pragma once

#ifdef GE_PLATFORM_WINDOWS

extern GE_Ehm::Application* GE_Ehm::CreateApplication();
	
int main(int argc, char** args) {
	auto app = GE_Ehm::CreateApplication();
	app->Run();
	delete app;
}

#endif