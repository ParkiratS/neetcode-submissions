class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>, int>> q;

        int rows = grid.size(), cols = grid[0].size();
        int m = 0, ones = 0;

        for(int r{0}; r<grid.size(); r++){
            for(int c{0}; c<grid[r].size(); c++){
                if(grid[r][c] == 2){
                    q.push({{r, c + 1}, 1});
                    q.push({{r, c - 1}, 1});
                    q.push({{r - 1, c}, 1});
                    q.push({{r + 1, c}, 1});
                }
                if(grid[r][c] == 1)
                    ones++;
            }
        }

        while(!q.empty()){
            int r = q.front().first.first, c = q.front().first.second, curr = q.front().second;
            q.pop();

            if (r<0 || c<0 || r>=rows || c>=cols || grid[r][c] == 2 || grid[r][c] == 0)
                continue;

            m = max(m, curr);
            grid[r][c] = 2;
            ones--;
            q.push({{r, c + 1}, curr+1});
            q.push({{r, c - 1}, curr+1});
            q.push({{r - 1, c}, curr+1});
            q.push({{r + 1, c}, curr+1});
        } 

        if(ones > 0)
            return -1;
        else 
            return m;
    }
};
