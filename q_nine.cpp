#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        long mirror = 0;
        int tmp = x;
        while (x > 0){
            mirror = mirror * 10 + x % 10;
            x /= 10;
        }
        if(tmp == mirror){
            return true;
        }else
        {
            return false;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution solotion = Solution();
    bool result = solotion.isPalindrome(11);
    std::cout << result << std::endl;
    return 0;
}