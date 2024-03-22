#include "Command.h"

Command::Command(std::string &typenam, std::string &value) {
    type = typenam;
    val = value;
}

CommandList::CommandList() {
    commands = {
            {{"beg", 0}, std::regex(R"([\s]*beg)")},
            {{"end", 0}, std::regex(R"([\s]*end)")},
            {{"pop", 0}, std::regex(R"([\s]*pop)")},
            {{"add", 0}, std::regex(R"([\s]*add)")},
            {{"sub", 0}, std::regex(R"([\s]*sub)")},
            {{"mul", 0}, std::regex(R"([\s]*mul)")},
            {{"div", 0}, std::regex(R"([\s]*div)")},
            {{"out", 0}, std::regex(R"([\s]*out)")},
            {{"in", 0}, std::regex(R"([\s]*in)")},
            {{"push", 1}, std::regex(R"([\s]*push\s+[\S]+)")},
            {{"pushr", 1}, std::regex(R"([\s]*pushr\s+[\S]+)")},
            {{"popr", 1}, std::regex(R"([\s]*popr\s+[\S]+)")},
            {{"label", 2}, std::regex(R"([\s]*[\S]+:)")},
            {{"end_label", 0}, std::regex(R"(\s*)")},
            {{"jmp", 1}, std::regex(R"([\s]*jmp\s+[\S]+)")},
            {{"jeq", 1}, std::regex(R"([\s]*jeq\s+[\S]+)")},
            {{"jne", 1}, std::regex(R"([\s]*jne\s+[\S]+)")},
            {{"ja", 1}, std::regex(R"([\s]*ja\s+[\S]+)")},
            {{"jae", 1}, std::regex(R"([\s]*jae\s+[\S]+)")},
            {{"jb", 1}, std::regex(R"([\s]*jb\s+[\S]+)")},
            {{"jbe", 1}, std::regex(R"([\s]*jbe\s+[\S]+)")},
            {{"call", 1}, std::regex(R"([\s]*call\s+[\S]+)")},
            {{"ret", 0}, std::regex(R"([\s]*ret\s*)")}
    };
}

void Command::execute(stack::Stack<int> &data_stack, int &cur, int *registers, std::map<std::string, int> &labels) {
    if (type == "push") {
        int real_arg = std::stoi(val);
        data_stack.push(real_arg);
    } else if (type == "pop") {
        data_stack.pop();
    } else if (type == "in") {
        int new_val;
        std::cin >> new_val;
        data_stack.push(new_val);
    } else if (type == "out") {
        int out_el = data_stack.top();
        std::cout << out_el << std::endl;
        data_stack.pop();
    } else if (type == "add") {
        int b = data_stack.top();
        data_stack.pop();
        int a = data_stack.top();
        data_stack.pop();
        int c = a + b;
        data_stack.push(a);
        data_stack.push(b);
        data_stack.push(c);
    } else if (type == "sub") {
        int b = data_stack.top();
        data_stack.pop();
        int a = data_stack.top();
        data_stack.pop();
        int c = a - b;
        data_stack.push(a);
        data_stack.push(b);
        data_stack.push(c);
    } else if (type == "mul") {
        int b = data_stack.top();
        data_stack.pop();
        int a = data_stack.top();
        data_stack.pop();
        int c = a * b;
        data_stack.push(a);
        data_stack.push(b);
        data_stack.push(c);
    } else if (type == "div") {
        int b = data_stack.top();
        data_stack.pop();
        int a = data_stack.top();
        data_stack.pop();
        int c = a / b;
        data_stack.push(a);
        data_stack.push(b);
        data_stack.push(c);
    } else if (type == "pushr") {
        if (val.size() == 2 && val[1] == 'X' &&
            val[0] - 'A' >= 0 && val[0] - 'A' <= 7) {
            data_stack.push(registers[val[0] - 'A']);
        } else {
            throw RegisterException(val + " - No such register");
        }
    } else if (type == "popr") {
        if (val.size() == 2 && val[1] == 'X' &&
            val[0] - 'A' >= 0 && val[0] - 'A' <= 7) {
            registers[val[0] - 'A'] = data_stack.top();
            data_stack.pop();
        } else {
            throw RegisterException(val + " - No such register");
        }
    } else if (type == "jmp") {
        cur = labels[val];
    } else if (type == "jeq") {
        int b = data_stack.top();
        data_stack.pop();
        int a = data_stack.top();
        data_stack.pop();
        if (a == b) {
            cur = labels[val];
        }
    } else if (type == "jne") {
        int b = data_stack.top();
        data_stack.pop();
        int a = data_stack.top();
        data_stack.pop();
        if (a != b) {
            cur = labels[val];
        }
    } else if (type == "ja") {
        int b = data_stack.top();
        data_stack.pop();
        int a = data_stack.top();
        data_stack.pop();
        if (a < b) {
            cur = labels[val];
        }
    } else if (type == "jae") {
        int b = data_stack.top();
        data_stack.pop();
        int a = data_stack.top();
        data_stack.pop();
        if (a <= b) {
            cur = labels[val];
        }
    } else if (type == "jb") {
        int b = data_stack.top();
        data_stack.pop();
        int a = data_stack.top();
        data_stack.pop();
        if (a > b) {
            cur = labels[val];
        }
    } else if (type == "jbe") {
        int b = data_stack.top();
        data_stack.pop();
        int a = data_stack.top();
        data_stack.pop();
        if (a >= b) {
            cur = labels[val];
        }
    } else if (type == "call") {
        data_stack.push(registers[6]);
        data_stack.push(registers[7]);
        registers[7] = cur;
        registers[6] = data_stack.getSize();
        cur = labels[val];
    } else if (type == "ret") {
        cur = registers[7];

        while (data_stack.getSize() > registers[6]) {
            data_stack.pop();
        }
        registers[7] = data_stack.top();
        data_stack.pop();
        registers[6] = data_stack.top();
        data_stack.pop();
    }
    ++cur;
}
