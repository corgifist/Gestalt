#include "Gestalt.hpp"
#include "HTMLTidy.hpp"
#include "XML.hpp"

#include <fmt/core.h>

void startElement(void* data, const char* element, const char** attr) {
	fprintf(stdout, "Start Element: %s\n", element);

	if (attr) {
		for (int i = 0; attr[i]; i += 2) {
			fprintf(stdout, "  Attribute: %s = %s\n", attr[i], attr[i + 1]);
		}
	}
}

void endElement(void* data, const char* element) {
	fprintf(stdout, "End Element: %s\n", element);
}

void characterData(void* data, const char* content, int length) {
	fprintf(stdout, "Character Data: %.*s\n", length, content);
}

int main(int argc, char **argv) {
	auto tidy = Gestalt::HTMLTidy::New();

	auto test = "<title>Foo</title><p>Foo!";

	tidy->SetBool(TidyQuiet, true);
	tidy->SetBool(TidyMark, false);
	tidy->SetBool(TidyXhtmlOut, true);
	tidy->ParseString(test);
	tidy->CleanAndRepair();
	tidy->SaveToOutputBuffer();
	auto output = tidy->GetOutputBuffer();

	auto xml = Gestalt::XML::New();
	xml->SetElementHandler(startElement, endElement);
	xml->SetCharacterDataHandler(characterData);
	xml->Parse(output, true);

#if PLATFORM(WIN)
	fmt::println("Windows");
#elif PLATFORM(LINUX)
	fmt::println("Linux");
#elif PLATFORM(DARWIN)
	fmt::println("Darwin");
#endif
	return 0;
}