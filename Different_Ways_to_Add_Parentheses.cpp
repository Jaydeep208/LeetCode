class Solution {
private:
vector<int> solve(string s){
    vector<int> ans;
    for(int i=0; i<s.length();i++){
        if(s[i] == '+' || s[i] == '-' || s[i] == '*'){
            vector <int> left_half = solve(s.substr(0,i));
            vector <int> right_half = solve(s.substr(i+1));

            for(int &x: left_half){
                for(int &y: right_half){
                    if(s[i]=='+'){
                        ans.push_back(x+y);
                    }else if(s[i] == '-'){
                        ans.push_back(x-y);
                    }else{
                        ans.push_back(x*y);
                    }
                }
            }
        }
    }
    if(ans.size()==0){
        ans.push_back(stoi(s));
    }
    return ans;
}
public:
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};
