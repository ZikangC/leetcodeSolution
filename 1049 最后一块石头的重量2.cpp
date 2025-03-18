class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int len = stones.size();
        vector<int> partsum = {};
        int sum = 0;
        for(auto i:stones){
            sum+=i;
            partsum.push_back(sum);
        }

        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int stone : stones) {
            for (int j = target; j >= stone; j--) {
                dp[j] = dp[j] || dp[j - stone];
            }
        }
        int weight = target;
        while(weight >0 &&!dp[weight]){
            weight--;
        }
        return sum- 2*weight;
    }
};
