//
//  main.cpp
//  Maximum Subarray
//
//  Created by Muhle Musa Khumalo on 2021/12/1.
//

#include <iostream>
#include <vector>
#include <algorithm>

//Recursive method
class Solution
{
public:
    int globalMaxSum;
    int maxSubArray(std::vector <int> &nums, size_t n)
    {
        if(n==1)
            return nums[0];
        int currMaxSum = std::max(nums[n - 1], maxSubArray(nums, n - 1) + nums[n - 1]);
        globalMaxSum = std::max(globalMaxSum, currMaxSum);
        return currMaxSum;
    }
    int maxSubArray(std::vector<int> &nums) {
            globalMaxSum = nums[0];
            maxSubArray(nums, nums.size());
            return globalMaxSum;
        }
};

//Iterative method
class Solution1 {
public:
    int maxSubArray(std::vector<int> &nums) {
        int globalMaxSum = nums[0], currMaxSum = nums[0];
        for (int ind = 1; ind < nums.size(); ind++) {
            currMaxSum = std::max(currMaxSum + nums[ind], nums[ind]);
            globalMaxSum = std::max(globalMaxSum, currMaxSum);
        }
        return globalMaxSum;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<int> vec1 = {-2,1,-3,4,-1,2,1,-5,4};//6
    std::vector<int> vec2 = {5,4,-1,7,8};
    std::vector<int> vec3 = {1};
    Solution s1;
    std::cout << s1.maxSubArray(vec1)<< std::endl;
    std::cout << s1.maxSubArray(vec2)<< std::endl;
    std::cout << s1.maxSubArray(vec3)<< std::endl;
    return 0;
}

