#include<iostream>
#include<ctype.h>
using namespace std;

string clean_string(string str)
{
    string str1;
    for(char &c: str)
    {
        if(isalpha(c))
            str1 += tolower(c);
    }
    return str1;
}


string isPalindrome(string str)
{
    str = clean_string(str);
    for(int i=0; i<str.length()/2; i++)
    {
        if(str[i] != str[str.length()-1-i])
            return "No";
    }
    return "Yes";
}

int main()
{
    string str = "Was it Eliot’s toilet I saw?";
    string str1 = "Don't nod";
    cout << isPalindrome(str)<< endl;
    cout << isPalindrome(str1) << endl;
    return 0;
}
