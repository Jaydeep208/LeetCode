class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.length();
        long long step = 0;
        int blackCount = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '1'){
                blackCount++;
            }
            if(s[i] == '0'){
                step += blackCount;
            }
        }
        return step;
    }
};
