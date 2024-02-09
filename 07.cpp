/*
Write a program to recognize C++
 i) Keyword ii) Identifier iii) Operator iv) Constant
*/
#include <bits/stdc++.h>
using namespace std;
string keywords[] = {"alignas", "alignof", "and", "and_eq", "asm", "auto", "bitand", "bitor",
                     "bool", "break", "case", "catch", "char", "char8_t", "char16_t", "char32_t",
                     "class", "compl", "concept", "const", "consteval", "constexpr", "const_cast",
                     "continue", "co_await", "co_return", "co_yield", "decltype", "default", "delete",
                     "do", "double", "dynamic_cast", "else", "enum", "explicit", "export", "extern",
                     "false", "float", "for", "friend", "goto", "if", "import", "inline", "include", "int",
                     "long", "module", "mutable", "namespace", "new", "noexcept", "not", "not_eq",
                     "nullptr", "operator", "or", "or_eq", "private", "protected", "public", "register",
                     "reinterpret_cast", "requires", "return", "short", "signed", "sizeof", "static",
                     "static_assert", "static_cast", "struct", "switch", "synchronized", "template",
                     "this", "thread_local", "throw", "true", "try", "typedef", "typeid", "typename",
                     "union", "unsigned", "using", "virtual", "void", "volatile", "wchar_t", "while",
                     "xor", "xor_eq"};
string operators[] = {
    "+", "-", "*", "/", "%",                                           // Arithmetic Operators
    "==", "!=", "<", ">", "<=", ">=",                                  // Relational Operators
    "&&", "||", "!",                                                   // Logical Operators
    "&", "|", "^", "~", "<<", ">>",                                    // Bitwise Operators
    "=", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", "<<=", ">>=", // Assignment Operators
    "++", "--",                                                        // Increment and Decrement Operators
    "?", ":",                                                          // Conditional Operator
    ",",                                                               // Comma Operator
    ".", "->",                                                         // Member Access Operators
    "::"                                                               // Scope Resolution Operator
};

int main()
{
    freopen("07.input.txt", "r", stdin);
    string str;
    while (getline(cin, str))
    {
        bool isValid = true;
        if (find(begin(keywords), end(keywords), str) != end(keywords))
        {
            cout << str << " : "
                 << "Keyword\n";
        }
        else if (find(begin(operators), end(operators), str) != end(operators))
        {
            cout << str << " : "
                 << "Operator\n";
        }
        else if (str[0] == '_' || isalpha(str[0]))
        {
            for (int i = 1; i < str.length(); i++)
            {
                if (!isalnum(str[i]) && str[i] != '_')
                {
                    isValid = false;
                    break;
                }
            }
            if (isValid) cout << str << " : " << "Identifier\n";
        }
        else if (str[0] == '"' && str[str.length() - 1] == '"')
        {
            cout << str << " : " << "Constant\n";
        }
        else if (str[0] == '.' || isdigit(str[0]))
        {
            int dot_count = 0;
            for (char c : str)
            {
                if (!isdigit(c) && c != '.') {
                    isValid = false;
                    break;
                }
                if (c == '.')
                    dot_count++;
            }
            if (isValid && dot_count < 2) cout << str << " : "<< "Constant\n";
            else isValid = false;
        }
        else
        {
            isValid = false;
        }
        if(!isValid) {
            cout << str << " : "<< "Invalid Lexeme\n";
        }
    }
    return 0;
}