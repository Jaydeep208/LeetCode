//Question: Minimum Increment to Make Array Unique (945) LeetCode

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        //Counting sort
        int ans = 0;
        int n = nums.size();
        //sort(nums.begin(), nums.end());
        int maxEle = *max_element(nums.begin(), nums.end());
        
        return ans;
    }
};
