class Solution {
private:
    void update(int number, vector<int> &vec, int val){
        for(int i=0;i<32;i++){
            if( ((number >> i) &1) != 0 ){
                vec[i] += val;
            }
        }
    }

    int getDecimalFromBinary(vector<int> &vec){
        int num =0;
        for(int i=0;i<32;i++){
            if(vec[i] > 0){
                num |= (1 << i);
            }
        }
        return num;
    }
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        //Tc is O(2*2)
        int n = nums.size();
        int ans = INT_MAX;
        int i =0;
        int j =0;
        vector<int> vec(32,0);
        while(j<n){
            update(nums[j], vec, +1);
            while(i<=j && getDecimalFromBinary(vec) >= k){
                ans = min(ans, j-i+1);
                update(nums[i], vec, -1); 
                i++;
            }
            j++;
        }
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};
