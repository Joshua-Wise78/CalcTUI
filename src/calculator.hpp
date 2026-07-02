#include <iostream>
#include <stdexcept>

class Calculator {
public:
  double calculate(double x, char oper, double y) {
    switch (oper) {
    case '+':
      return x + y;
    case '-':
      return x - y;
    case '*':
      return x * y;
    case '/':
      if (y == 0)
        throw std::runtime_error("Divide by 0 error");
      return x / y;
    default:
      throw std::invalid_argument("Invalid operator");
    }
  };
};
