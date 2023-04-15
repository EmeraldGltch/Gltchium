#include <Gltchium.h>

class TestLayer : public Gltchium::Layer {
	public:
		TestLayer() : Layer("Testing") {}

		void OnUpdate() override {
			GC_INFO("TestLayer::Update");
		}

		void OnEvent(Gltchium::Event& event) override {
			GC_TRACE("{0}", event);
		}
};

class Sandbox : public Gltchium::Application {
	public:
		Sandbox() {
			PushLayer(new TestLayer());
			PushOverlay(new Gltchium::ImGuiLayer());
		}

		~Sandbox() {

		}
};

Gltchium::Application* Gltchium::CreateApplication() {
	return new Sandbox();
}
