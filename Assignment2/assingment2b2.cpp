#include<iostream>
#include<string>
#include <bits/stdc++.h>
using namespace std;


map<string, int> encode(string str){
    unordered_map<unordered_set<char>, int> substrings;
    unordered_set<char> hashset;
    int left = 0;
    int right = 0;
    while(right < str.length()){
        if(!hashset.count(str[right])){
            right++;
            hashset.insert(str[right]);
        }
        else{
            int i = right;
            unordered_set<char> new_str;
            while(hashset.count(str[i])){
                hashset.erase(str[i]);
                new_str.insert(str[i]);
                i++;
            }
            substrings[hashset]++;
            substrings[new_str]++;
            while(new_str.count(str[i])){
                substrings[new_str]++;
                i += new_str.size();
            }
            hashset.clear();
            right = i;
        }
    }
}

int main(){
    string str;
    str = "abcdcdcdabcdcdcd";
    map<string, int> words; 
    //words = encode(str);
    //display(words);
    return 0;
}
/*A simple way to compress a text is to use n[str]
to mean that str appears n times. For example,
“2[ab3[cd]]” denotes “abcdcdcdabcdcdcd”.
Write functions to encode and decode a string
properly. Write main to test them.*/