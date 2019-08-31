#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        bool dp[p.size()+1][s.size()+1] = {false};
        dp[0][0] = true;
        for (int j = 1; j < s.size() + 1; j++)
            dp[0][j] = false;
        for (int i = 1; i < p.size() + 1; i++) {
            bool ast = p[i-1] == '*';
            dp[i][0] = ast && dp[i-2][0];
            for (int j = 1; j < s.size() + 1; j++){
                if (ast)
                {
                    dp[i][j] = dp[i-2][j] || (p[i-2] == '.' || p[i-2] == s[j-1]) && dp[i][j-1];
                }else{
                    dp[i][j] = (p[i-1] == '.' || p[i-1] == s[j-1]) && dp[i-1][j-1];
                }
            }
                
        }
        return dp[p.size()][s.size()];
    }
};
int main(int argc, char const *argv[])
{
    Solution solotion = Solution();
    bool result = solotion.isMatch("aa", "a*");
    std::cout << result << std::endl;
    return 0;
}
