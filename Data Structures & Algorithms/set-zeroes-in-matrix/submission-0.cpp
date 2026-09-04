class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> rows(matrix.size(), 0);
        vector<int> cols(matrix[0].size(), 0);
        

        for(int r{0}; r<matrix.size(); r++){
            for(int c{0}; c<matrix[0].size(); c++){
                if(matrix[r][c] == 0){
                    rows[r] = 1;
                    cols[c] = 1;
                }
            }
        }

        for(int r{0}; r<matrix.size(); r++){
            for(int c{0}; c<matrix[0].size(); c++){
                if(rows[r] == 1 || cols[c] == 1)
                    matrix[r][c] = 0;
            }
        }
    }
};
