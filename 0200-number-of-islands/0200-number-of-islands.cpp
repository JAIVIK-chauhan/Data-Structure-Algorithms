class Solution {
public:
    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid){
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int delr = -1 ; delr <= 1 ; delr++){
                int nr = r + delr;
                if(nr >= 0 && nr < n && !vis[nr][c] && grid[nr][c] == '1'){
                            vis[nr][c] = 1;
                            q.push({nr,c});
                }
            }
            for(int delc = -1 ; delc <= 1 ; delc++){
                int nc = c + delc;
                if(nc >= 0 && nc < m && !vis[r][nc] && grid[r][nc] == '1'){
                            vis[r][nc] = 1;
                            q.push({r,nc});
                }
            }
        }


        //     for(int delrow = -1 ; delrow <= 1 ; delrow++){
        //         for(int delcol = -1; delcol <= 1 ; delcol++){
        //             int nr = r + delrow;
        //             int nc = c + delcol;

        //             if(nr >= 0 && nr < n && nc >= 0 && nc < m &&
        //                 !vis[nr][nc] && grid[nr][nc] == '1'){
        //                     vis[nr][nc] = 1;
        //                     q.push({nr,nc});
        //                 }
        //         }
        //     }
        // }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(n, vector<int>(m,0));

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    bfs(i,j,vis,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};