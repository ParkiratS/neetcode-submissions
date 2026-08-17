const int BOARD_DIMENSION = 9;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> row_map(9);
        vector<unordered_set<char>> col_map(9);
        vector<unordered_set<char>> square_map(9);

        for(int i = 0; i<BOARD_DIMENSION; i++){
            for(int j = 0; j<BOARD_DIMENSION; j++){

                char element = board.at(i).at(j);

                if(element == '.')
                    continue;
                
                bool existsInRow = row_map.at(i).find(element) != row_map.at(i).end();
                bool existsInCol = col_map.at(j).find(element) != col_map.at(j).end();
                bool existsInSquare = square_map.at((i/3)*3 + j/3).find(element) != square_map.at(i/3 + j/3).end();


                if(existsInRow || existsInCol || existsInSquare)
                    return false;
                
                else{
                    row_map.at(i).insert(element);
                    col_map.at(j).insert(element);
                    square_map.at((i/3)*3 + j/3).insert(element);
                }
                
            }
        }

        return true;
        
    }
};
