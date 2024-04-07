class Solution {
public:
    int divide(int dividend, int divisor) {
        int returnVal = 0; 
        bool negativeSign = false;
        // Detect negative sign
        if(   (dividend < 0 && dividend >= INT_MIN) && (divisor > 0 && divisor <= INT_MAX) || 
              (dividend > 0 && dividend <= INT_MAX) && (divisor < 0 && divisor >= INT_MIN) ){
            
            negativeSign = true;
        }
        if(negativeSign){
            std::cout << "sign is true" << std::endl;
        }else{
            std::cout << "sign is false" << std::endl;
        }
        

        // No division by zero
        if(divisor == 0){ 
            std::cout << "1" << std::endl;
            throw "Error: No division by zero";
        }else if( (dividend > INT_MIN && dividend < INT_MAX) && (divisor > INT_MIN && divisor < INT_MAX)) {
            std::cout << "2" << std::endl;
            returnVal = abs(dividend) / abs(divisor);
        }else if(dividend == INT_MIN && abs(dividend) < INT_MAX && divisor != 1){
            std::cout << "3" << std::endl;
            returnVal = ( abs(dividend+1) / abs(divisor) + 1 );
        }else if(dividend == INT_MIN && (divisor == 1) ){
            std::cout << "4" << std::endl;
            returnVal = INT_MIN;
            negativeSign = false;
        }else{
            std::cout << "5" << std::endl;
           returnVal = (dividend) / (divisor);
        }
       

        // Add a negative sign
        if(negativeSign){
            returnVal *= -1;
        }
        return returnVal;
    }
};