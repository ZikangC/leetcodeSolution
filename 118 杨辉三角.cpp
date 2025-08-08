class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> last = {};
        vector<int> tmp ={1};
        res.push_back(tmp);
        int i = 1;
        while(i < numRows){
            last = tmp;
            tmp = {};
            tmp.push_back(1);
            for(int j = 1; j < i; j++){
                tmp.push_back(last[j-1]+last[j]);
            }
            tmp.push_back(1);
            res.push_back(tmp);
            i++;
        }
        return res;
    }
};
