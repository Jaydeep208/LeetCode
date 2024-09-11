//TC is O(1) as we run the for loop for fixed amount it. 32 and SC is O(1) as we take fixed space i.e 32 bits

class Solution {
private:
string convertToBinary(int n){
    return bitset<32>(n).to_string();
}
public:
    int minBitFlips(int start, int goal) {
        string s= convertToBinary(start);
        string g = convertToBinary(goal);
        int ans =0;
        for(int i=0;i<32;i++){
            if(s[i] != g[i]){
                ans++;
            }
        }
        return ans;
    }
};
