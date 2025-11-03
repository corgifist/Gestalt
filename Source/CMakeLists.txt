set(Gestalt_Sources
	Gestalt.cpp
	HTMLTidy.cpp
	XML.cpp
)

set(Gestalt_Headers
	Platform.h
	Feature.h
	Gestalt.hpp
	HTMLTidy.hpp
	XML.hpp
)

find_package(unofficial-tidy-html5 CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(expat CONFIG REQUIRED)

add_library(Gestalt ${Gestalt_Sources} ${Gestalt_Headers})
target_include_directories(Gestalt PUBLIC .)
target_compile_definitions(Gestalt PRIVATE GESTALT_DLL_EXPORT)
target_link_libraries(Gestalt 
	PUBLIC unofficial::tidy-html5::tidy
	PUBLIC fmt::fmt
	PUBLIC expat::expat
)
set_target_properties(Gestalt PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
	CXX_EXTENSIONS OFF
)