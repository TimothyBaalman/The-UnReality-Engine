#pragma once

#ifdef UR_PLATFORM_WINDOWS

extern UnReality::Application* UnReality::CreateApplication();

int main(int argc, char** argv) {
	auto app = UnReality::CreateApplication();
	app->Run();
	delete app;
}

#endif // UR_PLATFORM_WINDOWS