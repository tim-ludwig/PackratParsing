#include "LiteralParser.h"

namespace parser {
    Result LiteralParser::parse(std::string_view const& text) const override {
        if (!text.starts_with(expected)) {
            return std::nullopt;
        }

        return Match{text.substr(0, expected.size())};
    }
}