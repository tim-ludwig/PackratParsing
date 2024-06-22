#include <iostream>

#include "parser/LiteralParser.h"

int main() {
    const auto p = parser::LiteralParser{"Hallo"};
    const std::string s = "Hello, World!";

    if (const auto result = p.parse(s); result.has_value()) {
        std::cout << "Matched: " << result.value().text << std::endl;
    } else {
        std::cout << "No match" << std::endl;
    }

    return 0;
}
