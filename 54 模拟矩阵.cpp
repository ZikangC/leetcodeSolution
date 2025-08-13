class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<int>> direction = {{0,1},{1,0},{0,-1},{-1,0}};
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<bool>> visited(row,vector<bool>(col,false));
        int nums = 0;
        vector<int> res = {};
        int i = 0;
        int j = 0;
        int loop = 0;
        int index = 0;
        while(nums < row*col){
            res.push_back(matrix[i][j]);
            nums++;
            visited[i][j] = true;
            int nexti = i + direction[index][0];
            int nextj = j + direction[index][1];
            if(nexti < 0 || nexti > row - 1 || nextj < 0 || nextj > col-1 || visited[nexti][nextj]){
                index++;
                index = index%4;
            }
            i = i + direction[index][0];
            j = j + direction[index][1];
        }
        return res;
    }
};
