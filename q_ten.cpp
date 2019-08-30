#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        bool dp[p.size()+1][s.size()+1] = {false};

        for(int i=0; i<=p.size();){
            bool wild_card = i<p.size() and p[i+1] == '*'? true: false;

            for (int j=0; j<s.size();){
                dp[i][j] == true;
                if(wild_card){
                    dp[i]
                }
            }
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
