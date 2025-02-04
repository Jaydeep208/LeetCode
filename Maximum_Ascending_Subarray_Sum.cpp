class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        //Optimal Approach TC is O(N) and SC is O(1)
        int n = nums.size();
        int maxSum = 0;
        int currSum = nums[0];
        
        for(int i = 1; i<n; i++){
            if(nums[i] > nums[i-1]){
                currSum += nums[i];
            }else{
                maxSum = max(maxSum , currSum);
                currSum = nums[i]; 
            }
        }
        return max(maxSum, currSum);
    }
};