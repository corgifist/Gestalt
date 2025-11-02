/*
	feature.h - different macros for checking enabled / disabled features
	provides USE(FEATURE) macro
	notice: this header is compatible with C
*/

#ifndef GESTALT_FEATURE_H
#define GESTALT_FEATURE_H

#define USE(FEATURE) GESTALT_IS_ ## FEATURE ## _ENABLED

#endif // GESTALT_FEATURE_H