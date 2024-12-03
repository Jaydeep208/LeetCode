class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.size();
        string ans;

        int spaceIdx = 0;
        for (int i = 0; i < n; i++) {
            if (spaceIdx < spaces.size() && i == spaces[spaceIdx]) {
                ans += ' ';
                spaceIdx++;
            }
            ans += s[i];
        }
        return ans;
    }
};
