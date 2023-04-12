#pragma once

#ifdef GC_PLATFORM_WINDOWS

	extern Gltchium::Application* Gltchium::CreateApplication();

	int main(int argc, char** argv) {
		Gltchium::Print();

		Gltchium::Log::Init();
		GC_CORE_INFO("Initializing Engine...");
		GC_INFO("Initializing Client...");

		auto app = Gltchium::CreateApplication();
		app->Run();
		delete app;
	}
#else
	#error Gltchium only supports Windows!
#endif
