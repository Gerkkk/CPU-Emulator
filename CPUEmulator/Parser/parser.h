#ifndef CPUEMUL_PARSER_H
#define CPUEMUL_PARSER_H

#include <fstream>
#include <vector>
#include "../Command/Command.h"


class Parser {
public:
    std::ifstream file;
    std::vector<Command> parsed_info;

    explicit Parser(std::string  &filepath);
    static Command read_string(std::string &);
    static std::string get_arg(std::string &);
    static std::string get_label(std::string &);
};
#endif //CPUEMUL_PARSER_H
