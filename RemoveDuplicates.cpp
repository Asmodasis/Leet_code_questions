class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int n = 0;
        for(int i=1; i < nums.size(); i++){
            // check the current value with the next value for a duplicate
            if(nums[i] != nums[n]){
                nums[n+1] = nums[i];
                n++;
            }
        }
        return n+1;
    }
};