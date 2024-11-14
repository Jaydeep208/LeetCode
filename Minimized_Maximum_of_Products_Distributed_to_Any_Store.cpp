class Solution {
private: 
bool isPossible(int x, vector<int>& quantities, int shops){
    for (int &products: quantities){
        shops -= ceil((double)products/x); 
        if(shops < 0){
            return false;
        }
    }
    return true;
}    
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1; 
        int right = *max_element(quantities.begin(), quantities.end());
        int ans = 0;
        while(left <= right){
            int mid = (left+right)/2;
            if(isPossible(mid, quantities, n)){
                ans = mid;
                right = mid-1;
            }else{
                left = mid +1;
            }
        }
        return ans;
    }
};
