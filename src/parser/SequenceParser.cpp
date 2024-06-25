#include "SequenceParser.h"

namespace parser {
    Result SequenceParser::parse(std::string_view const& text) const {
        size_t length = 0;
        std::string_view toParse = text;

        for (auto const& parser : parsers) {
            const auto result = parser->parse(toParse);

            if (!result.has_value()) {
                return result;
            }

            length += result->matched.size();
            toParse = result->remaining;
        }

        return Match(text, length);
    }

    Parser* SequenceParser::then(Parser const* next) {
        parsers.push_back(next);
        return this;
    }
}