/*
Write a program to generate a syntax tree for the sentence a+b*c with the following 
grammar: E —> E+E|E-E|E*E|E/E|(E)|a|b|c 
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

bool isOperand(char c);
bool isOperator(char c);
int precedence(char c);
string infixtoPostfix(string infix);
Node* parse(string str);
void print(Node* root, int space = 0, int indent = 4) { // Inorder traversal of tree
    if (root == NULL) return;
    space += indent;
    print(root->right, space);
    cout<<endl;
    for (int i = indent; i < space; i++) {
        cout << " ";
    }
    cout << root->data;
    print(root->left, space);
}

int main() {
    freopen("11.input.txt", "r", stdin);
    string str;
    getline(cin, str);
    str = infixtoPostfix(str);
    Node* tree = parse(str);
    print(tree);
    cout<<endl;
    return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool isOperand(char c) {
    return isalnum(c);
}

int precedence(char c) {
    switch (c)
    {
    case '^':
    case '/':
    case '*':
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
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

Node* parse(string str) {
    stack<Node*> stack;
    for (char ch : str) {
        if (isOperand(ch)) {
            Node* node = new Node(ch);
            stack.push(node);
        }
        // If the character is an operator, create a node and pop two nodes from the stack as its children
        else if (isOperator(ch)) {
            Node* node = new Node(ch);
            node->right = stack.top();
            stack.pop();
            node->left = stack.top();
            stack.pop();
            stack.push(node);
        }
    }
    return stack.top();
}