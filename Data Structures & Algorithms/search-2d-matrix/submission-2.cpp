class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int leftIndex = 0, rightIndex = m*n - 1;

        while(leftIndex <= rightIndex){
            int index = (leftIndex + rightIndex) / 2;
            int row = index / n, col = index % n;

            if(matrix[row][col] == target)
                return true;
            else if(matrix[row][col] < target)
                leftIndex = index + 1;
            else
                rightIndex = index - 1;
        }
        return false;
    }
};