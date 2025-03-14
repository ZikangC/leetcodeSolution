#字典序大小可以直接比较 不需要进行转化
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string deal = to_string(n);
        int len = deal.size();
        char cmp = deal[0];
        int i = 1;
        for(i = 1; i < len; i++){
            if(deal[i] >= cmp){
                cmp = deal[i];
            }else{
                break;
            }
        }
        if(i == len){
            return n;
        }
        i = i-1;
        deal[i] = char(deal[i]-1);
        while(i-1 >= 0 && deal[i-1] > deal[i]){
            deal[i-1] = char(deal[i-1]-1);
            i--;
        }
        i = i+1;
        while(i < len){
            deal[i] = '9';
            i++;
        }
        if(deal[0] == '0'){
            deal.erase(deal.begin());
        }
        return stoi(deal);
    }
};
