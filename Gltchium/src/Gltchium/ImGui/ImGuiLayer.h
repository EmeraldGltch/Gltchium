#pragma once

#include "Gltchium/LayerStack/Layer.h"

#include "Gltchium/EventSystem/MouseEvent.h"
#include "Gltchium/EventSystem/KeyEvent.h"
#include "Gltchium/EventSystem/ApplicationEvent.h"

namespace Gltchium {
	class GLTCHIUM_API ImGuiLayer : public Layer {
		public:
			ImGuiLayer();
			~ImGuiLayer();

			void OnAttach();
			void OnDetach();

			void OnUpdate();
			void OnEvent(Event& event);
		private:
			bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
			bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
			bool OnMouseMovedEvent(MouseMovedEvent& e);
			bool OnMouseScrolledEvent(MouseScrolledEvent& e);
			bool OnKeyPressedEvent(KeyPressedEvent& e);
			bool OnKeyReleasedEvent(KeyReleasedEvent& e);
			bool OnKeyTypedEvent(KeyTypedEvent& e);
			bool OnWindowResizeEvent(WindowResizeEvent& e);
		private:
			float m_Time = 0.0f;
	};
}
