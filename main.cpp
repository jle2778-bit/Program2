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
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == '(' || line[i] == ')') {
            Token p;
            p.value = string(1, line[i]);
            tokens.push_back(p);
        }
        if (line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] == '/') {
            Token p;
            p.value = string(1, line[i]);
            tokens.push_back(p);
        }

        if (isdigit(line[i])) {
            string num;
            while(isdigit(line[i])){
                num += line[i];
                i++;
            }
            Token p;
            p.value = num;
            tokens.push_back(p);
            i--;
        }


    }
    return tokens;
}

// Helpers

bool isOperator(const string& s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
}

int precedence(const string& op) {
    // TODO
    if (op == "+" || op == "-") {
        return 1;
    }
    if (op == "*" || op == "/") {
        return 2;
    }
    return 0;
}

// Detection

bool isValidPostfix(const vector<Token>& tokens) {
    // TODO
    int pFix = 0;
    for (const auto& token : tokens) {
        if (tokens.empty()) {
            return false;
        }
        if (isdigit(token.value[0])) {
           pFix++;
        }
        else if (isOperator(token.value)) {
            if (pFix < 2) {  // having one number and reading in an operation invalidates PostFix
                return false;
            }
            pFix--; // successful operations combine two numbers into one
        }
        else {
            return false;
        }
    }
    return pFix == 1; //if everything goes right, count has to be 1 because of our result
}

bool isValidInfix(const vector<Token>& tokens) {
    // TODO
    if (tokens.empty()) {
        return false;
    }
    bool numberNext = true; //following number operator number pattern, so we expect a number first

    for (const auto& token : tokens) {
        if (numberNext) { // Progress if we are expecting a number, accept the number and then change our status so we expect an operator next
            if (isdigit(token.value[0])) { // Skip this code chunk in the next iteration because numberNext is false
                numberNext = false;
            } else {
                return false;
            }
        }
        else {
            if (isOperator(token.value)) { // Accept an operator and flip the boolean so we take in a number next and dodge this chunk in the next interation.
                numberNext = true;
            } else {
                return false;
            }
        }
    }
    return !numberNext; // InvalidInFix if string ends with an operator which would mean numberNext would have to be true. Flip the boolean when returning it to accuarately see if its valid.

}



// Conversion

vector<Token> infixToPostfix(const vector<Token>& tokens) {
    vector<Token> output;
    ArrayStack<Token> storedOps; // Stack to hold operators
    // TODO
    for (const auto& token : tokens) {

        if (isdigit(token.value[0])) { //any number immediately gets outputted
            output.push_back(token);
        }

        else if (isOperator(token.value)) {
            while (!storedOps.empty() && precedence(storedOps.top().value) > precedence(token.value)) {
                output.push_back(storedOps.top()); // the line above compares the precdent of the operation on the stack and our current one, if the one on the stack is higher, we push it out first.
                storedOps.pop(); // remove precedent operator from top of stack
            }
            storedOps.push(token); //Now is the new top of the stack
        }
    }
    while (!storedOps.empty()) { //push all our remaining operators
        output.push_back(storedOps.top());
        storedOps.pop();
    }
    return output;
}

// Evaluation

double evalPostfix(const vector<Token>& tokens) {
    ArrayStack<double> stack;
    // TODO
    for (const auto& token : tokens) {
        if (isdigit(token.value[0])) {
            stack.push(stod(token.value)); //convert "string" numbers to double and push into stack
        }
        else if (isOperator(token.value)) {
            double b = stack.top();
            stack.pop();            // pop 'b' first to perserve order, "a - b"
            double a = stack.top();
            stack.pop();

            if (token.value == "+") {
                stack.push(a + b);
            }
            else if (token.value == "-") {
                stack.push(a - b);
            }
            else if(token.value == "*") {
                stack.push(a * b);
            }
            else if (token.value == "/") {
                stack.push(a / b);
            }
        }
    }
    return stack.top();
}

// Main

int main() {

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


    /*
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
    */

    /*
    cout << "---- Tokenizer Test ----" << endl;
    string line;
    getline(cin, line);
    vector<Token> tokens = tokenize(line);

    for (const auto& token : tokens) {
        cout << "[" << token.value << "] ";
    }
    */

    cout << "---- Precedance Test ----" << endl;
    cout << precedence("+") << endl;
    cout << precedence("-") << endl;
    cout << precedence("*") << endl;
    cout << precedence("/") << endl;

    return 0;
}
