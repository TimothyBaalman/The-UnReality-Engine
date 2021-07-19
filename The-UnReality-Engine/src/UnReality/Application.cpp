#include "Application.h"

#include "UnReality/Events/ApplicationEvent.h"
#include "UnReality/Log.h"

//Macros will be shortened 
namespace UnReality {

	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent e(1200, 720);
		if(e.IsInCategory(EventCategoryApplication))
			UR_TRACE(e);
		if(e.IsInCategory(EventCategoryInput))
			UR_TRACE(e);

		while (true);
	}
}