#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        bool dp[p.size()+1][s.size()+1] = {false};
        dp[0][0] = true;
        for (int j = 1; j < s.size() + 1; j++)
            dp[0][j] = s.size() == 0;
        for (int i = 1; i < p.size() + 1; i++) {
            bool ast = p[i-1] == '*';
            dp[i][0] = ast && dp[i-2][0];
            for (int j = 1; j < s.size() + 1; j++)
                dp[i][j] = ast && dp[i-2][j] || (p[i-1-ast] == '.' || p[i-1-ast] == s[j-1]) && dp[i-1+ast][j-1];
        }
        return dp[p.size()][s.size()];
    }
};
int main(int argc, char const *argv[])
{
    Solution solotion = Solution();
    bool result = solotion.isMatch("ab", "**..");
    std::cout << result << std::endl;
    return 0;
}
