#ifndef MESSAGE_OUTPUT_STREAM_H
#define MESSAGE_OUTPUT_STREAM_H

#include <cstdint>
#include <vector>

#include "message_serializer.h"
#include "message_deserializer.h"

namespace nb {

class message_output_stream
{
    message_serializer _serializer;

public:
    message_output_stream() = default;

    void write(int_string_message const&);
    void write(array_of_arrays_message const&);

    void write(std::vector<int_string_message> const&);
    void write(std::vector<array_of_arrays_message> const&);
};

}

#endif // MESSAGE_OUTPUT_STREAM_H
