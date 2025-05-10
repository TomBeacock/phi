#pragma once

#include <span>
#include <string_view>

namespace phi::commands {

auto run(std::span<const std::string_view> args) -> int;

} // namespace phi::commands
