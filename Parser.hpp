#ifndef COMMAND_CONTROLLER_PARSER
#define COMMAND_CONTROLLER_PARSER

#include "Command.hpp"
#include "CommandRegistry.hpp"

#include <istream>
#include <sstream>

class Parser {
public:
    Parser(std::istream&);
    CommandPtr parseCommand();

private:
   std::stringstream inputCommand(); 

private:
    std::istream& input_;
    CommandRegistry commandRegistry_;
};

#endif // COMMAND_CONTROLLER_PARSER
