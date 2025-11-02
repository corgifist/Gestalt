#include "Gestalt.hpp"
#include "HTMLTidy.hpp"

#include <fmt/core.h>


int main(int argc, char **argv) {
	auto tidy = Gestalt::HTMLTidy::New();

	auto test = "<title>Foo</title><p>Foo!";

	tidy->SetBool(TidyQuiet, true);
	tidy->SetBool(TidyMark, false);
	tidy->ParseString(test);
	tidy->CleanAndRepair();
	tidy->SaveToOutputBuffer();

	fmt::println("OUTPUT{}", tidy->GetOutputBuffer());

#if PLATFORM(WIN)
	fmt::println("Windows");
#elif PLATFORM(LINUX)
	fmt::println("Linux");
#elif PLATFORM(DARWIN)
	fmt::println("Darwin");
#endif
	return 0;
}