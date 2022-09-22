#ifndef MESSAGE_ID_H
#define MESSAGE_ID_H

#include <array>
#include <cstdint>

namespace nb {

static constexpr std::array<std::uint8_t, 4> message_threshold_sequence = { 0xfa, 0xaf, 0xfa, 0xaf };
enum class message_id : std::uint8_t {};

}

#endif // MESSAGE_ID_H
