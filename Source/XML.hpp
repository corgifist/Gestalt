#pragma once

/*
	XML.hpp - safe C++ wrapper over libexpat
*/

#include "Gestalt.hpp"

#include <expat.h>

namespace Gestalt {
	class XML;
	using XMLPtr = std::unique_ptr<XML>;

	class XML {
	public:
		~XML();

		template <typename ...Args>
		static inline XMLPtr New(Args&& ...args) {
			return std::unique_ptr<XML>(new XML(std::forward<Args>(args)...));
		}

		void SetUserData(void* data);
		void SetElementHandler(XML_StartElementHandler startHandler, XML_EndElementHandler endHandler);
		void SetCharacterDataHandler(XML_CharacterDataHandler characterHandler);

		XML_Status Parse(std::string_view input, bool isFinal);

		XML_Size GetCurrentLineNumber();
		XML_Error GetErrorCode();
		std::string GetErrorString(XML_Error error);

	private:
		XML();
		XML(const XML&&) = delete;
		XML& operator=(const XML&) = delete;

		XML_Parser m_parser;
	};
} // Gestalt