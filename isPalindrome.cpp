class Solution {
public:
    bool isPalindrome(int x) {
        // temp storage of ints
        std::vector<int> compare;
        bool isPalidrome = true;
        // if the number is negative, not a palindrome
        if(x<0){
            isPalidrome = false;
        }
        // find the digits
        while(x){
            // unpack tens
            compare.push_back(x % 10);
            // keep the remainder
            x /= 10;
        }
        int size = compare.size();
        // loop through the compare vector
        // but only if isPalidrome is not set to false
        if(isPalidrome){
            for(int i = 0; i < size; ++i){
                if(compare[i] != compare[size-i-1]){
                    isPalidrome = false;
                    break;
                }else {
                    isPalidrome = true;
                }
            }
        }   
        return isPalidrome;
    }
};