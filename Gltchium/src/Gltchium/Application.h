#pragma once

#include "Core.h"
#include "EventSystem/Event.h"
#include "Gltchium/EventSystem/ApplicationEvent.h"

#include "Window.h"

namespace Gltchium {
	class GLTCHIUM_API Application {
		public:
			Application();
			virtual ~Application();

			void Run();

			void OnEvent(Event& e);
		private:
			bool OnWindowClose(WindowCloseEvent& e);

			std::unique_ptr<Window> m_Window;
			bool m_Running = true;
	};

	__declspec(dllexport) void Print();

	// DEFINED IN CLIENT
	Application* CreateApplication();
}