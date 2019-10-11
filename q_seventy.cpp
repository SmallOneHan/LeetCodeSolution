#include<iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {

        int a = 0;
        int b = 1;

        for (int i = 0; i < n; i++){
            a = b + a;
            int tmp = b;
            b = a;
            a = tmp;
        }

        return b;
    }
};

int main(int argc, char const *argv[])
{
    Solution solotion = Solution();

    int n = 3;
    int result = solotion.climbStairs(n);
    std::cout << result << std::endl;
    return 0;
}