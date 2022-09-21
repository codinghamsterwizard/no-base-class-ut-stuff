#ifndef MESSAGE_DESERIALIZER_H
#define MESSAGE_DESERIALIZER_H

#include <vector>

#include "array_of_arrays_message.h"
#include "int_string_message.h"

namespace nb {
class message_deserializer
{
public:
    message_deserializer() = default;

    template <typename ResultType>
    ResultType deserialize(std::vector<uint8_t> const&);
};

}

#endif // MESSAGE_DESERIALIZER_H
