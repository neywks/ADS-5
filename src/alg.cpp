// Copyright 2025 NNTU-CS
#include <string>
#include <map>
#include <cctype>
#include "tstack.h"

int getPrior(char pr) {
  switch (pr) {
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
    default:
      return 0;
  }
}

std::string infx2pstfx(const std::string& inf) {
  TStack<char> stack;
  std::string res;

  for (char ch : inf) {
    if (std::isdigit(ch)) {
      res += ch;
    } 
    else if (ch == '(') {
      stack.push(ch);
    } 
    else if (ch == ')') {
      while (!stack.isEmpty() && stack.get() != '(') {
        res += stack.pop();
      }
      if (!stack.isEmpty()) {
        stack.pop();
      }
    } 
    else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
      while (!stack.isEmpty() && stack.get() != '(' && getPrior(stack.get()) >= getPrior(ch)) {
        res += stack.pop();
      }
      stack.push(ch);
      }
    }
  while (!stack.isEmpty()) {
    res += stack.pop();
  }
  return res;
}


int eval(const std::string& pref) {
  TStack<int> stack;

  for (char ch : pref) {
    if (std::isdigit(ch)) {
      int num = ch - '0';
      stack.push(num);
    } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
      int ri = stack.pop();
      int le = stack.pop();

      int res = 0;
      if (ch == '+') {
        res = le + ri;
      }
      else if (ch == '-') {
        res = le - ri;
      }
      else if (ch == '*') {
        res = le*ri;
      }
      else if (ch == '/') {
        res = le/ri;
      }
      stack.push(res);
    }
  }
  return stack.pop();
}
