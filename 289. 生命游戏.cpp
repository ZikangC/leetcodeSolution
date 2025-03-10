##记得学一下这个的编程方法 尤其是continue和：的使用
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<int> dir = {-1,0,1};
        int row = board.size();
        int col = board[0].size();
        for(int i = 0; i < row; i++){
            for(int j = 0 ; j < col; j++){
                int cnt = 0;
                for(int x:dir){
                    for(int y:dir){
                        if(x == 0&& y ==0)continue;
                        int a = i + x;
                        int b = j + y;
                        if(a >=0&& a < row&& b>=0 && b < col && board[a][b]%10 == 1){
                            cnt++;
                        }
                    }
                }
                if(cnt == 3){
                    board[i][j]+= 10;
                }else if(cnt ==2 && board[i][j] == 1){
                    board[i][j]+=10;
                }
            }
        }
        for(int i = 0; i < row; i++){
            for(int j = 0 ; j < col; j++){
                board[i][j] = board[i][j]/10;
            }
        }
        return;
    }
};
