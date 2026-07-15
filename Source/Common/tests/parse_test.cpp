#include "Util/Parse.hpp"
#include <iostream>
#include <string>

int main() {
    using util::parse::parse_int;
    int out = 0;
    if (!parse_int<int>("123", out, 1, 1000) || out != 123) {
        std::cerr << "parse_int valid failed\n";
        return 1;
    }
    if (parse_int<int>("", out, 1, 10)) {
        std::cerr << "parse_int empty accepted\n";
        return 1;
    }
    if (parse_int<int>("999999999999999999999999", out, 1, 1000)) {
        std::cerr << "parse_int overflow accepted\n";
        return 1;
    }
    std::size_t s = 0;
    if (!util::parse::parse_size_t("1024", s, 2048) || s != 1024) {
        std::cerr << "parse_size_t valid failed\n";
        return 1;
    }
    if (util::parse::parse_size_t("99999999999999999999999", s, 2048)) {
        std::cerr << "parse_size_t overflow accepted\n";
        return 1;
    }
    uint16_t port = 0;
    if (!util::parse::parse_port("1337", port) || port != 1337) {
        std::cerr << "parse_port valid failed\n";
        return 1;
    }
    if (util::parse::parse_port("70000", port)) {
        std::cerr << "parse_port out of range accepted\n";
        return 1;
    }
    std::cout << "parse_test OK\n";
    return 0;
}
