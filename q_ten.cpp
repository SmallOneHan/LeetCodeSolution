#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int s_p = 0;
        int p_p = 0;
        int s_size = s.size();
        int p_size = p.size();

        while(s_p < s_size and p_p < p_size){
            // 如果当前正则表达式字符为小写字母
            if(islower(p[p_p])){

                //该字符不是最后一个字符，且下一个字符是 *
                if(p_p + 1 < p_size and p[p_p + 1] == '*'){

                    if(p_p + 2 == p_size){
                        while (s_p < s_size and s[s_p] == p[p_p])
                        {
                           s_p++;
                        }
                        if(s_p != s_size){
                            return false;
                        }else{
                            return true;
                        }
                    }
                    
                    char next_char = p[p_p+2];
                    while(1){
                        if(s[s_p] != p[p_p]){
                            break;
                        }else{
                            if (this->isMatch(s.substr(s_p, s_size), p.substr(p_p + 2, p_size))){
                                return true;
                            }else{
                                s_p++;
                                if (s_p == s_size){
                                    return false;
                                }
                            }
                        }

                    }

                    p_p += 2;
                }else
                {
                    if(s[s_p] == p[p_p]){
                        s_p++;
                        p_p++;
                    }else
                    {
                        return false;
                    }
                }
            }else
            {
                //该字符不是最后一个字符，且下一个字符是 *
                if(p_p + 1 < p_size and p[p_p + 1] == '*'){
                    if(p_p + 2 == p_size){
                        return true;
                    }
                    char next_char = p[p_p+2];
                    while(1){
                        if(s[s_p] != next_char)
                            s_p++;
                            if (s_p >= s_size){
                                return false;
                            }
                        else{
                            if(this->isMatch(s.substr(s_p, s_size), p.substr(p_p + 2, p_size))){
                                return true;
                            }else{
                                s_p++;
                                if (s_p >= s_size){
                                    return false;
                                }
                            }
                        }
                    }
                    
                }else
                {
                    s_p++;
                    p_p++;
                }
            }
            
        }

        if(s_p == s_size and p_p == p_size){
            return true;
        }else if(p_p == p_size - 2 and p[p_size - 1] == '*'){
            return true;
        }
        else{
            return false;
        }

    }
};

int main(int argc, char const *argv[])
{
    Solution solotion = Solution();
    bool result = solotion.isMatch("ab", ".*..");
    std::cout << result << std::endl;
    return 0;
}

