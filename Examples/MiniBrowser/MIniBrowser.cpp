#include "Gestalt.hpp"

int main(int argc, char **argv) {
	GestaltC();
	Gestalt::NamespaceTest();
#if PLATFORM(WIN)
	std::cout << "Windows platform" << std::endl;
#elif PLATFORM(LINUX)
	std::cout << "Linux platform" << std::endl;
#elif PLATFORM(DARWIN)
	std::cout << "Darwin platform" << std::endl;
#endif
	return 0;
}