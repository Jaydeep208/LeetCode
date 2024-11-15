class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        //Optimal Approach TC is O(n) and SC is O(1)
        int n = arr.size();
        int j = n-1;
        while(j > 0 && arr[j] >= arr[j-1]){
            j--;
        }
        if(j == 0){
            return 0; //Already sorted array
        }

        int i =0;
        int ans = j;
        while ( i < j && (i == 0 || arr[i] >= arr[i-1]) ){
            while (j < n && arr[i] > arr[j]){
                j++;
            }
            ans = min(ans, j-i-1);
            i++;
        }
        return ans;
    }
};
