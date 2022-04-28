//
//  main.cpp
//  Two Sum
//
//  Created by Muhle Musa Khumalo on 2021/12/1.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> twoNums;
        for(int i=0; i<nums.size()-1; i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
                if(nums[i]+nums[j] == target)
                {
                    twoNums.push_back(i);
                    twoNums.push_back(j);
                }
                    
            }
        }
        return twoNums;
    }
};

int main(int argc, const char * argv[]) {
    Solution s1;
    vector<int> vec= {2,7,11,15};
    int target = 9;
    vector<int> twoSum;
    twoSum = s1.twoSum(vec, target);
    for(auto x:twoSum)
        cout << x << " ";
    
    return 0;
}
