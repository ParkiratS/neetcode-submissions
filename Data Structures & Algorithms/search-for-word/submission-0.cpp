class Solution {
public:

    vector<vector<bool>> visited;

    bool traverse(vector<vector<char>>& board, string& word, int r, int c, int index){
        if(index == word.size())
            return true;
        
        if(r < 0 || r>=board.size() || c<0 || c>=board[0].size() || visited[r][c])
            return false;
        

        if(board[r][c] == word[index]){
            visited[r][c] = true;
            bool temp = traverse(board, word, r-1, c, index+1) || traverse(board, word, r+1, c, index+1) || traverse(board, word, r, c-1, index+1) || traverse(board, word, r, c+1, index+1);
            visited[r][c] = false;
            return temp;

        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        visited = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));

        for(int i{0}; i<board.size(); i++){
            for(int j{0}; j<board[0].size(); j++){
                if(traverse(board, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};
