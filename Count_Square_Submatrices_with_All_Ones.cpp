class Solution {
private:
    //Brute force without memorization
    
 int solve(int i, int j, vector<vector<int>>& matrix, int n, int m){
    if(i >= n || j >= m){
        return 0;
    }
    if(matrix[i][j] == 0){
        return 0;
    }
    int right = solve(i,j+1,matrix,n,m);
    int diagonal  = solve(i+1,j+1,matrix,n,m);
    int below = solve(i+1, j, matrix,n,m);
    return 1 + min({right, diagonal, below});
 }
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans=0;
        for(int i =0;i<n;i++){
            for(int j =0; j<m;j++){
                if(matrix[i][j] == 1)
                ans += solve(i,j,matrix,n,m);
            }
        }
        return ans;
    }
};
//----------------------------------------------------------------------------------------------------------------------
class Solution {
private:
    //optimal Approach with memorization

 int solve(int i, int j, vector<vector<int>>& matrix, int n, int m, vector<vector<int>> &t){
    if(i >= n || j >= m){
        return 0;
    }
    if(matrix[i][j] == 0){
        return 0;
    }
    if(t[i][j] != -1){
        return t[i][j];
    }
    int right = solve(i,j+1,matrix,n,m, t);
    int diagonal  = solve(i+1,j+1,matrix,n,m, t);
    int below = solve(i+1, j, matrix,n,m, t);
    return t[i][j] = 1 + min({right, diagonal, below});
 }
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans=0;
        vector<vector<int>> t(n+1, vector<int>(m+1,-1));
        for(int i =0;i<n;i++){
            for(int j =0; j<m;j++){
                if(matrix[i][j] == 1)
                ans += solve(i,j,matrix,n,m,t);
            }
        }
        return ans;
    }
};
