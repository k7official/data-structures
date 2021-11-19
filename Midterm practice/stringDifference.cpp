#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

void Difference(string s1, string s2)
{
    vector<string> vec1;
    vector<string> vec2;
    vector<string> vec3;
    string word;
    stringstream ss1(s1);
    stringstream ss2(s2);
    while(ss1 >> word)
        vec1.push_back(word);
    while(ss2 >> word)
        vec2.push_back(word);
    for(auto word : vec1)
    {
        auto it = find(vec2. begin(), vec2.end(), word);
        if(it == vec2.end())
        {
            vec3.push_back(word);
        }
    }
    for(auto word : vec3)
    {
        cout << word << " ";
    }
    cout << endl;
}

int main()
{
    string s1 = "To see is to believe";
    string s2 = "What you see is what you get";
    Difference(s1, s2);
    return 0;
}