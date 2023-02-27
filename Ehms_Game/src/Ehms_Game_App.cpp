#include <GEE.h>

class Ehms_Game : public GEE::Application {
public:
	Ehms_Game() {

	}

	~Ehms_Game() {

	}
};

GEE::Application* GEE::CreateApplication() {
	return new Ehms_Game();
}