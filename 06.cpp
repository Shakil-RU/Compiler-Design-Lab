/*
Build a lexical analyzer implementing the following regular expressions:
Character variable =ch_(a-zA-Z0-9)(a-zA-Z0-9)*
Binary variable = bn_(a-zA-Z0-9)(a-zA-Z0-9)* 
Binary Number = 0(0|1)(0|1)*
Invalid Input or Undefined = Otherwise
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("06.input.txt", "r", stdin);
    string word;

    while (getline(cin, word))
    {
        bool isValid = true;
        if (word.size() >= 4 && ((word.substr(0, 3) == "ch_") || (word.substr(0, 3) == "bn_")) && isalnum(word[3])) {
            for(int i = 4; i < word.size(); i++) {
                if(!isalnum(word[i])) {
                    isValid = false;
                    break;
                }
            }
            if(isValid) {
                if(word.substr(0, 3) == "ch_") cout << word << " : " << "Character variable\n";
                else cout << word << " : " << "Binary variable\n";
            }
        }
        else if(word.size() >= 2 && word[0] == '0' && (word[1] == '1' || word[1] == '0')) {
            for(int i = 2; i < word.size(); i++) {
                if(word[i] != '0' && word[i] != '1') {
                    isValid = false;
                    break;
                }
            }
            if(isValid) cout << word << " : "<< "Binary Number\n";
        }
        else isValid = false;
        if(!isValid) cout << word << " : "<< "Invalid Input or Undefined\n";
    }
    return 0;
}