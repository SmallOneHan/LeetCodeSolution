#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    bool isNumber(string str) {

        int p = 0; //记录指针当前位置
        int str_len = str.size();
        int count[7] = {0};

        str.append(1, '*');  //增加结束标志

        while(str[p] == ' '){
            p++;
        }

        if(str[p] == '+' || str[p] == '-'){
            p++;
            count[0]++;
        }

        while(isdigit(str[p])){
            p++;
            count[1]++;
        }

        if(str[p] == '.'){
            p++;
            count[2]++;
        }

        while(isdigit(str[p])){
            p++;
            count[3]++;
        }

        if(count[3] == 0 and count[1] == 0){
            return false;
        }

        if(str[p] == 'e'){
            p++;
            count[4]++;
        }

        if(str[p] == '+' || str[p] == '-'){
            p++;
            count[5]++;
        }

        if(count[4] == 0 and count[5] > 0){
            return false;
        }

        while(isdigit(str[p])){
            p++;
            count[6]++;
        }

        if(count[4] == 0 and count[6] > 0){
            return false;
        }
        if(count[4] > 0 and count[6] == 0){
            return false;
        }

        while(str[p] == ' '){
            p++;
        }

        if(p == str_len){
            return true;
        }else
        {
            return false;
        }
        
    }
};

int main(int argc, char const *argv[])
{
    Solution solotion = Solution();
    bool result = solotion.isNumber("0e");
    std::cout << result << std::endl;
    return 0;
}
