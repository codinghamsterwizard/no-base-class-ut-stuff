#ifndef ARRAY_OF_ARRAYS_MESSAGE_H
#define ARRAY_OF_ARRAYS_MESSAGE_H

#include <array>
#include <cstdint>

#include "message_id.h"

namespace nb {

struct array_of_arrays_message {
    static constexpr auto id = static_cast<message_id>(0xcd);

    struct subarray {
        enum : uint32_t {
            max_size = 5u
        };

        using size_type = std::uint32_t;
        using data_type = std::array<std::uint8_t, max_size>;

        size_type size;
        data_type data;
    };

    enum : uint32_t {
        max_size = 5u
    };

    using size_type  = std::uint32_t;
    using value_type = std::array<subarray, max_size>;

    enum : uint32_t {
        maximum_message_size = subarray::max_size * sizeof(subarray::data_type) * max_size
    };

    // data section
    size_type  size;
    value_type value;
};

}

#endif // ARRAY_OF_ARRAYS_MESSAGE_H
