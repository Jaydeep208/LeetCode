class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        //Optimal Approach
        set<int> st(arr.begin(),arr.end());
        unordered_map<int,int> mp;
        int rank = 1;
        for(auto num : st){
            mp[num] = rank;
            rank++;
        }
        for(int i =0; i<arr.size();i++){
            arr[i] = mp[arr[i]];   
        }
        return arr;
    }
};
