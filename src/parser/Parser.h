#ifndef PARSER_H
#define PARSER_H

#include <memory>
#include <optional>
#include <string_view>

namespace parser {
	class Match {
	public:
		const std::string_view matched;
		const std::string_view remaining;

		Match(const std::string_view text, size_t match_length)
			: matched{text.substr(0, match_length)},
		      remaining(text.substr(match_length))
		{

		}
	};

	using Result = std::optional<Match>;

	class Parser {
	public:
		virtual ~Parser() = default;

		virtual Result parse(std::string_view const& text) const = 0;

		virtual Parser* then(Parser const* next);
	};
}

#endif //PARSER_H