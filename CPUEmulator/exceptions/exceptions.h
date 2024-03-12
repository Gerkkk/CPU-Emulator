#ifndef CPUEMUL_EXCEPTIONS_H
#define CPUEMUL_EXCEPTIONS_H
#include <exception>
#include <iostream>

class ParserException: public std::exception{
    public:
        explicit ParserException(std::string &&cur_message) {
            message = std::move(cur_message);
        }

        const char* what() {
            return message.c_str();
        }
    private:
        std::string message;
};

class RegisterException: public std::exception{
public:
    explicit RegisterException(std::string &&cur_message) {
        message = std::move(cur_message);
    }

    const char* what() {
        return message.c_str();
    }
private:
    std::string message;
};
#endif //CPUEMUL_EXCEPTIONS_H
