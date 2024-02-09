/*
Write a program that converts the C++ expression to an intermediate code of 
Post-fix notation form.
*/
#include <bits/stdc++.h>
using namespace std;

int precedence(char ch);
string infixtoPostfix(string infix);

int main() {
    freopen("16.input.txt", "r", stdin);
    string infix;
    getline(cin, infix);
    cout<<infixtoPostfix(infix);
    return 0;
}

string infixtoPostfix(string infix) {
    string postfix = "";
    stack<char> stk;
    for(char ch : infix) {
        // add operands to postfix string
        if(tolower(ch) >= 'a' && tolower(ch) <= 'z') {
            postfix += ch;
        }
        // push open parentheses into stack
        else if(ch == '(') stk.push(ch);

        else if(ch == ')') {
            // pop from stack and add to postfix until open parentheses appears
            while (stk.top() != '(')
            {
                postfix += stk.top();
                stk.pop();
            }
            stk.pop();
        }
        // push or pop operator based on their precedence
        else {
            while(!stk.empty() && precedence(ch) <= precedence(stk.top())) {
                postfix += stk.top();
                stk.pop();
            }
            stk.push(ch);
        }          
    }
    while (!stk.empty()) {
        postfix += stk.top();
        stk.pop();
    }
    return postfix;
}

int precedence(char ch) {
    switch (ch)
    {
    case '^':
        return 3;
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}