#ifndef PARSER_H
#define PARSER_H

#include <optional>
#include <string_view>

namespace parser {
	struct Match {
		const std::string_view text;
	};

	using Result = std::optional<Match>;

	class Parser {
	public:
		virtual ~Parser() = default;

		virtual Result parse(std::string_view const& text) const = 0;
	};
}

#endif //PARSER_H