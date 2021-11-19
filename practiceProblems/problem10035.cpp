#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    size_t num1, num2;
    cin >> num1 >> num2;
    while(num1 != 0 && num2 != 0)
    {
        string num11 = to_string(num1);
        string num22 = to_string(num2);
        int m = 0;
        for(char c: num11)
            m++;
        vector<char> vec1;
        vector<char> vec2;
        for (auto c : num11)
            vec1.push_back(c);
        for (auto c : num22)
            vec2.push_back(c);
        bool is_carry = false;
        int num_carry = 0;
        for(int i=m-1; i>=0; i--)
        {
            int sum = 0;
            const int carry = 1;
            if(is_carry == true){
                sum = (vec1[i] - '0') + (vec2[i] - '0') + carry;
            }
            else {
                sum = (vec1[i] -'0')  + (vec2[i] - '0');
                is_carry = false;
            }
            if(sum > 9){
                is_carry = true;
                num_carry++;
            }          
        }
        if(num_carry == 0)
            cout << "No carry operations." << endl;
        else cout << num_carry << " carry operations." << endl;

        cin >> num1 >> num2;
    }
    return 0;
}