#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    //  动态规划 - 使用柱状图的优化暴力方法
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int len_y = matrix.size();
        if (len_y == 0){
            return 0;
        } 
        int len_x = matrix[0].size();
        int max_area = 0;

        int dp[len_y][len_x] = {0};

        // 对每一行从右到左计算最大宽度
        for (int j=0; j<len_y; j++){
            int len = 0;
            for (int i=0; i<len_x; i++){
                if (matrix[j][i] == '1')
                    len++;
                else
                    len=0;
                
                dp[j][i] = len; 

                if (len==0)
                    continue;

                int width = dp[j][i];
                for (int k=j; k>=0; k--){
                    width = min(width, dp[k][i]);
                    max_area = max(width * (j - k + 1), max_area);
                    int b = 1;
                }
            }
        }

        return max_area;
    }

    //动态规划，空间复杂度N，时间复杂度M*N
    int maximalRectangle2(vector<vector<char>> &matrix)
    {
        int len_y = matrix.size();
        if (len_y == 0){
            return 0;
        } 
        int len_x = matrix[0].size();

        int max_area = 0;

        int l[len_x] = {0};
        int r[len_x] = {len_x};
        int h[len_x] = {0};

        for (int i = 0; i < len_x; i++){
            l[i] = 0;
            r[i] = len_x;
            h[i] = 0;
        }

        for (int i = 0; i<len_y; i++){
            int cur_left = 0;
            int cur_right = len_x;

            // 更新h
            for (int j = 0; j<len_x; j++){
                h[j] = matrix[i][j] == '1' ? h[j]+1: 0;
                cout<<h[j]<<endl;
            }
            
            // 更新l
            for (int j = 0; j<len_x; j++){
                if (matrix[i][j] == '1'){
                    l[j] = max(cur_left, l[j]);
                }else{
                    l[j] = 0;
                    cur_left = j + 1;
                }
                cout << l[j] << endl;
            }

            // 更新r
            for (int j = len_x - 1; j>=0; j--){
                if (matrix[i][j] == '1'){
                    r[j] = min(cur_right, r[j]);
                }else{
                    r[j] = len_x;
                    cur_right = j;
                }
                cout << r[j] << endl;
            }

            // 更新最大面积
            for (int j = 0; j<len_x; j++){
                max_area = max(max_area, h[j] * (r[j] - l[j]));
            }
        }
        return max_area;
    }
};

int main(int argc, char const *argv[])
{
    Solution solotion = Solution();

    vector<vector<char>> matrix = {{'1'}};

    int result = solotion.maximalRectangle2(matrix);
    std::cout << result << std::endl;
    return 0;
}