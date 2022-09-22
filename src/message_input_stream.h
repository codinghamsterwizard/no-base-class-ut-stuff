#ifndef MESSAGE_INPUT_STREAM_H
#define MESSAGE_INPUT_STREAM_H

#include <cstdint>
#include <vector>

#include "message_deserializer.h"

namespace nb {

class message_input_stream
{
    message_deserializer _deserializer;

public:
    message_input_stream() = default;

    template<typename SerializedType>
    SerializedType read();
};

}

#endif // MESSAGE_INPUT_STREAM_H
