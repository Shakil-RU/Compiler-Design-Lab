/*
Write a program that will check an English sentence given in present indefinite form 
to justify whether it is syntactically valid or invalid according to the following Chomsky 
Normal Form: 
S -> SUB PRED 
SUB -> PN | P 
PRED -> V | V N 
PN -> Sagor | Selim | Salma | Nipu 
P -> he | she | i | we | you | they 
N -> book | cow | dog | home | grass | rice | mango 
V -> read | eat | take | run | write
*/
#include <bits/stdc++.h>
using namespace std;
vector<string> subject = {"Sagor", "Selim", "Salma", "Nipu", "he", "she", "I", "we", "you", "they"};
vector<string> verb = {"read", "eat", "take", "run", "write"};
vector<string> noun = {"book", "cow", "dog", "home", "grass", "rice", "mango"};

int main()
{
    freopen("09.input.txt", "r", stdin);
    string input;
    while (getline(cin, input))
    {
        // Store the words of the sentence in an vector
        string word;
        vector<string> words;
        for (char c : input)
        {
            if (c != ' ')
            {
                word += c;
            }
            else
            {
                words.push_back(word);
                word = "";
            }
        }
        // Push the last word
        words.push_back(word);

        bool isValid = true;

        // Check if the sentence has more than 3 or less than 2 words
        if (words.size() > 3 || words.size() < 2)
        {
            isValid = false;
        }
        // Check if the words are in proper sequence;
        else
        {
            if (find(subject.begin(), subject.end(), words[0]) == subject.end())
                isValid = false;
            if (find(verb.begin(), verb.end(), words[1]) == verb.end())
                isValid = false;
            if (words.size() == 3)
            {
                if (find(noun.begin(), noun.end(), words[2]) == noun.end())
                    isValid = false;
            }
        }

        if (isValid)
            cout << input << " : Valid\n";
        else
            cout << input << " : Invalid\n";
    }
    return 0;
}