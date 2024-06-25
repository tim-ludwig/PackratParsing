#ifndef CHOICEPARSER_H
#define CHOICEPARSER_H

#include "Parser.h"

#include <vector>

namespace parser {
    class ChoiceParser : public Parser {
    private:
        std::vector<Parser const*> choices;

    public:
        ChoiceParser() = default;
        ChoiceParser(Parser const* choice) : choices{choice} {};

        Result parse(std::string_view const& text) const override;

        Parser* or_else(Parser const* alternative) override;
    };
}

#endif //CHOICEPARSER_H
