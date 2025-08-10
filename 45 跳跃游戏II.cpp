class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return 0; // 处理长度为1的情况
        
        int maxpos = 0;         // 当前能到达的最远位置
        int pos = 0;            // 当前所在位置
        int nextpos = 0;        // 下一次跳跃的起点
        int res = 0;            // 跳跃次数
        
        while (pos < len - 1) {
            res++;
            int current_max = maxpos; // 记录当前循环的最大范围（关键修复）
            
            // 第一次循环时初始化maxpos
            if (res == 1) {
                current_max = nums[0];
                // 起点直接能到终点的情况
                if (current_max >= len - 1) {
                    return res;
                }
            }
            
            // 在当前可跳跃范围内寻找最远点
            for (int i = pos; i <= current_max; i++) {
                if (i + nums[i] >= len - 1) {
                    return res + 1;
                }
                if (i + nums[i] > maxpos) {
                    maxpos = i + nums[i];
                    nextpos = i;
                }
            }
            pos = nextpos;
        }
        return res;
    }
};
