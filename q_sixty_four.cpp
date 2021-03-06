#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int dp[m][n] = {0};
        dp[0][0] = grid[0][0];

        for (int i = 1; i < m; i++){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }

        for (int i = 1; i < n; i++){
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }

        for (int i = 1; i< m; i++){

            for (int j = 1; j < n; j++){
                int prev = dp[i - 1][j] < dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
                dp[i][j] = prev + grid[i][j];
            }
        }

        return dp[m-1][n-1];
    }
};

int main(int argc, char const *argv[])
{
    Solution solotion = Solution();

    vector<vector<int>> grid = {{1, 3, 1},
                                {1, 5, 1},
                                {4, 2, 1}};

    int result = solotion.minPathSum(grid);
    std::cout << result << std::endl;
    return 0;
}