#include "../Stack/stack.h"
#include "Parser/parser.h"

using namespace stack;

class CPU{
public:
    Stack<int> data_stack;
    std::vector<Command> program;
    int cur;
    int registers[8]{};

    explicit CPU(std::string  &filepath) {
        Parser parser = Parser(filepath);
        program = parser.parsed_info;

        cur = 0;
        while (program[cur].type != "beg") {
            ++cur;
        }
        data_stack = Stack<int>();
    };

    ~CPU() = default;

    void execute_program() {
        while (program[cur].type != "end") {
            execute_cur();
        }
    }

    void execute_cur() {
        if (program[cur].type == "push") {
            int real_arg = std::stoi(program[cur].val);
            data_stack.push(real_arg);
        } else if (program[cur].type == "pop") {
            data_stack.pop();
        } else if (program[cur].type == "in") {
            int new_val;
            std::cin >> new_val;
            data_stack.push(new_val);
        } else if (program[cur].type == "out") {
            int out_el = data_stack.top();
            std::cout << out_el << std::endl;
            data_stack.pop();
        } else if (program[cur].type == "add") {
            int b = data_stack.top();
            data_stack.pop();
            int a = data_stack.top();
            data_stack.pop();
            int c = a + b;
            data_stack.push(a);
            data_stack.push(b);
            data_stack.push(c);
        } else if (program[cur].type == "sub") {
            int b = data_stack.top();
            data_stack.pop();
            int a = data_stack.top();
            data_stack.pop();
            int c = a - b;
            data_stack.push(a);
            data_stack.push(b);
            data_stack.push(c);
        } else if (program[cur].type == "mul") {
            int b = data_stack.top();
            data_stack.pop();
            int a = data_stack.top();
            data_stack.pop();
            int c = a * b;
            data_stack.push(a);
            data_stack.push(b);
            data_stack.push(c);
        } else if (program[cur].type == "div") {
            int b = data_stack.top();
            data_stack.pop();
            int a = data_stack.top();
            data_stack.pop();
            int c = a / b;
            data_stack.push(a);
            data_stack.push(b);
            data_stack.push(c);
        } else if (program[cur].type == "pushr") {
            if (program[cur].val.size() == 2 && program[cur].val[1] == 'X' &&
                program[cur].val[0] - 'A' >= 0 && program[cur].val[0] - 'A' <= 7)  {
                data_stack.push(registers[program[cur].val[0] - 'A']);
            } else {
                throw RegisterException(program[cur].val + " - No such register");
            }
        } else if (program[cur].type == "popr") {
            if (program[cur].val.size() == 2 && program[cur].val[1] == 'X' &&
                program[cur].val[0] - 'A' >= 0 && program[cur].val[0] - 'A' <= 7)  {
                registers[program[cur].val[0] - 'A'] = data_stack.top();
                data_stack.pop();
            } else {
                throw RegisterException(program[cur].val + " - No such register");
            }
        }
        ++cur;
    }
};

//int main(int argc, char *argv[]){
//
//    for (int i = 1; i < argc; i++) {
//        //"./fibb.txt"
//        std::string path = argv[i];
//        CPU cpu = CPU(path);
//        cpu.execute_program();
//    }
//}

int main(){
    std::string path = "../fibb.txt";
    CPU cpu = CPU(path);
    cpu.execute_program();
}
