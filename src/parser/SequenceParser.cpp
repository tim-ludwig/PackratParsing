#include "SequenceParser.h"

namespace parser {
    Result SequenceParser::parse(std::string_view const& text) const override {
        size_t length = 0;

        for (auto const& parser : parsers) {
            const auto result = parser->parse(text.substr(length));

            if (!result.has_value()) {
                return result;
            }

            length += result->text.size();
        }

        return Match{text.substr(0, length)};
    }

    Parser* SequenceParser::then(Parser const* next) override {
        parsers.push_back(next);
        return this;
    }
}