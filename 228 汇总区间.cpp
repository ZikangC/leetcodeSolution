#这样做其实不好 如果你觉得if里面还有一个大循环其实可以用if里面一个大if来替代 而不是两个while 这样容易出现边界错误
  
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int len = nums.size();
        if (len == 0) {
            return {};
        } else if (len == 1) {
            return {to_string(nums[0])};
        }
        int begin = nums[0];
        int end = nums[0];
        int index = 1;
        while (index <= len) {
            while (index < len && nums[index] == nums[index - 1] + 1) {
                end = nums[index];
                index++;
            }
            if (begin == end) {
                res.push_back(to_string(begin));
            } else {
                res.push_back(to_string(begin) + "->" + to_string(end));
            }
            if (index < len) {
                begin = nums[index];
                end = nums[index];
            }
            index++;
        }
        return res;
    }
};
