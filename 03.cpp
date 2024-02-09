/*
Write a program that abbreviates the following code:
CSE-3141 as Computer Science & Engineering, 3rd year, 1st semester, Compiler Design, Theory.
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("03.input.txt", "r", stdin);
    string input, dept_name;
    getline(cin, input);

    int i = 0;
    while(input[i] != '-') {
        dept_name += input[i];
        i++;
    }

    string code = input.substr(i+1);

    map<string, string> dept_names;
    dept_names["CSE"] = "Computer Science & Engineering";
    dept_names["ICE"] = "Information & Communication Engineering";

    map<char, string> year;
    year['1'] = "1st";
    year['2'] = "2nd";
    year['3'] = "3rd";
    year['4'] = "4th";

    map<char, string> subject;
    subject['1'] = "Software Engineering";
    subject['2'] = "Database Management Systems";
    subject['3'] = "Web Engineering";
    subject['4'] = "Compiler Design";

    map<char, string> course;
    course['1'] = "Theory";
    course['2'] = "Lab";

    cout<<input<<" : "<<dept_names[dept_name]<<", "<<year[code[0]]<<" year, "<<year[code[1]]<<" semester, "<<subject[code[2]]<<", "<<course[code[3]]<<endl;

    return 0;
}