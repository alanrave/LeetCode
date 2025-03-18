class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<pair<int,int>,int>> q; // { {row, col}, time }

        // Step 1: Push all initially rotten oranges into the queue
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }

        // Directions for moving in a 4-directional grid
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        int time = 0;

        // Step 2: BFS traversal
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time, t);
            
            for(int i = 0; i < 4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                // Check if the cell is within bounds, unvisited, and contains a fresh orange
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                   !visited[nrow][ncol] && grid[nrow][ncol] == 1) {
                    visited[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, t + 1});
                }
            }
        }

        // Step 3: Check if any fresh orange remains unrotted
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && !visited[i][j])
                    return -1;
            }
        }
        return time;

    }
};