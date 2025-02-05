class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.length();
        int i =-1;
        int j = -1;
        if(s1 == s2){
            return true;
        }
        for(int k = 0; k<n; k++){
            if(s1[k] != s2[k]){
                if(i == -1 &&  j == -1){
                    i = k;
                    continue;
                }else if (i != -1 && j == -1){
                    j = k;
                    continue;
                }else{
                    continue;
                }
            }
        }
        
        if(i != -1 && j != -1){
            swap(s2[i],s2[j]);
            if(s1 == s2){
                return true;
            }
        }
        
        return false;
    }
};
