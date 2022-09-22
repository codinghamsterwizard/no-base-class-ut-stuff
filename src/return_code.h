#ifndef RETURN_CODE_H
#define RETURN_CODE_H

#include <cstdint>

namespace nb {

enum class return_code: std::uint8_t {
    serialization_data_skipped,
    serialization_empty_blob,
    serialization_fragmented,
    serialization_successful,
    serialization_unknown_error
};

}

#endif // RETURN_CODE_H
