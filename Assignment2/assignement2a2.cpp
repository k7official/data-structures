#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int compareWordSets(string str1, string str2)
{

    int return_value;
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    if(str1.compare(str2) == 0)
        return_value = 0; //equivalent
    else if(includes(str1.begin(), str1.end(), str2.begin(), str2.end()))
        return_value = 1; //str1 is the superset
    else if(includes(str2.begin(), str2.end(), str1.begin(), str1.end()))
        return_value = -1; // str1 is a subset of str2
    else
        return_value = INT_MAX;//not comparable
    return return_value;

}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    cout << compareWordSets(str1, str2) << endl;
    return 0;
}
/*Write a function compareWordSets which takes two strings(word sets),
and returns -1, 0, 1, INT_MAX if the first word set is a
proper subset, equivalent, a proper superset, or incomparable to the second word set.*/
