//179(Leetcode) Largest Number

class Solution {
private:
static bool comparator (string &a, string &b){
    return a+b > b+a;
}
public:
    string largestNumber(vector<int>& nums) {
        string ans = "";
        int n = nums.size();
        vector<string>num;
        for(int i =0; i<n;i++){
            num.push_back(to_string(nums[i]));
        }
        sort(num.begin(), num.end(),comparator);
        for(int i =0; i<n; i++){
            ans+= num[i];
        }
        if(ans[0]=='0') return "0";
        return ans;

    }
};
