#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:

    //递归法求解
    bool isScramble(string s1, string s2) {
        //如果字符串长度不相等，则不是反向字符串
        if (s1.size() != s2.size()){
            return false;
        }

        // 如果两个字符串完全相等，则是反向字符串
        if (s1 == s2){
            return true;
        }

        // 判断两个字符串的字符数是否相等
        string ss1(s1);
		string ss2(s2);
		sort(ss1.begin(), ss1.end());
        sort(ss2.begin(), ss2.end());

        // 不相等返回错误
        if (ss1 != ss2){
            return false;
        }

        for (int i = 1; i<s1.size(); i++){
            // 正向对比
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, s1.size()), s2.substr(i, s2.size())))
                return true;
            
            //反向对比
            if (isScramble(s1.substr(0, i), s2.substr(s2.size() - i, s2.size())) && isScramble(s1.substr(i, s1.size()), s2.substr(0, s2.size() - i)))
                return true;
        }

        return false;


    }
};

int main(int argc, char const *argv[])
{
    Solution solotion = Solution();
    int result = solotion.isScramble("abc", "bca");
    std::cout << result << std::endl;
    return 0;
}