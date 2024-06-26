#ifndef LITERALPARSER_H
#define LITERALPARSER_H

#include "Parser.h"

#include <string_view>

namespace parser {
    class LiteralParser : public Parser {
    private:
        const std::string expected;

    public:
        LiteralParser(const std::string _expected) : expected{_expected} {}

        Result parse(std::string_view const& text) const override;
    };
}

#endif //LITERALPARSER_H