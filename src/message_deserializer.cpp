#include "message_deserializer.h"

namespace nb {

template<>
int_string_message message_deserializer::deserialize<int_string_message>(std::vector<std::uint8_t> const& blob)
{
    int_string_message result;
    result.int_value   = 0u;
    result.string_size = 0u;
    return result;
}

}
