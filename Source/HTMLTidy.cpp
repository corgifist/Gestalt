#include "HTMLTidy.hpp"

namespace Gestalt {
	HTMLTidy::HTMLTidy() {
		this->m_doc = tidyCreate();
		this->m_out = { 0 };
		this->m_err = { 0 };
		
		tidySetErrorBuffer(m_doc, &m_err);
	}

	HTMLTidy::~HTMLTidy() {
		if (m_out.allocated) tidyBufFree(&m_out);
		if (m_err.allocated) tidyBufFree(&m_err);
		tidyRelease(m_doc);
	}

	bool HTMLTidy::SetBool(TidyOptionId t_option, bool t_value) {
		return tidyOptSetBool(m_doc, t_option, t_value ? yes : no) == yes;
	}

	bool HTMLTidy::GetBool(TidyOptionId t_option) {
		return tidyOptGetBool(m_doc, t_option);
	}

	bool HTMLTidy::SetString(TidyOptionId t_option, std::string_view t_string) {
		return tidyOptSetValue(m_doc, t_option, t_string.data());
	}

	std::string HTMLTidy::GetString(TidyOptionId t_option) {
		return tidyOptGetValue(m_doc, t_option);
	}

	bool HTMLTidy::SetMessageCallback(TidyMessageCallback t_callback) {
		return tidySetMessageCallback(m_doc, t_callback) == yes;
	}

	int HTMLTidy::ParseString(std::string_view t_input) {
		return tidyParseString(m_doc, t_input.data());
	}

	int HTMLTidy::CleanAndRepair() {
		return tidyCleanAndRepair(m_doc);
	}

	int HTMLTidy::RunDiagnostics() {
		return tidyRunDiagnostics(m_doc);
	}

	int HTMLTidy::SaveToOutputBuffer() {
		return tidySaveBuffer(m_doc, &m_out);
	}

	std::string HTMLTidy::GetOutputBuffer() {
		if (!m_out.allocated) return "";
		return (const char*) m_out.bp;
	}

	std::string HTMLTidy::GetErrorBuffer() {
		if (!m_err.allocated) return "";
		return (const char*) m_err.bp;
	}

}