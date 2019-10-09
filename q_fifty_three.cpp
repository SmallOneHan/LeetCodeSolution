#include<vector>
#include<iostream>

using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT32_MIN;
        int sum = 0;

        for (int i=0; i < nums.size(); i++){

            sum += nums[i];
            
            ans = sum > ans ? sum: ans;

            if (sum < 0){
                sum = 0;
            }
            
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution solotion = Solution();
    int array[] = {1, -2, 2, 3};
    vector<int> height(array, array + 4);
    int result = solotion.maxSubArray(height);
    std::cout << result << std::endl;
    return 0;
}

