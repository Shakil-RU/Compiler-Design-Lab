/*
Write a C program that read the following string:
“Md. Tareq Zaman, Part-3, 2011”
a) Count number of words, letters, digits and other characters.
b) Separates letters, digits and others characters.
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("01.input.txt", "r", stdin);
    string input;
    getline(cin, input);

    int word = 1, letter = 0, digit = 0, other_character = 0;
    string letters, digits, other_characters;

    for(char c : input) {
        if(c == ' ') word++; // Number of words are counted using space
        else if(tolower(c) >= 'a' && tolower(c) <= 'z') {
            letter++; letters += c; // Count letter and from a string
        }
        else if(c >= '0' && c <= '9') {
            digit++; digits += c; // Count digit and from a string
        }
        else {
            other_character++; other_characters += c;
        }

    }
    cout<<"Number of words: "<<word<<endl;
    cout<<"Number of letters: "<<letter<<endl;
    cout<<"Number of digits: "<<digit<<endl;
    cout<<"Number other of characters: "<<other_character<<endl;

    cout<<"\nThe letters are: "<<letters<<endl;
    cout<<"The digits are: "<<digits<<endl;
    cout<<"The characters are: "<<other_characters<<endl;
    return 0;
}