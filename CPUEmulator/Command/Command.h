#ifndef CPUEMUL_COMMAND_H
#define CPUEMUL_COMMAND_H
#include<iostream>
#include <regex>
#include <map>
#include "../exceptions/exceptions.h"
#include "../../Stack/stack.h"


class Command{
public:
    std::string type;
    std::string val;
    explicit Command(std::string &type, std::string &val);
    virtual void execute(stack::Stack<int> &, int &cur, int *registers, std::map<std::string, int> &labels);
};

class CommandList{
public:
    explicit CommandList();
    std::map<std::pair<std::string, int>, std::regex> commands;
};

#endif //CPUEMUL_COMMAND_H
