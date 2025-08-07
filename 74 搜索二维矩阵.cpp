class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int j = col-1;
        int i = 0;
        while(i < row && matrix[i][j] < target){
            i++;
        }
        if(i == row) return false;
        if(matrix[i][j] == target) return true;
        while(j > -1 && matrix[i][j] > target){
            j--;
        }
        return j != -1 && matrix[i][j] == target;
    }

};
