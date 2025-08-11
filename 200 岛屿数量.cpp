class Solution {
public:
    void fision(vector<vector<char>>& grid,vector<vector<int>>& dp, int i, int j, int cnt){
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int,int>> q;
        q.push(tie(i,j));
        while(!q.empty()){
            int f = q.front().first;
            int s = q.front().second;
            dp[f][s] = cnt;
            if(f-1 >= 0){
                if(grid[f-1][s] == '1' && dp[f-1][s] == 0){
                dp[f-1][s] = cnt;
                q.push({f-1,s});
                }
            }
            if(s+1 < col){
                if(grid[f][s+1] == '1' && dp[f][s+1] == 0){
                    dp[f][s+1] = cnt;
                    q.push({f,s+1});
                }
            }
            if(f+1 < row){
                if(grid[f+1][s] == '1' && dp[f+1][s] == 0){
                    dp[f+1][s] = cnt;
                    q.push({f+1,s});
                }
            }
            if(s-1 >= 0){
                if(grid[f][s-1] == '1' && dp[f][s-1] == 0){
                    dp[f][s-1] = cnt;
                    q.push({f,s-1});
                }
            }
            q.pop();
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int cnt = 0;
        vector<vector<int>> dp(row,vector<int>(col,0));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1' && dp[i][j] == 0){
                    cnt++;
                    fision(grid,dp,i,j,cnt);
                }
            }
        }
        return cnt;
    }
};
