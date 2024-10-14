class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long score =0;
        long long n = nums.size();
        priority_queue<long long> pq(nums.begin(), nums.end());
        while(k != 0){
            long long number = pq.top();
            pq.pop();
            score += number;
            number = ceil((double)number/3);
            pq.push(number);
            k--;
        }
        return score;
    }
};
