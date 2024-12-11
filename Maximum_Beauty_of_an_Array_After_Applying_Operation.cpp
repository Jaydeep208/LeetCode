class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        //Better Approach TC is O(nlogn)  
        int n = nums.size();
        vector<pair<int,int>> intervals(n);
        for(int i =0; i<n;i++){
            intervals[i] = {nums[i] -k, nums[i]+k};
        }
        sort(intervals.begin(), intervals.end());
        queue<int>que; //Only push the end of the interval
        int maxBeauty = 0;
        for(pair<int,int> & interval : intervals){
            while(!que.empty() && que.front() < interval.first){
                que.pop();
            }
            que.push(interval.second);
            maxBeauty = max(maxBeauty, (int) que.size());
        }
        return maxBeauty;
    }
};
