#pragma once

#ifdef UR_PLATFORM_WINDOWS

extern UnReality::Application* UnReality::CreateApplication();

int main(int argc, char** argv) {
	UnReality::Log::Init();
	UR_CORE_WARN("Initialized Log!");
	int a = 10;
	UR_INFO("Hello var a = {0}", a);

	auto app = UnReality::CreateApplication();
	app->Run();
	delete app;
}

#endif // UR_PLATFORM_WINDOWS