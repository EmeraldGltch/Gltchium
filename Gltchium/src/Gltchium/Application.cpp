#include "gcpch.h"
#include "Application.h"

#include "Gltchium/EventSystem/ApplicationEvent.h"
#include "Gltchium/Logging/Log.h"
#include "Gltchium/Input/Input.h"

#include <glad/glad.h>

namespace Gltchium {
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
	Application* Application::s_Instance = nullptr;

	Application::Application() {
		GC_CORE_ASSERT(!s_Instance, "Instance already Exists!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application() {

	}

	void Application::PushLayer(Layer* layer) {
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer) {
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	void Application::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		GC_CORE_TRACE("{0}", e);

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); ) {
			(*--it)->OnEvent(e);

			if (e.Handled) {
				break;
			}
		}
	}

	void Application::Run() {
		while (m_Running) {
			glClearColor(0, 0.10, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack) {
				layer->OnUpdate();
			}

			auto [x, y] = Input::GetMousePosition();
			GC_CORE_TRACE("{0}, {1}", x, y);

			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e) {
		m_Running = false;
		return true;
	}

	void Print() {
		printf("  ______    __     __                  __         __\n");
		printf(" /      \\  |  \\   |  \\                |  \\       |  \\\n");
		printf("| $$$$$$ \\ | $$  _| $$_      _______  | $$____    \\$$  __    __   ______ ____\n");
		printf("| $$ __\\$$ | $$ |   $$ \\    /       \\ | $$    \\  |  \\ |  \\  |  \\ |      \\    \\\n");
		printf("| $$|    \\ | $$  \\$$$$$$   |  $$$$$$$ | $$$$$$$\\ | $$ | $$  | $$ |  $$$$$$\$$$$\\\n");
		printf("| $$ \\$$$$ | $$   | $$ __  | $$       | $$  | $$ | $$ | $$  | $$ | $$ | $$ | $$\n");
		printf("| $$__| $$ | $$   | $$|  \\ | $$_____  | $$  | $$ | $$ | $$__/ $$ | $$ | $$ | $$\n");
		printf(" \\$$    $$ | $$    \\$$  $$  \\$$     \\ | $$  | $$ | $$  \\$$    $$ | $$ | $$ | $$\n");
		printf("  \\$$$$$$   \\$$     \\$$$$    \\$$$$$$$  \\$$   \\$$  \\$$   \\$$$$$$   \\$$  \\$$  \\$$\n\n");
	}

	//  ______    __     __                  __         __
	// /      \  |  \   |  \                |  \       |  \
	//| $$$$$$ \ | $$  _| $$_      _______  | $$____    \$$  __    __  ______ ____
	//| $$ __\$$ | $$ |   $$ \    /       \ | $$    \  |  \ |  \  |  \ |      \    \
	//| $$|    \ | $$  \$$$$$$   |  $$$$$$$ | $$$$$$$\ | $$ | $$  | $$ | $$$$$$\$$$$\
	//| $$ \$$$$ | $$   | $$ __  | $$       | $$  | $$ | $$ | $$  | $$ | $$ | $$ | $$
	//| $$__| $$ | $$   | $$|  \ | $$_____  | $$  | $$ | $$ | $$__/ $$ | $$ | $$ | $$
	// \$$    $$ | $$    \$$  $$  \$$     \ | $$  | $$ | $$  \$$    $$ | $$ | $$ | $$
	//  \$$$$$$   \$$     \$$$$    \$$$$$$$  \$$   \$$  \$$   \$$$$$$   \$$  \$$  \$$
}
