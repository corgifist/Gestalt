set(MiniBrowser_Sources
	MiniBrowser.cpp
)

add_executable(MiniBrowser ${MiniBrowser_Sources})
target_link_libraries(MiniBrowser PRIVATE Gestalt)
set_target_properties(MiniBrowser PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
	CXX_EXTENSIONS OFF
)