class Solution {
private:
bool isPossible(vector<int> & candies, long long k, int numOfCandies){
    long long int maxChildren = 0;
    for(int i =0; i< candies.size(); i++){
        maxChildren += candies[i]/numOfCandies;
    }
    return maxChildren >= k;
}
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int ans = 0;
        int n = candies.size();
        long long total =0;
        int maxi = INT_MIN;
        for(int i =0; i<n ;i ++){
            total += candies[i];
            maxi = max(maxi, candies[i]);
        }
        if(total < k){
            return 0;
        }
        int left =1;
        int right = maxi;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(isPossible(candies, k, mid))
            {
                ans = max(mid, ans);
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return ans;
        
    }
};
