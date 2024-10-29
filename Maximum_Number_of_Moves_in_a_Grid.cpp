class Solution {
private:
//After memorization TC is O(n*m) and SC is O(n*m)
    int func(int row, int col, int delRow[], int delCol[], vector<vector<int>>& grid, int n, int m, vector<vector<int>>& t) {
        if(t[row][col] != -1){
            return t[row][col];
        }
        int moves = 0;

        for (int i = 0; i < 3; i++) {
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] > grid[row][col]) {
                moves = max(moves, 1 + func(newRow, newCol, delRow, delCol, grid, n, m,t));
            }
        }

        return t[row][col] = moves;
    }

public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int delRow[] = {-1, 0, +1};
        int delCol[] = {+1, +1, +1};

        int maxMovesOverall = 0;
        vector<vector<int>> t(n, vector<int> (m,-1));
        // Try starting from every cell in the first column
        for (int i = 0; i < n; i++) {
            maxMovesOverall = max(maxMovesOverall, func(i, 0, delRow, delCol, grid, n, m,t));
        }

        return maxMovesOverall;
    }
};
