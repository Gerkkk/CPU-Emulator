#include "stack.h"
using namespace stack;

int main(){
    Stack<std::string> s;
//    s.pop();
    s.push("2");
    s.push("3");
    s.push("4");
    s.push("5");
    s.push("6");
    s.push("7sdfsdfs");
    std::cout << s.top() << std::endl;
    Stack<std::string> s1((Stack<std::string>()));

    return 0;
}
