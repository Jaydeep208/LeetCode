class Solution {
public:
    bool rotateString(string s, string goal) {
        //Optimal TC is O(n) and Sc is O(n)
        int n = s.length();
        int m = goal.length();
        if(n != m){
            return false;
        }
        string doubleString = s + s;
        
        return doubleString.find(goal) < doubleString.length();
    }
};
