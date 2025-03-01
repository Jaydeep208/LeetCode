class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        //Brute Force TC is O(2n) ans SC is O(1)
        int n = nums.size();
        vector<int>ans(n,0);
        for(int i =0; i<n-1; i++){
            if(nums[i] == nums[i+1]){
                nums[i] = nums[i]*2;
                nums[i+1] = 0;
            }
        }
        int j =0;
        for(int i =0; i<n; i++){
            if(nums[i] != 0){
                ans[j] = nums[i];
                j++;
            }
        }
        return ans;
    }
};
