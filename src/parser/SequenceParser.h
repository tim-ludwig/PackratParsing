#ifndef SEQUENCEPARSER_H
#define SEQUENCEPARSER_H

#include <vector>

#include "Parser.h"

namespace parser {
    class SequenceParser : public Parser {
    private:
        std::vector<Parser const*> parsers;

    public:
        SequenceParser() = default;
        explicit SequenceParser(Parser const* parser) : parsers{parser} {}

        Result parse(std::string_view const& text) const override;

        Parser* and_then(Parser const* next) override;
    };
}

#endif //SEQUENCEPARSER_H
