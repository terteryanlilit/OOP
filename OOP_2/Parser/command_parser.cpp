#include "command_parser.hpp"


Tokens Parser::tokenize(){
    Tokens tokens;
    std::stringstream ss(input_stream);
    if(ss.fail()){
        throw std::invalid_argument("Parser tokenization is failed");
    }
    std::string temp;
    while(std::getline(ss, temp, ' '))
    { 
        if(!temp.empty())
            tokens.push_back(temp);
    }    
    return tokens;
}

std::string Parser::determine_command(const Tokens token){
    validate_command(token[0]);
    return token[0];
}

CommandPtr Parser::parse(std::string input){
    Tokens tokens = tokenize();
    std::string command = determine_command(tokens);
    std::map<std::string, std::string> operands_map;
    for(auto i = 0; i < tokens.size() - 1 ; i += 2){
        operands_map[tokens[i]] = tokens[i+1];
    }
    auto cmdFACTORY = command_factory.create_command_builder(command, operands_map);
    return cmdFACTORY->get_result();
}
