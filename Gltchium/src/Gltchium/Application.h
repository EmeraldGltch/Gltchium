#pragma once

#include "Core.h";

namespace Gltchium {
	class GLTCHIUM_API Application {
		public:
			Application();
			virtual ~Application();

			void Run();
	};

	__declspec(dllexport) void Print();

	// DEFINED IN CLIENT
	Application* CreateApplication();
}