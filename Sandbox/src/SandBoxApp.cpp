#include <UnReality.h>

class Sandbox : public UnReality::Application {
public:
	Sandbox() {

	}
	~Sandbox() {

	}

};

UnReality::Application* UnReality::CreateApplication() {
	return new Sandbox();
}