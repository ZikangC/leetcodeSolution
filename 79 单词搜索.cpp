class Solution {
public:
    bool backtrack(vector<vector<char>>& board, string word, int first, int row, int col){
        if(first == word.size()){
            return true;
        }
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size()){
            return false;
        }
        if(board[row][col] != word[first]){
            return false;
        }else{
            char temp = board[row][col];
            board[row][col] = '*';
            if(backtrack(board,word,first+1,row+1,col) ||  backtrack(board,word,first+1,row-1,col) || backtrack(board,word,first+1,row,col+1) || backtrack(board,word,first+1,row,col-1)){
            return true;
            }
            board[row][col] = temp;
        }
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(backtrack(board,word,0,i,j)){
                    return true;
                };
            }
        }
        return false;
    }
};




// 这道题注意搜索后的内容记得标记 这里可以用回溯
