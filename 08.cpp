/*
Write a program which converts a word of C++ program to its equivalent token.
RESULT:
Input: 646.45
Output: Float
Input: do
Output: Keyword
Input: 554
Output: Integer
Input: abc
Output: Identifier
Input: +
Output: Arithmetic Operator
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
string arithmetic_operators[] = {"+", "-", "*", "/", "%"};
string relational_operators[] = {"==", "!=", "<", ">", "<=", ">="};
string logical_operators[] = {"&&", "||", "!"};
string bitwise_operators[] = {"&", "|", "^", "~", "<<", ">>"};
string assignment_operators[] = {"=", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", "<<=", ">>="};
string increment_decrement_operators[] = {"++", "--"};

int main()
{
    freopen("08.input.txt", "r", stdin);
    string str;
    while (getline(cin, str))
    {
        bool isValid = true;
        if (find(begin(keywords), end(keywords), str) != end(keywords))
        {
            cout << str << " : "
                 << "Keyword\n";
        }
        else if (find(begin(arithmetic_operators), end(arithmetic_operators), str) != end(arithmetic_operators))
        {
            cout << str << " : "
                 << "Arithmetic Operator\n";
        }
        else if (find(begin(relational_operators), end(relational_operators), str) != end(relational_operators))
        {
            cout << str << " : "
                 << "Relational Operator\n";
        }
        else if (find(begin(logical_operators), end(logical_operators), str) != end(logical_operators))
        {
            cout << str << " : "
                 << "Logical Operator\n";
        }
        else if (find(begin(assignment_operators), end(assignment_operators), str) != end(assignment_operators))
        {
            cout << str << " : "
                 << "Assignment Operator\n";
        }
        else if (find(begin(increment_decrement_operators), end(increment_decrement_operators), str) != end(increment_decrement_operators))
        {
            cout << str << " : "
                 << "Increment or Decrement Operator\n";
        }
        // Check identifier
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
        // Check string literal
        else if (str[0] == '"' && str[str.length() - 1] == '"')
        {
            cout << str << " : "
                 << "String Literal\n";
        }
        // Check number : Integer or Float
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
            if (isValid && dot_count == 0)
                cout << str << " : "
                     << "Integer\n";
            else if (isValid && dot_count == 1)
                cout << str << " : "
                     << "Float\n";
            else isValid = false;
        }
        else
        {
            isValid = false;
        }
        if(!isValid) cout << str << " : "<< "Invalid Lexeme\n";
    }
    return 0;
}