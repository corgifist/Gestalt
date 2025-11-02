cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(Gestalt)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

option(BUILD_EXAMPLES "Build example programs" ON)

# Source code of Gestalt library
add_subdirectory(Source)

if (BUILD_EXAMPLES)
  add_subdirectory(Examples)
endif()