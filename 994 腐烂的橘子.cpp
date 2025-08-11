class Solution {
public:
    int worse(vector<vector<int>>& grid, vector<vector<int>>& deal, queue<pair<int,int>>& q,int nums){
        int res = 0;
        while(nums--){
            int row = grid.size();
            int col = grid[0].size();
            int f = q.front().first;
            int s = q.front().second;
            if(f-1 >=0){
                if(grid[f-1][s] == 1 && deal[f-1][s] == 0){
                    q.push({f-1,s});
                    grid[f-1][s] = 2;
                    deal[f-1][s] = 1;
                    res++;
                }
            }
            if(f+1 < row){
                if(grid[f+1][s] == 1 && deal[f+1][s] == 0){
                    q.push({f+1,s});
                    grid[f+1][s] = 2;
                    deal[f+1][s] = 1;
                    res++;
                }
            }
            if(s-1>=0){
                if(grid[f][s-1] == 1 && deal[f][s-1] == 0){
                    q.push({f,s-1});
                    grid[f][s-1] = 2;
                    deal[f][s-1] = 1;
                    res++;
                }
            }
            if(s+1<col){
                if(grid[f][s+1] == 1 && deal[f][s+1] == 0){
                    q.push({f,s+1});
                    grid[f][s+1] = 2;
                    deal[f][s+1] = 1;
                    res++;
                }
            }
            q.pop();
        }
        return res;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> deal(row,vector<int>(col,0));
        queue<pair<int,int>> q;
        int nums = 0;
        int newo = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                    nums++;
                }
                if(grid[i][j] == 1){
                    newo++;
                }
            }
        }
        if(newo == 0){
            return 0;
        }
        int res = -1;
        while(!q.empty()){
            nums = worse(grid,deal,q,nums);
            res++;
        }
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return res;        
    }
};
