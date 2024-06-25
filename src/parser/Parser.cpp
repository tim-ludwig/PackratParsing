#include "Parser.h"

#include "SequenceParser.h"
#include "ChoiceParser.h"

namespace parser {
    Parser* Parser::and_then(Parser const* next) {
        return (new SequenceParser{this})->and_then(next);
    }

    Parser* Parser::or_else(Parser const* alternative) {
        return (new ChoiceParser{this})->or_else(alternative);
    }
}