class Solution {
public:
    void traverse(vector<vector<char>>& temp, int r, int c){
        if(r<0 || c<0 || r>=temp.size() || c>=temp[0].size() || temp[r][c] == 'X' || temp[r][c] == 'S')
            return;

        temp[r][c] = 'S';
        traverse(temp, r-1, c);
        traverse(temp, r+1, c);
        traverse(temp, r, c-1);
        traverse(temp, r, c+1);
    }

    void solve(vector<vector<char>>& board) {
        vector<vector<char>> temp = board;

        for(int r{0}; r<temp.size(); r++){
            for(int c{0}; c<temp[0].size(); c++){
                if(r == 0 || r == temp.size()-1 || c == 0 || c == temp[0].size()-1)
                    traverse(temp, r, c);
            }
        }

        for(int r{0}; r<temp.size(); r++){
            for(int c{0}; c<temp[0].size(); c++){
                if(temp[r][c] == 'O')
                    board[r][c] = 'X';
            }
        }

    }
};
