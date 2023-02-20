#include <GE_Ehm.h>

class Ehms_Game : public GE_Ehm::Application {
public:
	Ehms_Game() {

	}

	~Ehms_Game() {

	}
};

GE_Ehm::Application* GE_Ehm::CreateApplication() {
	return new Ehms_Game();
}