//884. Uncommon Words from Two Sentences

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        int n1 = s1.length();
        int n2 = s2.length();
        string word = "";
        for (int i = 0; i < n1; i++) {
            char ch = s1[i];
            if (ch == ' ') {
                mp[word]++;
                word = "";
            } else {
                word += ch;
            }
        }
        if (!word.empty())
            mp[word]++;
        word = "";
        for (int i = 0; i < n2; i++) {
            char ch = s2[i];
            if (ch == ' ') {
                mp[word]++;
                word = "";
            } else {
                word += ch;
            }
        }
        if (!word.empty())
            mp[word]++;
        vector<string> ans;
        for (auto it : mp) {
            if (it.second == 1) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
