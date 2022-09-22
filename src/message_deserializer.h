#ifndef MESSAGE_DESERIALIZER_H
#define MESSAGE_DESERIALIZER_H

#include <cstdint>
#include <tuple>
#include <vector>

#include "array_of_arrays_message.h"
#include "int_string_message.h"
#include "return_code.h"

namespace nb {
class message_deserializer
{
public:
    message_deserializer() = default;

    template <typename SerializedType>
    std::tuple<SerializedType, return_code>
    deserialize(std::vector<std::uint8_t>&);

    return_code parse(std::vector<std::uint8_t>&);
};

}

#endif // MESSAGE_DESERIALIZER_H
