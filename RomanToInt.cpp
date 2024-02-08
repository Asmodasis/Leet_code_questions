class Solution {
public:
    int romanToInt(string s) {
        int result = 0; 
        for(int i = 0; i < s.size(); ++i){
            if(i == 0){
                switch(s[i]){
                    case 'I':
                    if(s[i+1] == 'V'){
                        result += 4;
                        i++;
                    }else if(s[i+1] == 'X'){
                        result += 9;
                        i++;
                    }else{
                        result += 1;
                        }break;
                    case 'V':
                        result += 5;
                        break;
                    case 'X':
                        result += 10;
                        break;
                    case 'L':
                        result += 50;
                        break;
                    case 'C':
                        result += 100;
                        break;
                    case 'D':
                        result += 500;
                        break;
                    case 'M':
                        result += 1000;
                        break;
                }
            }else{
                switch(s[i]){
                    case 'I':
                    result += 1;
                        break;
                    case 'V':
                    if(s[i-1] == 'I'){ 
                        result += 4;
                        i++;
                    }else 
                        result += 5;
                        break;
                    case 'X':
                    if(s[i-1] == 'I'){ 
                        result += 9;
                        i++;
                    }else if(s[i+1] != 'L' && s[i+1] != 'C')
                        result += 10;
                        break;
                    case 'L':
                    if(s[i-1] == 'X'){ 
                        result += 40;
                        i++;
                    }else 
                        result += 50;
                        break;
                    case 'C':
                    if(s[i-1] == 'X'){
                        result += 90;
                        i++;
                    }else if(s[i+1] != 'D' && s[i+1] != 'M')
                        result += 100;
                        break;
                    case 'D':
                    if(s[i-1] == 'C'){
                        result += 400;
                        i++;
                    }else
                        result += 500;
                        break;
                    case 'M':
                    if(s[i-1] == 'C'){ 
                        result += 900;
                        i++;
                    }else
                        result += 1000;
                        break;
            }
            }
            
            
        }
        return result;
    }
};