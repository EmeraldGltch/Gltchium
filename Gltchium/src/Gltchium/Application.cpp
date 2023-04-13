#include "gcpch.h"
#include "Application.h"

#include "Gltchium/EventSystem/ApplicationEvent.h"
#include "Gltchium/Log.h"
#include <GLFW/glfw3.h>

namespace Gltchium {
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application() {

	}

	void Application::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		GC_CORE_TRACE("{0}", e);
	}

	void Application::Run() {
		while (m_Running) {
			glClearColor(0, 0.05, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);
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
