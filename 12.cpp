/*
Write a program to build a lexical analyzer implementing the following regular 
expressions. It takes a text as input from a file (e.g. input.txt) and display output in 
console mode: E -> EAE|(E)|ID 
              A -> + | - | * | /
              ID -> any valid identifier | any valid integer 
*/
#include <bits/stdc++.h>
using namespace std;
string input;

bool isValidIdentifier(string str) {
    // Check if the string is not empty and the first character is a letter or underscore
    if (str.empty() || !(std::isalpha(str[0]) || str[0] == '_')) {
        return false;
    }

    // Check the rest of the characters
    for (char c : str) {
        if (!(std::isalnum(c) || c == '_')) {
            return false;
        }
    }

    // Check if it is not a C++ keyword
    static const std::string keywords[] = {
        "alignas", "alignof", "and", "and_eq", "asm", "auto", "bitand", "bitor",
        "bool", "break", "case", "catch", "char", "char8_t", "char16_t", "char32_t",
        "class", "compl", "concept", "const", "consteval", "constexpr", "const_cast",
        "continue", "co_await", "co_return", "co_yield", "decltype", "default", "delete",
        "do", "double", "dynamic_cast", "else", "enum", "explicit", "export", "extern",
        "false", "float", "for", "friend", "goto", "if", "inline", "int", "long",
        "mutable", "namespace", "new", "noexcept", "not", "not_eq", "nullptr", "operator",
        "or", "or_eq", "private", "protected", "public", "register", "reinterpret_cast",
        "requires", "return", "short", "signed", "sizeof", "static", "static_assert",
        "static_cast", "struct", "switch", "template", "this", "thread_local", "throw",
        "true", "try", "typedef", "typeid", "typename", "union", "unsigned", "using",
        "virtual", "void", "volatile", "wchar_t", "while", "xor", "xor_eq"
    };

    for (string keyword : keywords) {
        if (str == keyword) {
            return false;
        }
    }

    return true;
}

bool isInteger(string str) {
    for(char c : str) {
        if(!isdigit(c)) return false; // Integer only contains 0-9
    }
    return true;
}

int main() // The program can't handle 8+(5+)8, 8(*)5 types error
{
    freopen("12.input.txt", "r", stdin);
    while(getline(cin, input)) {
        bool isValid = true;
        int operators = 0;
        vector<string> operands;
        string operand;
        stack<char> stk;
        for(char c : input) {
            if(c != '+' && c != '-' && c != '*' && c != '/') {
                if(c == '(') {
                    if(operand.size()) {isValid = false; break;} // 8(5+3) this error will be detected
                    stk.push('(');
                }
                else if(c == ')') {
                    if(!stk.empty() && !operand.empty()) stk.pop(); // ()a+b or )a+b( or 5+(5+)5
                    else {isValid = false; break;}
                }
                else
                    operand += c; // Anything except operators and parenthesis
            }
            else {
                if(operand.size()) // String is not empty
                    operands.push_back(operand);
                operand = "";
                operators++;
            }
        }
        if(operand.size())
            operands.push_back(operand); // Last operand

        for(string operand : operands) { // Not a Integer or Identifier
            if(!isValidIdentifier(operand) && !isInteger(operand)) {
                isValid = false;
                break;
            }
        }

        // Operator and parenthesis check
        if(isValid && (operands.size()-1 == operators) && stk.empty()) {
            cout<<input<<": Valid\n";
        }
        else {
            cout<<input<<": Invalid\n";
        }
    }
}