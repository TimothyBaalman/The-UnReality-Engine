#pragma once

#include "UnReality/Core.h"

#include <string>
#include <functional>

namespace UnReality {
	//Current Event Design is Blocking will implement buffering later on

	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender, 
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	//For filtering events
	enum EventCategory {
		None = 0,
		EventCategoryApplication  = BIT(0),
		EventCategoryInput        = BIT(1),
		EventCategoryKeyboard     = BIT(2),
		EventCategoryMouse        = BIT(3),
		EventCategoryMouseButton  = BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class UR_API Event {
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0; 
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0; 
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category) {
			return GetCategoryFlags() & category;
		}
	protected:
		bool _handled = false;
	};

	class EventDispatcher {
		template<typename EventType>
		using EventFn = std::function<bool(EventType&)>;
	public:
		EventDispatcher(Event& event) : _event(event) {

		}
		template<typename EventType>
		bool Dispatch(EventFn<EventType> func) {
			if (_Event.GetEventType() == EventType::GetStaticType()) {
				_event._handled = func(*(EventType*)&_event);
				return true;
			}
			return false;
		}
	private:
		Event& _event;
	};

	//For logging library
	inline std::ostream& operator<<(std::ostream& os, const Event& e) {
		return os << e.ToString();
	}
}