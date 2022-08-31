#ifndef MESSAGE_INPUT_STREAM_H
#define MESSAGE_INPUT_STREAM_H

#include "mockable.h"
#include "message_deserializer.h"

namespace nb {

class message_input_stream
{
MOCKABLE_PRIVATE:
    MOCKABLE(message_deserializer) _deserializer;

public:
    message_input_stream() = default;
};

}

#endif // MESSAGE_INPUT_STREAM_H
