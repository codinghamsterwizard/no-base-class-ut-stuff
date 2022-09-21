#ifndef MESSAGE_OUTPUT_STREAM_H
#define MESSAGE_OUTPUT_STREAM_H

#include "mockable.h"
#include "message_serializer.h"
#include "message_deserializer.h"

MOCKABLE_INCLUDE("message_output_stream.h")

namespace nb {

class message_output_stream
{
MOCKABLE_PRIVATE:
    MOCKABLE(message_serializer) _serializer;
    message_deserializer _deserializer;

public:
    message_output_stream() = default;
};

}

#endif // MESSAGE_OUTPUT_STREAM_H
