#include "parser.h"

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

std::string Parser::get_arg(std::string &s) {
    std::regex pattern = std::regex("([ ]*[a-z0-9]+[ ]+)" "([A-Za-z0-9]+)");
    std::smatch sm;
    int result = std::regex_search(s, sm, pattern);
    if (result == 1) {
        return sm[2];
    } else {
        std::cout << s << std::endl;
        throw ParserException("Syntax error in string above");
    }
}

std::string Parser::get_label(std::string &s) {
    std::regex pattern = std::regex("[ ]*" "([a-z0-9]+)" ":");
    std::smatch sm;
    int result = std::regex_search(s, sm, pattern);
    if (result == 1) {
        return sm[1];
    } else {
        std::cout << s << std::endl;
        throw ParserException("Syntax error in string: " + s);
    }
}

Command Parser::read_string(std::string &input) {
    std::string c_type;
    std::string arg;

    std::map<std::pair<std::string, int>, std::regex> commands = {
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

    for (const auto &cur_type : commands) {
        if (regex_match(input, cur_type.second)) {
            c_type = cur_type.first.first;
            if (cur_type.first.second == 1) {
                arg = get_arg(input);
            } else if (cur_type.first.second == 2) {
                arg = get_label(input);
            }
        }

    }

    Command ret = Command(c_type, arg);
    return ret;
}
