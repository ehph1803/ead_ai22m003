#pragma once

#ifdef GEE_PLATFORM_WINDOWS

extern GEE::Application* GEE::CreateApplication();
	
int main(int argc, char** args) {
	GEE::Log::Init();
	GEE_CORE_WARN("Initialized log!");
	int a = 5;
	GEE_INFO("Hello! Var={0}", a);


	auto app = GEE::CreateApplication();
	app->Run();
	delete app;
}

#endif