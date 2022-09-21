#include <algorithm>
#include <cstring>
#include <iterator>

#include "message_serializer.h"

namespace nb {

std::vector<uint8_t> message_serializer::serialize(int_string_message const& msg)
{
    std::vector<std::uint8_t> result;
    result.reserve(int_string_message::maximum_message_size);
    auto position = &result.data()[0];

    // serialize int value
    constexpr auto size_of_int_value_type = sizeof(int_string_message::int_value_type);
    std::memcpy(position, &msg.int_value, size_of_int_value_type);
    position += size_of_int_value_type;

    // serialize string size
    constexpr auto size_of_string_size_type = sizeof(int_string_message::string_size_type);
    std::memcpy(position, &msg.string_size, size_of_string_size_type);
    position += size_of_string_size_type;

    // serialize string value
    std::memcpy(position, &msg.string.data()[0], msg.string_size);

    result.shrink_to_fit();
    return result;
}

std::vector<uint8_t> message_serializer::serialize(array_of_arrays_message const& msg)
{
    std::vector<uint8_t> result;
    result.reserve(array_of_arrays_message::maximum_message_size);
    auto position = &result.data()[0];

    // serialize size of upper-level array
    constexpr auto size_of_size_type = sizeof(array_of_arrays_message::size_type);
    std::memcpy(position, &msg.size, size_of_size_type);
    position += size_of_size_type;

    // serialize subarrays
    constexpr auto size_of_subarray_size_type = sizeof(array_of_arrays_message::subarray::size_type);
    for (auto const inner_array : msg.value)
    {
        // serialize size of subarray
        std::memcpy(position, &inner_array.size, size_of_subarray_size_type);
        position += size_of_subarray_size_type;

        // serialize subarray
        std::memcpy(position, &inner_array.data[0], inner_array.size);
        position += inner_array.size;
    }

    result.shrink_to_fit();
    return result;
}

}
