class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();


        // character map to numbers
        char map [] = {'0','1','2','3','4','5','6','7','8','9'};

        std::string res = "";

        // the number sign (present or not)
        bool sign = false;        
        // indicator
        bool flagSpace = true, flagSign = true;

        // for char in s   
        for(auto ch : s){
            if(ch == ' ' && flagSpace) continue;        // ignore the leading whitespace only if space is empty for a sign
            else if((ch == '-' || ch == '+') && flagSign){
                // number is negative
                if(ch == '-') sign = true;
                // sign is occupied
                flagSpace = false;
                // sign is negative
                flagSign = false;
            } else if((ch % '0' < 10) && map[ch % '0'] == ch){
                res += ch;
                if(flagSpace) flagSpace = false;
                if(flagSign) flagSign = false;

            }else{ // if any other character is detected
                if(res == "") return 0;
                break;
            }
        }
        long long ans = 0;
        for(auto ch : res){
            ans = ans * 10 + (ch % '0');
            
            // detect the edge cases
            if(sign && -1 * ans <= INT_MIN) return INT_MIN;
            if(!sign &&  ans >= INT_MAX) return INT_MAX;

        }
        if(sign) ans *= -1;
        return (int)ans;
    }
};