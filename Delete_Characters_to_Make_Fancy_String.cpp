class Solution {
public:
    string makeFancyString(string s) {
        //Optimised TC is O(n) and SC is O(1) 
        int n = s.length();
        string ans ="";
        if(n<=1){
            return s;
        }
        ans.push_back(s[0]); // Inserting the 1st element

        int counter = 1;
        for(int i =1; i<n; i++){
            char ch = s[i];
            if(ans.back() != ch){
                counter =1;
            }
            if(ans.back() == ch){
                counter++;
            }
            if(counter < 3){
                ans.push_back(ch);
            }
        }
        return ans; 
    }
};
