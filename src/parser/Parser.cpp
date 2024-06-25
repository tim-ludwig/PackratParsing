#include "Parser.h"

#include "SequenceParser.h"

namespace parser {
    Parser* Parser::then(Parser const* next) {
        return (new SequenceParser{this})->then(next);
    }
}