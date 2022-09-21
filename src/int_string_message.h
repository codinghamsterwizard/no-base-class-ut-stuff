#ifndef INT_STRING_MESSAGE_H
#define INT_STRING_MESSAGE_H

#include <array>
#include <cstdint>
#include <limits>

#include "message_id.h"

namespace nb {

struct int_string_message {
    static constexpr auto id = static_cast<message_id>(0xabu);

    enum: std::uint8_t {
        max_string_size = std::numeric_limits<std::uint8_t>::max()
    };

    using int_value_type   = std::int32_t;
    using string_size_type = std::uint8_t;
    using string_type      = std::array<char, max_string_size>;

    enum: std::uint32_t {
        maximum_message_size =
            sizeof(int_value_type) +
            sizeof(string_size_type) +
            max_string_size * sizeof(string_type::value_type)
    };

    // data section
    int_value_type   int_value;
    string_size_type string_size;
    string_type      string;
};

}

#endif // INT_STRING_MESSAGE_H
