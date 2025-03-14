class Solution {
public:
    int fib(int n) {
        if(n == 0){
            return 0;
        }
        int res[n+1];
        memset(res,0,sizeof(res));
        res[1] = 1;
        for(int i = 2; i < n+1; i++){
            res[i] = res[i-2] + res[i-1];
        }
        return res[n];
    }
};
