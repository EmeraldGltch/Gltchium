#include <Gltchium.h>

class Sandbox : public Gltchium::Application {
	public:
		Sandbox() {

		}

		~Sandbox() {

		}
};

Gltchium::Application* Gltchium::CreateApplication() {
	return new Sandbox();
}
