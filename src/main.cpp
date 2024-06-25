#include <iostream>
#include <vector>

#include "parser/LiteralParser.h"
#include "parser/SequenceParser.h"

int main() {
    auto h = new parser::LiteralParser{"Hello, "};
    auto w = new parser::LiteralParser{"World!"};
    auto hw = h->then(w);

    const std::string s = "Hello, World!";

    if (const auto result = hw->parse(s); result.has_value()) {
        std::cout << "Matched: " << result.value().text << std::endl;
    } else {
        std::cout << "No match" << std::endl;
    }

    return 0;
}
