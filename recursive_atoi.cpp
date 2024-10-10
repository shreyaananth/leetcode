using namespace std;

class Solution {

public:
    int sign ;
    int retInt(string s) {
        if(!s.length() || !isdigit(s[0])){
            return 0;
        }
        

        int last_pos = s.length()-1;
        int num = retInt(s.substr(0, last_pos));
        int digit = s[last_pos]-'0';

        if(num==INT_MAX || num==INT_MIN) {
            return num;
        }
        if(sign>0 && (num > INT_MAX/10 || (num == INT_MAX/10 && digit>=7))) {
            return INT_MAX;
        } 
        if(sign<0 && (-num < INT_MIN/10 || (-num <= INT_MIN/10 && digit>=8))){
            return INT_MIN;
        }
    
        return  digit + num*10;

    }
    
    int myAtoi(string s) {
        int i = 0;
        while(isspace(s[i])){
            i++;
        }

        sign = 1;
        if(s[i] == '-') {
            sign*=-1;
        }
        if(s[i] == '-' || s[i] == '+') {
            i++;
        } 

        while(s[i] == '0'){
            i++;
        }

        int j = i;
        while(isdigit(s[j])) {
            j++;
        }

        int result = retInt(s.substr(i,j-i));
        if((sign > 0 && result == INT_MAX )|| (sign<0 && result == INT_MIN))
            return result;
        return sign*result;
        
    }
};
