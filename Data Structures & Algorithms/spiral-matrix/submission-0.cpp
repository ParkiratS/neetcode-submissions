class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int left = 0, right = matrix[0].size()-1, up = 0, down = matrix.size()-1;
        int row = up, col = left;
        
        while(up <= down && left <= right){
            if(row == up && col == left){
                for(int i{col}; i<=right; i++)
                    ans.push_back(matrix[row][i]);

                col = right;
                row++;
                up++;
                
            }

            else if(row == up && col == right){
                for(int i{row}; i<=down; i++)
                    ans.push_back(matrix[i][col]);

                row = down;
                col--;
                right--;
                
            }

            else if(row == down && col == right){
                for(int i{col}; i>=left; i--)
                    ans.push_back(matrix[row][i]);

                col = left;
                row--;
                down--;
                
            }

            else{
                for(int i{row}; i>=up; i--)
                    ans.push_back(matrix[i][col]);

                row = up;
                col++;
                left++;
                
            }
        }

        return ans;
        
        
    }
};
