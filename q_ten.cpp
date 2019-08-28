#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int s_p, p_p = 0;
        int s_size = s.size();
        int p_size = p.size();

        while(s_p < s_size and p_p < p_size){
            if(islower(p[p_p])){
                if(p_p + 1 < p_size and p[p_p + 1] == '*'){
                    
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
                if(p_p + 1 < p_size and p[p_p + 1] == '*'){
                    
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
            }
            
        }
    }
};