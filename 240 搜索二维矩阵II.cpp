class Solution {
public:
    bool searchpart(vector<vector<int>>& matrix, int target,int curi, int curj){
        int row = matrix.size();
        int col = matrix[0].size();
        int i = curi;
        int j = curj;
        while(i < row && matrix[i][j] < target){
            i++;
        }
        if(i == row){
            return false;
        }
        while(j >= 0 && matrix[i][j] > target){
            j--;
        }
        if(j == -1){
            return false;
        }
        if(matrix[i][j] == target){
            return true;
        }else{
            return searchpart(matrix,target,i,j);
        }
        return true;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int i = 0;
        int j = col - 1;
        return searchpart(matrix,target,i,j);
    }
};
