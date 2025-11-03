#include "XML.hpp"

namespace Gestalt {
	XML::XML() {
		this->m_parser = XML_ParserCreate(nullptr);
	}

	XML::~XML() {
		XML_ParserFree(m_parser);
	}

	void XML::SetUserData(void *t_data) {
		XML_SetUserData(m_parser, t_data);
	}

	void XML::SetElementHandler(XML_StartElementHandler t_startHandler, XML_EndElementHandler t_endHandler) {
		XML_SetElementHandler(m_parser, t_startHandler, t_endHandler);
	}

	void XML::SetCharacterDataHandler(XML_CharacterDataHandler t_characterHandler) {
		XML_SetCharacterDataHandler(m_parser, t_characterHandler);
	}

	XML_Status XML::Parse(std::string_view t_input, bool flag) {
		return XML_Parse(m_parser, t_input.data(), t_input.length(), flag);
	}

	XML_Size XML::GetCurrentLineNumber() {
		return XML_GetCurrentLineNumber(m_parser);
	}

	XML_Error XML::GetErrorCode() {
		return XML_GetErrorCode(m_parser);
	}

	std::string XML::GetErrorString(XML_Error t_error) {
		return XML_ErrorString(t_error);
	}
} // Gestalt