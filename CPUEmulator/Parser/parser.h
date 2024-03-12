#ifndef CPUEMUL_PARSER_H
#define CPUEMUL_PARSER_H

#include <fstream>
#include<iostream>
#include <vector>
#include <regex>
#include "../Command/Command.h"
#include "../Command/Command.cpp"
#include "../exceptions/exceptions.h"

class Parser {
public:
    std::ifstream file;
    std::vector<Command> parsed_info;

    explicit Parser(std::string  &filepath);
    ~Parser();
    static Command read_string(std::string &);
};
#endif //CPUEMUL_PARSER_H
