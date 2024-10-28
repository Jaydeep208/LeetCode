class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        // Brute Force
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end()); // initialize set with vector elements
        int maxlen = 0;

        for (int i = 0; i < n; i++) {
            long long num = nums[i];
            int currlen = 0;

            while (true) {
                if (num > INT_MAX / num) break;

                long long square = num * num;
                
                if (st.find(square) == st.end()) { // If square not found in set
                    break;
                } else {
                    num = square;
                    currlen += 1;
                }
            }
            maxlen = max(maxlen, currlen);
        }

        return maxlen == 0 ? -1 : maxlen + 1;
    }
};
