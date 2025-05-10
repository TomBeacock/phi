#include "run.hpp"

#include <print>

namespace phi::commands {

auto run(std::span<const std::string_view> args) -> int
{
    std::println("running");
    return 0;
}

} // namespace phi::commands
