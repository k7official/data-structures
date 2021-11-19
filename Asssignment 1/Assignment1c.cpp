#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>
#include<sstream>

using namespace std;

void display(map<char, int> letters){
    for(auto pair : letters){
        cout << pair.first << " ";//first is the key
        for(int i=0;i<pair.second; i++){//second is the value
            cout << "*";
        }
        cout << pair.second << endl;
    }

}

int main()
{
    string line;
    string word;
    ifstream my_file;
    map<char, int> letters; //key-value pairs, key is the letter, value is the number of times it appears
    my_file.open("/Users/musa.official/Desktop/projects/++projects/example.txt");
    if(my_file.is_open())
    {
        cout << "success n00b" << endl;
        while(getline(my_file, line))
        {
            char c{};//getting each letter from each word
            stringstream ss(line);//put the line in sstream stream
            while(ss >> word){
                for(int i=0; i<word.length(); i++){
                    c = word[i];
                    letters[c]++;//increament the value at each letter key if present, if not a new key value pair will be created
                }
            }
        }
        display(letters);
        my_file.close();//be polite and close the file:)
    }
    else cerr << "Unable to open file" << endl;

    return 0;
}
