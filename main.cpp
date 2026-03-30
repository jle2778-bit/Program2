#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cctype>

#include "ArrayStack.h"

using namespace std;

// Token

struct Token {
    string value;   // number, operator, or parenthesis
};

// Tokenizer

vector<Token> tokenize(const string& line) {
    vector<Token> tokens;
    // TODO
    return tokens;
}

// Helpers

bool isOperator(const string& s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
}

int precedence(const string& op) {
    // TODO
    return 0;
}

// Detection

bool isValidPostfix(const vector<Token>& tokens) {
    // TODO
    return false;
}

bool isValidInfix(const vector<Token>& tokens) {
    // TODO
    return false;
}

// Conversion

vector<Token> infixToPostfix(const vector<Token>& tokens) {
    vector<Token> output;
    // TODO
    return output;
}

// Evaluation

double evalPostfix(const vector<Token>& tokens) {
    ArrayStack<double> stack;
    // TODO
    return 0.0;
}

// Main

int main() {
    /*
    string line;
    getline(cin, line);

    vector<Token> tokens = tokenize(line);

    if (isValidPostfix(tokens)) {
        cout << "FORMAT: POSTFIX\n";
        cout << "RESULT: " << evalPostfix(tokens) << "\n";
    }
    else if (isValidInfix(tokens)) {
        vector<Token> postfix = infixToPostfix(tokens);
        cout << "FORMAT: INFIX\n";
        cout << "POSTFIX: ";
        for (const auto& t : postfix) {
            cout << t.value << " ";
        }
        cout << "\n";
        cout << "RESULT: " << evalPostfix(postfix) << "\n";
    }
    else {
        cout << "FORMAT: NEITHER\n";
        cout << "ERROR: invalid expression\n";
    }

    return 0;
    */

    cout << "----- ARRAYSTACK TEST -----" << endl;
    ArrayStack<int> testNonEmpty;
    testNonEmpty.push(1);
    testNonEmpty.push(2);
    testNonEmpty.push(3);
    testNonEmpty.push(4);

    cout << "Is Stack empty?"  << endl;
    std::cout << testNonEmpty.empty() << std::endl;
    cout << endl;

    cout << "Size and top element before push" << endl;
    cout << "Size:" << testNonEmpty.size() << endl;

    cout << "Top:" << testNonEmpty.top() << endl;

    std::cout << std::endl;

    testNonEmpty.push(1);
    cout << "Size and top element after push" << endl;
    cout << "Size:" << testNonEmpty.size() << endl;
    cout << "Top:" << testNonEmpty.top() << endl;

    cout << endl;

    cout << "Empty List to Test Errors" << endl;
    int sizeBeforePop = testNonEmpty.size();
    for (int i = 0; i < sizeBeforePop; i++) {
        testNonEmpty.pop();
    }

    cout << "Size:" << testNonEmpty.size() << endl;
    cout << "Is Stack Empty:" << testNonEmpty.empty() << endl;
    cout << "Top:" << testNonEmpty.top() << endl;
    testNonEmpty.pop();


    // Both Top and Pop throw errors accordingly.
}
