#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cctype>
#include <limits>
#include <cstdlib>

class Modulars {
public:
    int mod;

    int modular_addition(int a, int b) {
        return (a + b) % mod;
    }

    int modular_subtraction(int a, int b) {
        return (a - b + mod) % mod;
    }

    int modular_multiplication(int a, int b) {
        return (a * b) % mod;
    }

    int modular_exponential(int a, int b) {
        int result = 1;
        a = a % mod;
        while (b > 0) {
            if (b % 2 == 1)
                result = (result * a) % mod;
            b = b / 2;
            a = (a * a) % mod;
        }
        return result;
    }

    void modular_congruence(int a, int b) {
        if ((a - b) % mod == 0)
            cout << a << " is congruent to " << b << " mod " << mod << endl;
        else
            cout << a << " is not congruent to " << b << " mod " << mod << endl;
    }

    int evaluate_expression(const string &expression) {
        vector<string> tokens = tokenize(expression);
        vector<string> postfix = infix_to_postfix(tokens);
        return evaluate_postfix(postfix);
    }

    vector<string> tokenize(const string &expression) {
        vector<string> tokens;
        string token;
        for (char ch : expression) {
            if (isdigit(ch)) {
                token += ch; // Build multi-digit numbers
            } else {
                if (!token.empty()) {
                    tokens.push_back(token);
                    token.clear();
                }
                if (ch != ' ') tokens.push_back(string(1, ch)); // Add operators and parentheses
            }
        }
        if (!token.empty()) tokens.push_back(token); // Add last token
        return tokens;
    }

    vector<string> infix_to_postfix(const vector<string> &tokens) {
        stack<string> ops;
        vector<string> output;

        for (const string &token : tokens) {
            if (isdigit(token[0])) {
                output.push_back(token); // If it's a number, add to output
            } else if (token == "(") {
                ops.push(token); // Push '(' onto stack
            } else if (token == ")") {
                while (!ops.empty() && ops.top() != "(") {
                    output.push_back(ops.top());
                    ops.pop();
                }
                ops.pop(); // Remove '('
            } else {
                while (!ops.empty() && precedence(ops.top()) >= precedence(token)) {
                    output.push_back(ops.top());
                    ops.pop();
                }
                ops.push(token); // Push the current operator
            }
        }

        while (!ops.empty()) { // Pop all the operators from the stack
            output.push_back(ops.top());
            ops.pop();
        }

        return output;
    }

    int evaluate_postfix(const vector<string> &postfix) {
        stack<int> values;

        for (const string &token : postfix) {
            if (isdigit(token[0])) {
                values.push(stoi(token)); // Convert string to int and push onto stack
            } else {
                int b = values.top(); values.pop(); // Second operand
                int a = values.top(); values.pop(); // First operand
                int result = perform_operation(a, b, token);
                values.push(result); // Push result onto stack
            }
        }

        return values.top(); // Return the final result
    }

    int perform_operation(int a, int b, const string &op) {
        if (op == "+") {
            return modular_addition(a, b);
        } else if (op == "-") {
            return modular_subtraction(a, b);
        } else if (op == "*") {
            return modular_multiplication(a, b);
        } else if (op == "^") {
            return modular_exponential(a, b);
        }
        return 0;
    }

    int precedence(const string &op) {
        if (op == "^") return 3;
        if (op == "*" || op == "/") return 2;
        if (op == "+" || op == "-") return 1;
        return 0;
    }

    int decision() {
        system("cls");
        cout << "\n\n| ======= MODULAR ARITHMETIC ======= |\n\n";
        bool run = true;
        string expression;
        char decision;
        int a, b;

        cout << "Enter the modulus (mod): ";
        cin >> mod;
        cin.ignore();

        while (run) {
            cout << "\nChoices: \n";
            cout << "A.) Modular Addition (e.g., '5 + 3')\n";
            cout << "B.) Modular Subtraction (e.g., '5 - 3')\n";
            cout << "C.) Modular Multiplication (e.g., '5 * 3')\n";
            cout << "D.) Modular Exponentiation (e.g., '5 ^ 3')\n";
            cout << "E.) Modular Congruence\n";
            cout << "F.) Evaluate Expression (e.g., '(5 + 3) * 2 - (2 ^ 2)')\n";
            cout << "Q) Quit to menu\n";
            cout << "Your choice: ";
            cin >> decision;
            cin.ignore();

            switch (toupper(decision)) {
                case 'A':
                case 'B':
                case 'C':
                case 'D':
                case 'F':
                    cout << "\nEnter the expression you wish to calculate: ";
                    getline(cin, expression);
                    int result;
                    result = evaluate_expression(expression);
                    cout << "\nResult: " << result << " mod " << mod << " = " << (result % mod) << endl;
                    again();
                    run = false;
                    break;

                case 'E':
                    cout << "Enter two numbers to check congruence: ";
                    cin >> a >> b;
                    modular_congruence(a, b);
                    cin.ignore();
                    again();
                    run = false;
                    break;

                case 'Q':
                    return main();
                    run = false;
                    break;

                default:
                    cout << "\n\n|| ===== INVALID ====== ||\n\n";
                    again();
                    run = false;
                    break;
            }
        }
        return 0;
    }
};
