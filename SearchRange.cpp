class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> returnVect;
        
        // the array is null
        if(nums.empty()){
             returnVect.push_back(-1);
             returnVect.push_back(-1);
        }else{
        // The array contains values
            if(target == 0){
                // no target designated 
             returnVect.push_back(-1);
             returnVect.push_back(-1);
            }else{
                // both a target and array designated
                // step through the vector
                for (auto i = nums.begin(); i < nums.end()-1; ++i) {
                    // if the target is found, add it to the return vector
                    if(nums.at((int)(i - nums.begin())) == target){
                        returnVect.push_back((int)(i - nums.begin()));
                    }
                }


            }
            if(returnVect.empty()){
                returnVect.push_back(-1);
                returnVect.push_back(-1);
            }
        }
        return returnVect;
    }
};