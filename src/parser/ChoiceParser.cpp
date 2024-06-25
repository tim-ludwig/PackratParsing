#include "ChoiceParser.h"

namespace parser {
    Result ChoiceParser::parse(std::string_view const& text) const {
        for (const auto choice : choices) {
            if (const auto result = choice->parse(text); result.has_value()) {
                return result;
            }
        }

        return std::nullopt;
    }

    Parser* ChoiceParser::or_else(Parser const* alternative) {
        choices.push_back(alternative);
        return this;
    }
}