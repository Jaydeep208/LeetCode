//Let code No: 386 Lexicographical Numbers
class Solution {
private:
    void solve(int currNum, int limit, vector<int> &ans){
        if(currNum > limit){
            return;
        }
        ans.push_back(currNum);
        for(int append =0; append<=9;append++){
            int num = currNum*10 + append;
            if(num > limit) return;
            solve(num,limit,ans);
        }

    }
public:
//OPTIMAL APPROACH as TC is O(n) and SC is O(1) 
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        for(int i =1;i<=9;i++){
            solve(i,n,ans);
        }
        return ans;
    }
};
