#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {

        bool dp[p.size() + 1][s.size() + 1] = {0};
        dp[0][0] = true;
        
        for (int x=1; x <= s.size(); x++){
            dp[0][x] = false;
        }
        
        for (int i=1; i<=p.size(); i++){
            bool isStar = p[i-1] == '*' ? true: false;
            if (isStar)
                dp[i][0] = dp[i-1][0];
            for(int j=1; j<=s.size(); j++){
                if (isStar){
                    dp[i][j] = (dp[i][j-1] || dp[i-1][j]);
                }else{
                    dp[i][j] = dp[i-1][j-1] and (s[j-1] == p[i-1] or p[i-1] == '?');
                }
                // cout << dp[i][j] << endl;
            }
        }
        return dp[p.size()][s.size()];
    }
};


int main(int argc, char const *argv[])
{
    Solution solotion = Solution();
    bool result = solotion.isMatch("aab", "c*a*b");
    std::cout << result << std::endl;
    return 0;
}