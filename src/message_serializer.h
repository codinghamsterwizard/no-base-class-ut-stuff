#ifndef MESSAGE_SERIALIZER_H
#define MESSAGE_SERIALIZER_H

#include <vector>
#include <cstdint>

#include "array_of_arrays_message.h"
#include "int_string_message.h"

namespace nb {

class message_serializer
{
public:
    message_serializer() = default;

    std::vector<std::uint8_t> serialize(int_string_message const&);
    std::vector<std::uint8_t> serialize(array_of_arrays_message const&);
};

}

#endif // MESSAGE_SERIALIZER_H
