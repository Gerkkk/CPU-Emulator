#include "parser.h"

enum class CommandName {

};

Parser::Parser(std::string &filepath) {
    std::ifstream fin;
    file = std::move(fin);
    file.open(filepath, std::ios::in);

    std::string buf;

    while (std::getline(file, buf, '\n')) {

        Command res = read_string(buf);
        parsed_info.push_back(res);
        buf = "";
    }
}

Parser::~Parser() {
    file.close();
}

Command Parser::read_string(std::string &input) {
    std::string c_type;
    std::string arg;

    std::regex r1 = std::regex(R"(push\s+[\s\S]+)");
    std::regex r2 = std::regex(R"([\s]*push\s+[\S]+)");

    if (regex_match(input, std::regex(R"([\s]*beg)"))) {
        c_type = "beg";
    } else if (regex_match(input, std::regex(R"([\s]*end)"))) {
        c_type = "end";
    } else if (regex_match(input, std::regex(R"([\s]*pop)"))) {
        c_type = "pop";
    } else if (regex_match(input, std::regex(R"([\s]*add)"))) {
        c_type = "add";
    } else if (regex_match(input, std::regex(R"([\s]*sub)"))) {
        c_type = "sub";
    } else if (regex_match(input, std::regex(R"([\s]*mul)"))) {
        c_type = "mul";
    } else if (regex_match(input, std::regex(R"([\s]*div)"))) {
        c_type = "div";
    } else if (regex_match(input, std::regex(R"([\s]*out)"))) {
        c_type = "out";
    } else if (regex_match(input, std::regex(R"([\s]*in)"))) {
        c_type = "in";
    } else if (regex_match(input, std::regex(R"([\s]*push\s+[\S]+)"))) {
        c_type = "push";

        int i = 0;
        std::string a;
        while (input[i] == ' ') {
            ++i;
        }

        while (input[i] != ' ') {
            ++i;
        }

        while (input[i] == ' ') {
            ++i;
        }
        while (i < input.size() && input[i] != ' ' && input[i] != '\n') {
            a.push_back(input[i]);
            ++i;
        }
        arg = a;
    } else if (regex_match(input, std::regex(R"([\s]*pushr\s+[\S]+)"))) {
        c_type = "pushr";

        int i = 0;
        std::string a;
        while (input[i] == ' ') {
            ++i;
        }

        while (input[i] != ' ') {
            ++i;
        }

        while (input[i] == ' ') {
            ++i;
        }
        while (i < input.size() && input[i] != ' ' && input[i] != '\n') {
            a.push_back(input[i]);
            ++i;
        }
        arg = a;
    } else if (regex_match(input, std::regex(R"([\s]*popr\s+[\S]+)"))) {
        c_type = "popr";

        int i = 0;
        std::string a;
        while (input[i] == ' ') {
            ++i;
        }

        while (input[i] != ' ') {
            ++i;
        }

        while (input[i] == ' ') {
            ++i;
        }
        while (i < input.size() && input[i] != ' ' && input[i] != '\n') {
            a.push_back(input[i]);
            ++i;
        }
        arg = a;
    } else if (regex_match(input, std::regex(R"([\s]*[\S]+:)"))) {
        c_type = "label";

        int i = 0;
        std::string a;
        while (input[i] == ' ') {
            ++i;
        }

        while (input[i] != ':') {
            a.push_back(input[i]);
            ++i;
        }
        arg = a;
    } else if (regex_match(input, std::regex(R"(\s*)"))) {
        c_type = "end_label";
    } else if (regex_match(input, std::regex(R"([\s]*jmp\s+[\S]+)"))) {
        c_type = "jmp";

        int i = 0;
        std::string a;
        while (input[i] == ' ') {
            ++i;
        }

        while (input[i] != ' ') {
            ++i;
        }

        while (input[i] == ' ') {
            ++i;
        }
        while (i < input.size() && input[i] != ' ' && input[i] != '\n') {
            a.push_back(input[i]);
            ++i;
        }
        arg = a;
    } else if (regex_match(input, std::regex(R"([\s]*jeq\s+[\S]+)"))) {
        c_type = "jeq";

        int i = 0;
        std::string a;
        while (input[i] == ' ') {
            ++i;
        }

        while (input[i] != ' ') {
            ++i;
        }

        while (input[i] == ' ') {
            ++i;
        }
        while (i < input.size() && input[i] != ' ' && input[i] != '\n') {
            a.push_back(input[i]);
            ++i;
        }
        arg = a;
    } else if (regex_match(input, std::regex(R"([\s]*jne\s+[\S]+)"))) {
        c_type = "jne";

        int i = 0;
        std::string a;
        while (input[i] == ' ') {
            ++i;
        }

        while (input[i] != ' ') {
            ++i;
        }

        while (input[i] == ' ') {
            ++i;
        }
        while (i < input.size() && input[i] != ' ' && input[i] != '\n') {
            a.push_back(input[i]);
            ++i;
        }
        arg = a;
    } else if (regex_match(input, std::regex(R"([\s]*ja\s+[\S]+)"))) {
        c_type = "ja";

        int i = 0;
        std::string a;
        while (input[i] == ' ') {
            ++i;
        }

        while (input[i] != ' ') {
            ++i;
        }

        while (input[i] == ' ') {
            ++i;
        }
        while (i < input.size() && input[i] != ' ' && input[i] != '\n') {
            a.push_back(input[i]);
            ++i;
        }
        arg = a;
    } else if (regex_match(input, std::regex(R"([\s]*jae\s+[\S]+)"))) {
        c_type = "jae";

        int i = 0;
        std::string a;
        while (input[i] == ' ') {
            ++i;
        }

        while (input[i] != ' ') {
            ++i;
        }

        while (input[i] == ' ') {
            ++i;
        }
        while (i < input.size() && input[i] != ' ' && input[i] != '\n') {
            a.push_back(input[i]);
            ++i;
        }
        arg = a;
    } else if (regex_match(input, std::regex(R"([\s]*jb\s+[\S]+)"))) {
        c_type = "jb";

        int i = 0;
        std::string a;
        while (input[i] == ' ') {
            ++i;
        }

        while (input[i] != ' ') {
            ++i;
        }

        while (input[i] == ' ') {
            ++i;
        }
        while (i < input.size() && input[i] != ' ' && input[i] != '\n') {
            a.push_back(input[i]);
            ++i;
        }
        arg = a;
    } else if (regex_match(input, std::regex(R"([\s]*jbe\s+[\S]+)"))) {
        c_type = "jbe";

        int i = 0;
        std::string a;
        while (input[i] == ' ') {
            ++i;
        }

        while (input[i] != ' ') {
            ++i;
        }

        while (input[i] == ' ') {
            ++i;
        }
        while (i < input.size() && input[i] != ' ' && input[i] != '\n') {
            a.push_back(input[i]);
            ++i;
        }
        arg = a;
    } else if (regex_match(input, std::regex(R"([\s]*call\s+[\S]+)"))) {
        c_type = "call";

        int i = 0;
        std::string a;
        while (input[i] == ' ') {
            ++i;
        }

        while (input[i] != ' ') {
            ++i;
        }

        while (input[i] == ' ') {
            ++i;
        }
        while (i < input.size() && input[i] != ' ' && input[i] != '\n') {
            a.push_back(input[i]);
            ++i;
        }
        arg = a;
    } else if (regex_match(input, std::regex(R"([\s]*ret\s*)"))) {
        c_type = "ret";
    } else {
        throw ParserException(input + " - Syntax Error, wrong command");
    }
    Command ret = Command(c_type, arg);
    return ret;
}
