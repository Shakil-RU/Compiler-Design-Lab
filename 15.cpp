/*
Write a program to generate a parse tree of predictive parser using the following parsing 
table: 
      id          +          *          (          )          $ 
E   E->TE'                            E->TE'
E'             E'->+TE'                          E'->@      E'->@
T   T->FT'                            T->FT'
T'              T'->@      T'->*FT'              T'->@      T'->@
F   F->id                             F->(E)
*/
#include <bits/stdc++.h>

using namespace std;

map<pair<char, char>, string> table;

bool solve(string str);

int main()
{
    freopen("15.input.txt", "r", stdin);
    string str;
    getline(cin, str);

    table[make_pair('E', 'i')] = "TP";
    table[make_pair('E', '(')] = "TP";
    table[make_pair('P', '+')] = "+TP";
    table[make_pair('P', ')')] = "@";
    table[make_pair('P', '$')] = "@";
    table[make_pair('T', 'i')] = "FQ";
    table[make_pair('T', '(')] = "FQ";
    table[make_pair('Q', '+')] = "@";
    table[make_pair('Q', ')')] = "@";
    table[make_pair('Q', '$')] = "@";
    table[make_pair('Q', '*')] = "*FQ";
    table[make_pair('F', 'i')] = "i";
    table[make_pair('F', '(')] = "(E)";
    cout<<"Input string : "<<str<<endl;
    if(solve(str)) cout<<"Accepted\n";
    else cout<<"Rejected\n";


    return 0;
}

bool solve(string str) {
    stack<pair<int, char>> stk;
    stk.push({0, 'E'});
    int space = 0;
    for(int i = 0; i < str.size(); i++) {
        while(stk.top().second != str[i] && stk.top().second != '@') {
            pair<int, char> front = stk.top();
            if(table[{front.second, str[i]}] == "") {
                return false;
            }
            for(int i = 0; i < front.first; i++) cout<<" ";
            cout<<front.second<<"--->"<<table[{front.second, str[i]}]<<endl;
            space = front.first + 5;
            stk.pop();
            string rightside = table[{front.second, str[i]}];
            reverse(rightside.begin(), rightside.end());
            for(char c : rightside) {
                stk.push({space, c});
            }
        }
        if(stk.top().second == str[i]) {
            stk.pop();
        }
        if(stk.top().second == '@') {
            stk.pop();
            i--;
        }
    }
    while(!stk.empty()) {
        for(int i = 0; i < stk.top().first; i++) cout<<" ";
        cout<<stk.top().second<<"--->"<<'@'<<endl;
        stk.pop();
    }
    return true;
}

// void solve(string str)
// {
//     string stk = "E";
//     int space = 0;
//     for(int i = 0; i < str.size(); i++) {
//         while(stk.front() != str[i] && stk.front() != '@') {
//             for(int i = 0; i < space; i++) cout<<" ";
//             cout<<stk.front()<<"--->"<<table[{stk.front(), str[i]}]<<endl;
//             char front = stk.front();
//             stk.erase(0, 1);
//             stk = table[{front, str[i]}] + stk;
//             space += 5;
//         }
//         if(stk.front() == str[i]) {
//             if(str[i] != 'i') space += 5;
//             stk.erase(0, 1);
//             space -= 10;
//         }
//         else if(stk.front() == '@') {
//             stk.erase(0, 1);
//             i--;
//             space -= 15;
//         }
//         space += 5;
//     }
//     for(int i = 0; i < stk.size(); i++) {
//         space -= 5;
//         for(int i = 0; i < space; i++) cout<<" ";
//         cout<<stk[i]<<"--->"<<'@'<<endl;
//     }
// }