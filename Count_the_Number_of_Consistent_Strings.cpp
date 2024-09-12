class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char>st;
        for(int i =0; i<allowed.length();i++){
            char ch = allowed[i];
            st.insert(ch);
        }
        int ans=0;
        for(int i =0;i<words.size();i++){
            string word = words[i];
            bool found = true;
            for(int j =0;j<word.length();j++){
                char ch = word[j];
                if(!st.count(ch)){
                    found = false;
                    break;
                }
            }
            if(found == true){
                ans++;
            }
        }
        return ans;
    }
};
