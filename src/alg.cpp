// Copyright 2025 NNTU-CS
#include <string>
#include <stack>
#include <cctype>
#include <sstream>
#include <stdexcept>

int getPrior(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}
std::string infx2pstfx(const std::string& inf) {
    std::stack<char> stack;
    std::string result;

    for (char ch : inf) {
        if (std::isdigit(ch)) {
            res += ch;
        } 
        else if (ch == '(') {
            stack.push(ch);
        } 
        else if (ch == ')') {
            while (!stack.empty() && stack.get() != '(') {
                result += stack.top();
                stack.pop();
            }
            if (!stack.empty()) {
                stack.pop();
            }
        } 
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (!stack.empty() && stack.get() != '(' && getPrior(stack.get()) >= getPrior(ch)) {
                res += stack.top();
                stack.pop();
            }
            stack.push(ch);
        }
    }
    while (!stack.empty()) {
        res += stack.top();
        stack.pop();
    }
    return res;
}


int eval(const std::string& pref) {
    std::stack<int> stack;
    
    for (char ch : pref) {
        if (std::isdigit(ch)) {
            int num = ch - '0';
            stack.push(num);
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int right = stack.top();
            stack.pop();
            int left = stack.top();
            stack.pop();
            
            int res = 0;
            if (ch == '+') {
                res = le + ri;
            }
            else if (ch == '-') {
                res = le - ri;
            }
            else if (ch == '*') {
                res = le * ri;
            }
            else if (ch == '/') {
                res = le / ri;
            }
            stack.push(res);
        }
    }
    return stack.top();
}
