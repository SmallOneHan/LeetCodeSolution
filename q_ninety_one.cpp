#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0){
            return 0;
        }

        if (s[0] == '0'){
            return 0;
        }

        int p1 = 1;
        int p2 = 1;
        int prevNum = 1;
        
        for (int i = 1; i<s.size(); i++){
            int number = atoi(s.substr(i-1, 2).c_str());

            if (number > 26){
                if (s[i] == '0'){
                    return 0;
                }
                p1 = p2;
            }else if(number ==10 || number == 20)
            {
                p2 = p1;
            }else if(number == 0){
                return 0;
            }else if (number < 10){
                p1 = p2;
            }
            else{
                int tmp = p2;
                p2 = p1 + p2;
                p1 = tmp;
            }
                                                                                                                                                                                   
        }

        return p2;
    }
};

int main(int argc, char const *argv[])
{
    Solution solotion = Solution();
    string inputString = "226";
    int result = solotion.numDecodings(inputString);
    std::cout << result << std::endl;
    return 0;
}