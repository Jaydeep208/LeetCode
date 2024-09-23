//Leet code 2707. Extra Characters in a String
class Solution {
private:
//Memorizetion of the sulution
int t[51];
int solve (int i, string &s, unordered_set<string>&st, int &n ){
    if(i >= n){
        return 0;
    }
    if (t[i] != -1){
        return t[i];
    }
    int result = 1 + solve(i +1, s,st, n);
    for(int j =i;j<n;j++){
        string sub_string = s.substr(i, j-i+1);
        if(st.count(sub_string)){
            result = min(result, solve(j+1, s, st, n));
        }
    }
    return t[i] = result;
}
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        memset(t,-1,sizeof(t));
        unordered_set <string>st;
        for(auto &it: dictionary){
            st.insert(it);
        }
        int ans = solve(0, s,st,n);
        return ans;
        
    }
};

