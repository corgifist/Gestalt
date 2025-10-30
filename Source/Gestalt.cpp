#include "Gestalt.hpp"

GESTALT_API void GestaltC() {
	std::cout << "Hello, Gestalt C API!" << std::endl;
}

namespace Gestalt {
	void NamespaceTest(void) {
		std::cout << "Hello, Gestalt C++ API!" << std::endl;
	}
} // namespace Gestalt