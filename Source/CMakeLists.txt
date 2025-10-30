set(Gestalt_Sources
	Gestalt.cpp
)

set(Gestalt_Headers
	Platform.hpp
	Feature.hpp
	Gestalt.hpp
)

find_package(unofficial-tidy-html5 CONFIG REQUIRED)

add_library(Gestalt ${Gestalt_Sources} ${Gestalt_Headers})
target_include_directories(Gestalt PUBLIC .)
target_compile_definitions(Gestalt PRIVATE GESTALT_DLL_EXPORT)
target_link_libraries(Gestalt PRIVATE unofficial::tidy-html5::tidy)