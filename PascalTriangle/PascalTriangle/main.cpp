//
//  main.cpp
//  PascalTriangle
//
//  Created by Muhle Musa Khumalo on 2021/12/7.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        for(int i=0; i<numRows; i++){
            for(int j=0; j<(numRows-i-1); j++){
                result[i][j] = nCr(i, j);
            }
        }
        return result;
    }
    int fact(int n){//factorial of a number
        int i, fact = 1;
        for(i=n; i>1; i--)
            fact *= i;
        return fact;
    }
    
    int nCr(int n, int r){
        int num = fact(n);
        int denom = fact(r)*fact(n-r);
        return num/denom;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    vector<vector<int>> test;
    test = s.generate(5);

    return 0;
}
