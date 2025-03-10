class Solution {
public:
    bool checktrue(vector<vector<char>>& board,int i, int j){
        char cmp = board[i][j];
        if(cmp == '.'){
            return true;
        }
        for(int index = 0; index < 9; index++){
            if(index == j){
                continue;
            }else{
                if(board[i][index] == cmp){
                    return false;
                }
            }
        }
        for(int index = 0; index < 9; index++){
            if(index == i){
                continue;
            }else{
                if(board[index][j] == cmp){
                    return false;
                }
            }
        }
        int blockrow = i/3;
        int blockcol = j/3;
        for(int index1 = blockrow*3; index1 < (blockrow+1)*3; index1++){
            for(int index2 = blockcol*3; index2 < (blockcol+1)*3; index2++){
                if(index1 == i && index2 == j){
                    continue;
                }
                if(board[index1][index2] == cmp){
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(! checktrue(board,i,j)){
                    return false;
                }
            }
        }
        return true;
    }
};
