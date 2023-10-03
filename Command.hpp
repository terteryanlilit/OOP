#ifndef COMMAND_CONTROLLER
#define COMMAND_CONTROLLER

#include <string>
#include <unordered_map>

using OperandMap = std::unordered_map<std::string, double>;

class Command {
public:
    virtual void addOperand(std::string option, double operand) =0; // operand type is double yet
    virtual void execute() =0;
    virtual Command* create() =0;
    virtual ~Command() {}

protected:
    OperandMap operandMap_;
};

#endif // COMMAND_CONTROLLER
