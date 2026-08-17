class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;

        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    ans++;
                    bfs(grid, i, j);
                }
            }
        }

        return ans;
    }

    void bfs(vector<vector<char>>& grid, int r, int c){

        queue<pair<int, int>> r_c;
        r_c.push({r,c});

        while(!r_c.empty()){
            pair<int, int> front = r_c.front();
            int row = front.first, col = front.second;
            r_c.pop();

            if(grid[row][col] == '0')
                continue;

            grid[row][col] = '0';

            if(row > 0)
                r_c.push({row-1, col});
        
            if(col > 0)
                r_c.push({row, col-1});

            if(row < grid.size()-1)
                r_c.push({row+1, col});
            
            if(col < grid[row].size()-1)
                r_c.push({row, col+1});
        }
    }
};