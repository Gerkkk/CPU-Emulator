#ifndef CPUEMUL_COMMAND_H
#define CPUEMUL_COMMAND_H
#include<iostream>

class Command{
public:
    std::string type;
    std::string val;
    explicit Command(std::string &type, std::string &val);
    ~Command() = default;
};

#endif //CPUEMUL_COMMAND_H
