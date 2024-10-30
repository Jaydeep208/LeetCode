class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> LIS(n,1); //To store the longest subsequesce from left to right 
        vector<int> LDS(n,1); //To store the longest subsequesce from right to left

        //calculate the LIS
        for(int i =0; i<n; i++){
            for(int j = i-1; j>= 0; j--){
                if(nums[i] > nums[j]){
                    LIS[i] = max(LIS[i] , LIS[j] + 1);
                }
            }
        }

        //calculate the LDS
        for(int i = n-1;i>=0; i--){
            for(int j = i+1; j<n; j++){
                if(nums[i] > nums[j]){
                    LDS[i] = max(LDS[i], LDS[j] + 1);
                }
            }
        }

        int minRemoval = n; //n because in worst case we can remove all the elements
        for(int i=0; i<n; i++)
        {
            if(LIS[i] > 1 && LDS[i] > 1){ //both should be greater than 1 .. i.e the only mountain can be formed
                minRemoval = min(minRemoval, n - LIS[i] - LDS[i] + 1);
            }
        } 
        return minRemoval;
    }
};
