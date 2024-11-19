class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        //Bruet Force TC is O(2n) i.e O(n) and SC is O(n)
        int n = nums.size();
        long long ans = 0;
        int left =0;
        int right = 0;
        long long subSum = 0;
        unordered_set <int>st;
        while(right < n){
            while(st.count(nums[right])){
                subSum -= nums[left];
                st.erase(nums[left]);
                left++;
            }
            subSum += nums[right];
            st.insert(nums[right]);
            if(right-left+1 == k){
                ans = max(ans, subSum);
                subSum -= nums[left];
                st.erase(nums[left]);
                left++;
            }
            right++;
        }
        return ans;
    }
};
