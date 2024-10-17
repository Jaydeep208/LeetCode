class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.length();
        vector<int> maxRight (n, -1);
        for(int i = n-1; i>=0; i--){
            if(i == n-1){
                maxRight[i] = i;
            }
            else if(s[i] > s[maxRight[i+1]]){
                maxRight[i] = i;
            }else{
                maxRight[i] = maxRight[i+1];
            }
        }
        for(int i =0; i<n;i++){
            if(s[maxRight[i]] > s[i]){
                swap(s[i], s[maxRight[i]]);
                break;
            }
        }
        return stoi(s);

    }
};
