#include <iostream>
#include <vector>

#include "parser/LiteralParser.h"
#include "parser/SequenceParser.h"

int main() {
    auto h1 = new parser::LiteralParser{"Hello, "};
    auto w1 = new parser::LiteralParser{"World!"};
    auto h2 = new parser::LiteralParser{"Hallo, "};
    auto w2 = new parser::LiteralParser{"Welt!"};

    auto p = h1->and_then(w1)->or_else(h2->and_then(w2));

    const std::string s = "Hallo, Welt!";

    if (const auto result = p->parse(s); result.has_value()) {
        std::cout << "Matched: '" << result.value().matched << "'" << std::endl;
        std::cout << "Remaining: '" << result.value().remaining << "'" << std::endl;
    } else {
        std::cout << "No match" << std::endl;
    }

    return 0;
}
