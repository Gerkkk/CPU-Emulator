#include "Parser/parser.h"

using namespace stack;

class CPU {
public:
    Stack<int> data_stack;
    std::vector<Command> program;
    int cur;
    int registers[8]{};
    std::map<std::string, int> labels;

    explicit CPU(std::string &filepath) {
        Parser parser = Parser(filepath);
        program = parser.parsed_info;

        for (int i = 0; i < program.size(); i++) {
            if (program[i].type == "label") {
                labels[program[i].val] = i;
            }
        }

        cur = 0;
        while (program[cur].type != "beg") {
            ++cur;
        }
        data_stack = Stack<int>();
    };

    void execute_program() {
        while (program[cur].type != "end") {
            program[cur].execute(data_stack, cur, registers, labels);
        }
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

int main(int argc, char *argv[]) {

    if (argc == 1) {
        std::cout << "Please enter path to your program" << std::endl;
    } else {
        std::string path = "";

        int i = 0;
        while (argv[1][i] != '\0') {
            path.push_back(argv[1][i]);
            i++;
        }

        CPU cpu = CPU(path);
        cpu.execute_program();
    }
}
