#pragma once

/*
	HTMLTidy.hpp - safe C++ wrapper over tidy-html5
*/

#include "Gestalt.hpp"

#include <tidy.h>
#include <tidybuffio.h>

namespace Gestalt {
	class HTMLTidy;

	using HTMLTidyPtr = std::unique_ptr<HTMLTidy>;

	class HTMLTidy {
	public:
		~HTMLTidy();

		template <typename ...Args>
		static inline HTMLTidyPtr New(Args&& ...args) {
			return std::unique_ptr<HTMLTidy>(new HTMLTidy(std::forward<Args>(args)...));
		}

		/*
			Calls tidyOptSetBool(...) under the hood
			@result true if tidyOptSetBool(....) returns yes, otherwise false
		*/
		bool SetBool(TidyOptionId option, bool value);

		/*
			Calls tidyOptGetBool(...) under the hood
			@result value of tidyOptGetBool(...)
		*/
		bool GetBool(TidyOptionId option);

		/*
			Calls tidyOptSetValue(...) under the hood
			@result true if tidyOptSetValue(...) returns yes, otherwise false
		*/
		bool SetString(TidyOptionId option, std::string_view s);

		/*
			Calls tidyOptGetValue(...) under the hood
			@result value of tidyOptGetValue(...)
		*/
		std::string GetString(TidyOptionId option);


		/*
			Calls tidySetMessageCallback(...) under the hood
			@result true if tidySetMessageCallback(...) returns yes, otherwise false
		*/
		bool SetMessageCallback(TidyMessageCallback callback);

		/*
			Calls tidyParseString(...) under the hood
			@result tidyParseString(...) result
		*/
		int ParseString(std::string_view s);

		/*
			Calls tidyCleanAndRepair(...) under the hood
			@result tidyCleanAndRepair(...) result
		*/
		int CleanAndRepair();

		/*
			Calls tidyRunDiagnostics(...) under the hood
			@result tidyRunDiagnostics(...) result
		*/
		int RunDiagnostics();


		/*
			Calls tidySaveBuffer(..., &m_out) under the hood
			@result tidySaveBuffer(...) result
		*/
		int SaveToOutputBuffer();

		/*
			@result content of m_out
		*/
		std::string GetOutputBuffer();

		/*
			@result content of m_err
		*/
		std::string GetErrorBuffer();

	private:
		HTMLTidy();
		HTMLTidy(const HTMLTidy&) = delete;
		HTMLTidy& operator=(const HTMLTidy&) = delete;

		TidyDoc m_doc;
		TidyBuffer m_err, m_out;
	};
} // Gestalt