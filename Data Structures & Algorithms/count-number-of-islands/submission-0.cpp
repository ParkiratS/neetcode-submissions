class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;

        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }

        return ans;
    }

    void dfs(vector<vector<char>>& grid, int r, int c){
        if(grid[r][c] == '0')
            return;

        grid[r][c] = '0';

        if(r > 0)
            dfs(grid, r-1, c);
        
        if(c > 0)
            dfs(grid, r, c-1);

        if(r < grid.size()-1)
            dfs(grid, r+1, c);
        
        if(c < grid[r].size()-1)
            dfs(grid, r, c+1);

    }
};