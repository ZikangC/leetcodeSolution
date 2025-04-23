class Solution {
public:
    int getsquare(int n){
        int res = 0;
        while(n!=0){
            res += pow(n%10,2);
            n = n/10;
        }
        return res;
    }
    bool isHappy(int n) {
        for(int i = 0; i < 900; i++){
            n = getsquare(n);
            if(n == 1){
                return true;
            }
        }
        return false;
    }
};
