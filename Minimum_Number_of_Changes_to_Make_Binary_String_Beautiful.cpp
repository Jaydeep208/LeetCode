class Solution {
public:
    int minChanges(string s) {
        //Optimal Approach // Tc is O(n) and Sc is O(1)
        //Here break the entire string to the 2 length subString then check
        int n = s.length();
        int changes = 0;
        for(int i =0; i<n-1;i = i+2){
            char ch = s[i];
            if(ch != s[i+1]){
                changes += 1;
            }
        }
        return changes;
    }
};
