#include <gtest/gtest.h>

#include "stack.h"
using namespace stack;

TEST(Int, int1) {
    Stack<int> s;

    s.push(1);
    s.push(10);
    s.push(32);
    s.push(765);

    EXPECT_EQ(s.top(), 765);

    s.pop();

    EXPECT_EQ(s.top(), 32);
    EXPECT_EQ(s.empty(), false);

    s.pop();
    s.pop();
    s.pop();
    EXPECT_EQ(s.empty(), true);
}

TEST(Int, int2) {
    Stack<int> s;
    EXPECT_EQ(s.size(), 0);
    EXPECT_EQ(s.empty(), true);

    for(int i = 0; i < 100; i++) {
        s.push(i);
    }

    EXPECT_EQ(s.size(), 100);
    EXPECT_EQ(s.empty(), false);

    for (int i = 99; i >= 0; i--) {
        EXPECT_EQ(s.top(), i);
        s.pop();
    }

    EXPECT_EQ(s.size(), 0);
    EXPECT_EQ(s.empty(), true);
}

TEST(Double, double1) {
    Stack<double> s;
    EXPECT_EQ(s.size(), 0);
    EXPECT_EQ(s.empty(), true);

    s.push(1.12413);
    s.push(-984394.435);
    s.push(-32.234);
    s.push(7435.11231);
    s.push(-7645.34435);
    s.push(76135.75867);
    s.push(-76235.23423);
    s.push(0.0);
    s.push(-765.1);

    EXPECT_EQ(s.top(), -765.1);
    EXPECT_EQ(s.empty(), false);
    EXPECT_EQ(s.size(), 9);

    s.pop();
    EXPECT_EQ(s.top(), 0.0);
    s.pop();
    EXPECT_EQ(s.top(), -76235.23423);
    s.pop();
    EXPECT_EQ(s.top(), 76135.75867);
}

TEST(String, string1) {
    Stack<std::string> s;
    EXPECT_EQ(s.size(), 0);
    EXPECT_EQ(s.empty(), true);

    std::string s1 = "jala123s41d4alsdl-";
    s.push(s1);
    s.push("-984394.435");
    std::string s2;
    s.push(s2);
    s.push("0");

    EXPECT_EQ(s.empty(), false);
    EXPECT_EQ(s.size(), 4);

    EXPECT_EQ(s.top(), "0");
    s.pop();
    EXPECT_EQ(s.top(), "");
    s.pop();
    EXPECT_EQ(s.top(), "-984394.435");
    s.pop();
    EXPECT_EQ(s.top(), "jala123s41d4alsdl-");
}

TEST(String, string2) {
    Stack<std::string> s;
    EXPECT_EQ(s.size(), 0);
    EXPECT_EQ(s.empty(), true);

    for(int i = 0; i < 100; i++) {

        std::string temp = std::to_string(i);
        s.push(temp);
    }

    EXPECT_EQ(s.size(), 100);
    EXPECT_EQ(s.empty(), false);

    for (int i = 99; i >= 0; i--) {
        EXPECT_EQ(s.top(), std::to_string(i));
        s.pop();
    }

    EXPECT_EQ(s.size(), 0);
    EXPECT_EQ(s.empty(), true);
}

TEST(String, string3) {
    Stack<std::string> s;
    EXPECT_THROW(s.pop(), StackException);
    EXPECT_THROW(s.top(), StackException);
}

