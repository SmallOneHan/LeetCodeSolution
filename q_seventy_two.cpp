#include<iostream>
#include<string>

using namespace std;

int min_three(int a, int b, int c){
    return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

class Solution {
public:
    int minDistance(string word1, string word2) {
        int dp[word1.size() + 1][word2.size() + 1] = {0};

        for (int i=0; i<=word1.size(); i++){
            dp[i][0] = i;
        }
        for (int j=0; j<=word2.size(); j++){
            dp[0][j] = j;
        }

        for (int i = 1; i<=word1.size(); i++){
            for (int j = 1; j <= word2.size(); j++){

                if (word1[i-1] == word2[j-1]){
                    dp[i][j] = min_three(dp[i-1][j-1], dp[i-1][j] + 1, dp[i][j-1] + 1);
                }else{
                    dp[i][j] = min_three(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1;
                }
                // cout<<dp[i][j]<<endl;
            }
        }
        
        return dp[word1.size()][word2.size()];
    }
};

int main(int argc, char const *argv[])
{
    Solution solotion = Solution();
    int result = solotion.minDistance("", "a");
    std::cout << result << std::endl;
    return 0;
}