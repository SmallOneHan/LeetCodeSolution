#include <limits.h>
#include <iostream>

class Solution
{
public:
    int reverse(int x)
    {
        long result = 0;
        while (x != 0)
        {
            result = result * 10 + x % 10;
            x /= 10;
        }
        return (result > INT_MAX || result < INT_MIN) ? 0 : result;
    }
};

int main(int argc, char const *argv[])
{
    auto solotion = Solution();
    auto result = solotion.reverse(345);
    std::cout << result << std::endl;
    return 0;
}
