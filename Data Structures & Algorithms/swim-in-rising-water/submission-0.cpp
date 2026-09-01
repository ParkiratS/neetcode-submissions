class Solution {
public:

    struct Spot{
        int r;
        int c;
        int m;

        Spot(int row, int col, int max){
            this->r = row;
            this->c = col;
            this->m = max;
        }

        bool operator<(const Spot& other) const {
            return m > other.m; 
        }
    };

    void tryInsert(int r, int c, int curr_m, vector<vector<int>>& grid, priority_queue<Spot>& maxHeap, vector<vector<int>>& seen){
        if(r<0 || c<0 || r>=grid.size() || c>=grid.size())
            return;
        
        if(seen[r][c])
            return;
        
        maxHeap.push(Spot(r, c, max(curr_m, grid[r][c])));
    }


    int swimInWater(vector<vector<int>>& grid) {
        vector<vector<int>> seen(grid.size(), vector<int>(grid.size(), 0));
        priority_queue<Spot> maxHeap;
        maxHeap.push(Spot(grid.size()-1, grid.size()-1, grid[grid.size()-1][grid.size()-1]));

        while(true){
            Spot temp = maxHeap.top();
            maxHeap.pop();

            if(seen[temp.r][temp.c])
                continue;

            seen[temp.r][temp.c] = 1;

            if(temp.r == 0 && temp.c == 0)
                return temp.m;

            tryInsert(temp.r+1, temp.c, temp.m, grid, maxHeap, seen);
            tryInsert(temp.r-1, temp.c, temp.m, grid, maxHeap, seen);
            tryInsert(temp.r, temp.c+1, temp.m, grid, maxHeap, seen);
            tryInsert(temp.r, temp.c-1, temp.m, grid, maxHeap, seen);

        }

    }
};
