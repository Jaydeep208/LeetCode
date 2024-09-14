//optimal Approach
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = 0;
        int currStreak =0;
        int result =0;

        for(int num : nums){
            if(num > maxVal){
                maxVal = num;
                result = 0;
                currStreak=0;
            }
            if(num == maxVal){
                currStreak++;
            }else{
                currStreak=0;
            }
            result = max(result,currStreak);
        }
        return result;
    }
};
