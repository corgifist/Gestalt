#pragma once

/*
	feature.hpp - different macros for checking enabled / disabled features
	provides USE(FEATURE) macro
*/

#define USE(FEATURE) GESTALT_IS_ ## FEATURE ## _ENABLED