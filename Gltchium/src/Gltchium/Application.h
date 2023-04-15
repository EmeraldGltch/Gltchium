#pragma once

#include "Core.h"

#include "Platforms/Window.h"
#include "Gltchium/LayerStack/LayerStack.h"
#include "EventSystem/Event.h"
#include "Gltchium/EventSystem/ApplicationEvent.h"

namespace Gltchium {
	class GLTCHIUM_API Application {
		public:
			Application();
			virtual ~Application();

			void Run();

			void OnEvent(Event& e);

			void PushLayer(Layer* layer);
			void PushOverlay(Layer* layer);

			inline static Application& Get() { return *s_Instance; }

			inline Window& GetWindow() { return *m_Window; }
		private:
			bool OnWindowClose(WindowCloseEvent& e);

			std::unique_ptr<Window> m_Window;
			bool m_Running = true;
			LayerStack m_LayerStack;
		private:
			static Application* s_Instance;
	};

	__declspec(dllexport) void Print();

	// DEFINED IN CLIENT
	Application* CreateApplication();
}