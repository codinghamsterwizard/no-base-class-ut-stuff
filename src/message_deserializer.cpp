#include "message_deserializer.h"

#include <algorithm>
#include <cstring>
#include <iterator>

#include "array_of_arrays_message.h"
#include "int_string_message.h"
#include "message_id.h"

namespace nb {

template<>
std::tuple<int_string_message, return_code>
message_deserializer::deserialize<int_string_message>(std::vector<std::uint8_t>& blob)
{
    if (blob.empty())
    {
        return std::make_tuple(int_string_message(), return_code::serialization_empty_blob);
    }

    int_string_message result;
    auto position = std::begin(blob);

    // serialize int value
    constexpr auto size_of_int_value = sizeof(int_string_message::int_value_type);
    std::memcpy(&result.int_value, &(*position), size_of_int_value);
    std::advance(position, size_of_int_value);

    // serialize string size
    constexpr auto size_of_string_size = sizeof(int_string_message::string_size_type);
    std::memcpy(&result.string_size, &(*position), size_of_string_size);
    std::advance(position, size_of_string_size);

    // serialize string
    std::memcpy(
        &result.string.data()[0],
        &(*position),
        result.string_size * sizeof(int_string_message::string_type::value_type));
    std::advance(position, result.string_size * sizeof(int_string_message::string_type::value_type));

    blob.erase(std::begin(blob), position);
    blob.shrink_to_fit();
    return std::make_tuple(result, return_code::serialization_successful);
}

template<>
std::tuple<array_of_arrays_message, return_code>
message_deserializer::deserialize<array_of_arrays_message>(std::vector<std::uint8_t>& blob)
{
    if (blob.empty())
    {
        return std::make_tuple(array_of_arrays_message(), return_code::serialization_empty_blob);
    }

    array_of_arrays_message result;
    auto position = std::begin(blob);

    // serialize size (length) of upper-level array
    constexpr auto size_of_size_type = sizeof(array_of_arrays_message::size_type);
    std::memcpy(&result.size, &(*position), size_of_size_type);
    std::advance(position, size_of_size_type);

    constexpr auto size_of_subarray_size_type =
        sizeof(array_of_arrays_message::subarray::size_type);

    // serialize sub-arrays
    for (auto i = 0; i != result.size; i++)
    {
        // serialize size of current sub-array
        std::memcpy(&result.value[i].size, &(*position), size_of_subarray_size_type);
        std::advance(position, size_of_subarray_size_type);

        // serialize current sub-array
        std::memcpy(&result.value[i].data.data()[0], &(*position), result.value[i].size);
        std::advance(position, result.value[i].size);
    }

    blob.erase(std::begin(blob), position);
    blob.shrink_to_fit();
    return std::make_tuple(result, return_code::serialization_successful);
}

return_code message_deserializer::parse(std::vector<std::uint8_t>& blob)
{
    if (blob.empty())
    {
        return return_code::serialization_empty_blob;
    }

    auto position = std::search(
        std::begin(blob),
        std::end(blob),
        std::begin(message_threshold_sequence),
        std::end(message_threshold_sequence));
    std::advance(position, message_threshold_sequence.max_size());
    if (position == std::end(blob))
    {
        return return_code::serialization_fragmented;
    }

    return_code rc = return_code::serialization_unknown_error;
    if (position != std::begin(blob))
    {
        blob.erase(std::begin(blob), position);
        rc = return_code::serialization_data_skipped;
    }

    auto serialization_rc = return_code::serialization_unknown_error;
    switch(static_cast<message_id>(*position))
    {
    case int_string_message::id:
    {
        int_string_message msg;
        std::tie(msg, serialization_rc) = deserialize<int_string_message>(blob);
        break;
    }
    case array_of_arrays_message::id:
    {
        array_of_arrays_message msg;
        std::tie(msg, serialization_rc) = deserialize<array_of_arrays_message>(blob);
        break;
    }
    default:
    {
        return return_code::serialization_fragmented;
    }
    }

    return rc == return_code::serialization_data_skipped ? rc : serialization_rc;
}

}
