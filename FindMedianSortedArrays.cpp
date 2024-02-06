class Solution {
// Referenced meurudesu on LeetCode to find solution    
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n > m) return findMedianSortedArrays(nums2, nums1);          // perform BS on smaller array
        int low = 0;
        int high = n;
        int req = (n + m + 1) / 2;                                      // total elements required from both arrays
        while(low <= high) {
            int mid1 = (low + high) / 2;                                // elements to be picked from nums1
            int mid2 = req - mid1;                                      // elements to be picked from nums2
            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;
            if(mid1 < n) r1 = nums1[mid1];
            if(mid2 < m) r2 = nums2[mid2];
            if(mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
            if(mid2 - 1 >= 0) l2 = nums2[mid2 - 1];
            if(l1 <= r2 && l2 <= r1) {
                if((n + m) % 2 == 1) {                                  // total no. of elements are odd
                    return max(l1, l2);
                } else {                                                // total no. of elements are even
                    return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
                }
            } else if(l1 > r2) high = mid1 - 1;
            else low = mid1 + 1;
        }
        return 0;
    }
};