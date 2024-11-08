class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        //Optimal Approach TC is O(n) ans SC is O(1)
        int n = nums.size();
        int XOR = 0;
        vector<int>ans;
        for(int i =0; i<n; i++){
            XOR ^= nums[i];
        }

        int mask = ((1<<maximumBit)-1);

        for(int i=0; i<n; i++){
            int k = XOR ^ mask;
            ans.push_back(k);
            XOR ^= nums[n-1-i];
        }
        return ans;
    }
};
