class Solution {
public:
    bool isCircularSentence(string sentence) {
        //Optimal Approach TS is O(n) and SC is O(1)
        int n = sentence.size();
        if(sentence[0] != sentence[n-1]){
            return false;
        }
        for(int i =0; i<n; i++){
            char currL = sentence[i];
            if(currL == ' '){
                char prevL = sentence[i-1];
                char nextL = sentence[i+1];
                if(prevL != nextL){
                    return false;
                }
            }
        }
        return true;
    }
};
