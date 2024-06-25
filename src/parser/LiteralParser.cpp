#include "LiteralParser.h"

namespace parser {
    Result LiteralParser::parse(std::string_view const& text) const {
        if (!text.starts_with(expected)) {
            return std::nullopt;
        }

        return Match(text, expected.size());
    }
}