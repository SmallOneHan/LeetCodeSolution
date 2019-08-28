#include <string>
#include<iostream>
#include <limits.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string str)
    {
        long result = 0;
        int symbol = 1;
        bool flag = true;
        for (char ch : str) //ch依次取的是str里面的字符,直到取完为止
        {
            if (flag && ch == ' ')
            {
                continue;
            }

            if(ch == '-' && flag){
                symbol *= -1;
                flag = false;
            }else if(ch == '+' && flag){
                
                flag = false;
            }
            else if (ch >= '0' && ch <= '9')
            {
                result = result * 10 + (ch - '0');
                if (result > INT_MAX)
                {
                    if(symbol == 1){
                        result = INT_MAX;
                    }else
                    {
                        result = INT_MIN;
                    }
                    return result;
                }
                flag = false;
            }else
            {
                if (flag){
                    return 0;
                }else{
                    break;
                }
            } 
        }
        return result * symbol;
    }
};

int main(int argc, char const *argv[])
{
    string str = "43";
    Solution solution = Solution();
    int result = solution.myAtoi(str);
    cout << result << endl;
    return 0;
}
