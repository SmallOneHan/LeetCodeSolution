#include<string>
#include<algorithm>
#include<iostream>

using namespace std;

class Solution {
public:

    int longestValidParentheses(string s) {
        // 申请一个int 类型的数组，dp[s.size()], dp[i]表示前i个字符可组成的最长符合条件的字符串
        int strLen = s.size();
        int dp[strLen + 1] = {0};

        int maxLen = 0;
        dp[0] = 0;

        for (int i=1; i < s.size(); i++){

            if (s[i] == ')'){
                if (s[i-1] == '('){
                    dp[i] = 2 + (i - 2 >= 0 ? dp[i-2]:0);
                }else if(i - dp[i-1] > 0 and s[i - dp[i-1] - 1] == '('){

                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    
    }
};

int main(int argc, char const *argv[])
{
    Solution solotion = Solution();
    int result = solotion.longestValidParentheses("");
    cout << result << endl;
    return 0;
} 