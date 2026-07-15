#pragma once

#include <charconv>
#include <string>
#include <cstdint>
#include <limits>
#include <system_error>

namespace util::parse {

// General signed integer parser using std::from_chars. Ensures full-string parse and range checks.
template <typename Int>
inline bool parse_int(const std::string& s, Int& out, Int min_val, Int max_val) {
    if (s.empty()) return false;
    long long tmp = 0;
    const auto first = s.data();
    const auto last = s.data() + s.size();
    auto res = std::from_chars(first, last, tmp);
    if (res.ptr != last) return false;
    if (res.ec != std::errc()) return false;
    if (tmp < static_cast<long long>(min_val) || tmp > static_cast<long long>(max_val)) return false;
    out = static_cast<Int>(tmp);
    return true;
}

// General unsigned integer parser. Ensures full-string parse and range checks.
inline bool parse_size_t(const std::string& s, std::size_t& out, std::size_t max_val) {
    if (s.empty()) return false;
    unsigned long long tmp = 0;
    const auto first = s.data();
    const auto last = s.data() + s.size();
    auto res = std::from_chars(first, last, tmp);
    if (res.ptr != last) return false;
    if (res.ec != std::errc()) return false;
    if (tmp > static_cast<unsigned long long>(max_val)) return false;
    out = static_cast<std::size_t>(tmp);
    return true;
}

inline bool parse_port(const std::string& s, uint16_t& out) {
    uint32_t tmp = 0;
    if (!parse_int<uint32_t>(s, tmp, 1u, 65535u)) return false;
    out = static_cast<uint16_t>(tmp);
    return true;
}

} // namespace util::parse
