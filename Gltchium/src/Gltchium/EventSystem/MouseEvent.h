#pragma once

#include "Event.h"

namespace Gltchium {
	class GLTCHIUM_API MouseMovedEvent : public Event {
		public:
			MouseMovedEvent(float x, float y) : m_MouseX(x), m_MouseY(y) {}

			inline float GetX() const { return m_MouseX; }
			inline float GetY() const { return m_MouseY; }

			std::string ToString() const override {
				std::stringstream ss;
				ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
				ss.str();
			}

			EVENT_CLASS_TYPE(MouseMoved)
			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

		private:
			float m_MouseX, m_MouseY;
	};

	class GLTCHIUM_API MouseScolledEvent : public Event {
		public:
			MouseScolledEvent(float xOffset, float yOffset) : m_XOffset(xOffset), m_YOffset(yOffset) {}

			inline float GetXOffset() const { return m_XOffset; }
			inline float GetYOffset() const { return m_YOffset; }

			std::string ToString() const override {
				std::stringstream ss;
				ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
				return ss.str();
			}

			EVENT_CLASS_TYPE(MouseScrolled);
			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
		private:
			float m_XOffset, m_YOffset;
	};

	class GLTCHIUM_API MouseButtonEvent : public Event {
		public:
			inline int GetMouseButton() const { return m_Button; }

			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
		protected:
			MouseButtonEvent(int button) : m_Button(button) {}

			int m_Button;
	};

	class GLTCHIUM_API MouseButtonPressedEvent : public MouseButtonEvent {
		public:
			MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

			std::string ToString() const override {
				std::stringstream ss;
				ss << "MouseButtonPressedEvent: " << m_Button;
				ss.str();
			}

			EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class GLTCHIUM_API MouseButtonReleasedEvent : public MouseButtonEvent {
		public:
			MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

			std::string ToString() const override {
				std::stringstream ss;
				ss << "MouseButtonReleasedEvent: " << m_Button;
				ss.str();
			}

			EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}
