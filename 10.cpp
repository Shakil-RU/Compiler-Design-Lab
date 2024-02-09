/*
Write a program to implement a shift reducing parsing.
*/
#include <bits/stdc++.h>
using namespace std;

// map<string, string> rules = {{"E+E", "E"}, {"E*E", "E"}, {"(E)", "E"}, {"a", "E"}};
map<string, string> rules;
string stk = "", input;

void reduce() {
    for (auto rule : rules) {
        if (stk.find(rule.first) != std::string::npos) {
            int position = stk.find(rule.first);
            stk.erase(position); // Remove the right side of the production
            stk += rule.second; // Add the left side of the production
            cout << left << setw(13) << "$" + stk<< right << setw(13) << input + "$" <<right<< "         Reduce " << rule.second << "-->" << rule.first << "\n";
            reduce();
            return;
        }
    }
}

int main()
{
    freopen("10.input.txt", "r", stdin);
    string production;
    int n; // Number of production rules
    cin>>n;
    cin.ignore();
    for(int k = 0; k < n; k++) // Read the grammar from file
    {
        getline(cin, production);
        rules[production.substr(3)] = production[0]; // Left side of the production is key
    }                                                // Right side is the value

    cin >> input; // a+a*(a+a)+a
    cout<<"Stack              "<<"Input            "<<"Action\n";
    cout << left << setw(13) << "$" + stk<< right << setw(13) << input + "$"<<endl;
    for(int i = 0; !input.empty(); i++) {
        stk += input[0]; // Push the terminal into stack
        input.erase(0, 1); // Remove first character from the input
        cout << left << setw(13) << "$" + stk<< right << setw(13) << input + "$" << right<< "         Shift " << stk.back() << "\n";
        reduce();
    }
    if(stk == "E") cout<<"Accepted";
    else cout<<"Rejected";
}