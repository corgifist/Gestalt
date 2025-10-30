set(MiniBrowser_Sources
	MiniBrowser.cpp
)

add_executable(MiniBrowser ${MiniBrowser_Sources})
target_link_libraries(MiniBrowser PRIVATE Gestalt)