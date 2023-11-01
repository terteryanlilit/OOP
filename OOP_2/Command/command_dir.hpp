#ifndef COMMAND_DIR_HPP
#define COMMAND_DIR_HPP

#include "command.hpp"
#include "command_builder.hpp"

using OptionsMap = std::map<std::string, std::variant<std::string, int, void>>;

class CommandDirector{
    public:
        CommandDirector() = default;
        CommandPtr construct(CommandBuilderPtr, OptionsMap options);
};

#endif //COMMAND_DIR_HPP