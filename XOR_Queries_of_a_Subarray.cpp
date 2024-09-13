// Leet code no : 1310 XOR Queries of a Subarray
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        //Optimal Approach
        vector<int>xorArr(arr.size(),0);
        xorArr[0]=arr[0];
        for(int i =1;i<arr.size();i++){
            xorArr[i] = xorArr[i-1] ^ arr[i]; 
        }
        vector<int> ans; //For storing the ans
        for(int i =0; i<queries.size();i++){
            int left = queries[i][0];
            int right = queries[i][1];
            
            ans.push_back( (left == 0 ? 0:  xorArr[left-1]) ^ xorArr[right]);
        }
        return ans;
    }
};
