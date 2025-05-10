#include "commands/command.hpp"

#include <ranges>
#include <span>
#include <string_view>
#include <vector>

auto print_help() -> void;

auto main(int argc, char *argv[]) -> int
{
    auto args = std::span(argv, argc) | std::views::drop(1)
              | std::views::transform(
                  [](const char *arg) { return std::string_view(arg); })
              | std::ranges::to<std::vector>();

    return phi::commands::execute(args);
}
