#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left_x = 0;
        int right_x = height.size() - 1;
        int left_y = height[left_x];
        int right_y = height[right_x];
        int max_area = (height.size() - 1) * min(left_y, right_y);
        while (left_x < right_x)
        {
            bool flag = left_y >= right_y;
            if (flag)
            {
                right_y = height[--right_x];
            }
            else
            {
                left_y = height[++left_x];
            }
            int area = (right_x - left_x) * min(left_y, right_y);
            max_area = max_area >= area ? max_area : area;
        }

        return max_area;
    }
};

int main(int argc, char const *argv[])
{
    Solution solotion = Solution();
    int array[] = {1, 2, 3};
    vector<int> height(array, array + 3);
    int result = solotion.maxArea(height);
    std::cout << result << std::endl;
    return 0;
}
