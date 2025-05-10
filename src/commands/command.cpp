#include "command.hpp"

#include "run.hpp"

#include <functional>
#include <map>
#include <print>
#include <ranges>

namespace phi::commands {

using Command = std::function<int(std::span<const std::string_view>)>;

const std::map<std::string_view, Command> commands{
    {"run", &commands::run},
};

auto execute(std::span<const std::string_view> args) -> int
{
    if (args.empty()) {
        // TODO print help
        return 1;
    }

    auto command_it = commands.find(args.front());
    if (command_it == commands.end()) {
        std::println(
            R"(Unknown command "{}". Run "phi help" for available commands.)",
            args.front());
        return 1;
    }

    const auto &[name, command] = *command_it;
    return command(std::ranges::drop_view(args, 1));
}

} // namespace phi::commands
