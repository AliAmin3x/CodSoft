#include <iostream>
using namespace std;

class Calculator {
public:
    double add(double a, double b) {
        return a + b;
    }

    double subtract(double a, double b) {
        return a - b;
    }

    double multiply(double a, double b) {
        return a * b;
    }

    double divide(double a, double b) {
        if (b != 0) {
            return a / b;
        } else {
            cout << "Error! Division by zero is not allowed." << endl;
            return 0; 
        }
    }
};

int main() {
    Calculator calculator;

    double num1, num2;
    char operation;

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;

    switch (operation) {
        case '+':
            cout << num1 << " + " << num2 << " = " << calculator.add(num1, num2) << endl;
            break;
        case '-':
            cout << num1 << " - " << num2 << " = " << calculator.subtract(num1, num2) << endl;
            break;
        case '*':
            cout << num1 << " * " << num2 << " = " << calculator.multiply(num1, num2) << endl;
            break;
        case '/':
            cout << num1 << " / " << num2 << " = " << calculator.divide(num1, num2) << endl;
            break;
        default:
            cout << "Invalid operation! Please choose +, -, *, or /." << endl;
            break;
    }

    return 0;
}
