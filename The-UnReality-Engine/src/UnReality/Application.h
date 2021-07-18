#pragma once

#include "Core.h"
//Macros will be shortened 
namespace UnReality {

	class UR_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};
	
	// To be definced in CLIENT
	Application* CreateApplication();
}