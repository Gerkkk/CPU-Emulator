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

    CommandList com_map = CommandList();
    for (const auto &cur_type : com_map.commands) {
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
