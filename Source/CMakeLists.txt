set(Gestalt_Sources
	Gestalt.cpp
)

set(Gestalt_Headers
	Platform.hpp
	Feature.hpp
	Gestalt.hpp
)

add_library(Gestalt ${Gestalt_Sources} ${Gestalt_Headers})
target_include_directories(Gestalt PUBLIC .)
target_compile_definitions(Gestalt PRIVATE GESTALT_DLL_EXPORT)