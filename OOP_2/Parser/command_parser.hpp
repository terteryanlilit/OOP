#ifndef COMMAND_PARSER
#define COMMAND_PARSER

#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <variant>
#include <vector>

#include "../Builder/command_builder_factory.hpp"
#include "../Command/command.hpp"

class Parser{
    public:
        Parser() = default;
        Parser(std::string input): input_stream{input}{};
    private:
        using Tokens = std::vector<std::string>;
        using OptionsMap = std::map<std::string, std::optional<std::string>>;
    public:
        CommandPtr parse(std::string input);
        Tokens tokenize();
        std::string determine_command(const Tokens);
        std::variant<std::string, int, void> determine_operands(const Tokens&, std::string option);
    private:
        friend class Validate;
        std::string input_stream;
        OptionsMap options;
        CommandBuilderFactory command_factory;
};

class Validate{
    public:
        void validate_command();
        void validate_operands();
};

#endif //COMMAND_PARSER