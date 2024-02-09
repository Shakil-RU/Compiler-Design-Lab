/*
Build a lexical analyzer implementing the following regular expressions:
Float variable = (a-hA-Ho-zO-Z)(a-zA-Z0-9)*
Float Number = 0.(0-9)(0-9)|(1-9)(0-9)*.(0-9)(0-9)
Double Number = 0.(0-9)(0-9)(0-9)+|(1-9)(0-9)*.(0-9)(0-9)(0-9)+
Invalid Input or Undefined = Otherwise
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("05.input.txt", "r", stdin);
    string word;

    while (getline(cin, word))
    {
        bool isValid = true;
        if ((tolower(word[0]) >= 'a' && tolower(word[0]) <= 'h') || (tolower(word[0]) >= 'o' && tolower(word[0]) <= 'z'))
        {
            for (int i = 1; i < word.size(); i++)
            {
                if (!isalnum(word[i]))
                {
                    isValid = false;
                    break;
                }
            }
            if(isValid) cout << word << " : "<< "Float variable\n";
        }
        else if(isdigit(word[0])) {
            int dot_position = -1, dot_count = 0;
            for(int i = 1; i < word.size(); i++) {
                if(word[i] == '.') {
                    dot_position = i;
                    dot_count++;
                }
                if(!isdigit(word[i]) && (word[i] != '.')) {
                    isValid = false;
                    break;
                }
            }
            if(dot_position != -1 && dot_count == 1 && isValid) {
                int fraction = word.substr(dot_position+1).size();
                if(fraction == 2) cout<<word<<" : "<<"Float Number\n";
                else if(fraction > 3) cout<<word<<" : "<<"Double Number\n";
                else isValid = false;
            }
            else {
                isValid = false;
            }
        }
        else {
            isValid = false;
        }
        if(!isValid) cout << word << " : "<< "Invalid Input or Undefined\n";
    }
    return 0;
}