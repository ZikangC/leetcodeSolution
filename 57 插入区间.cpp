class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> res;
        int len = intervals.size();
        if (len == 0) {
            res.push_back(newInterval);
            return res;
        }
        int i = 0;
        int cmp = newInterval[1];
        if (newInterval[0] <= intervals[0][0]) {
            while (i < len && cmp >= intervals[i][0]) {
                cmp = max(cmp, intervals[i][1]);
                i++;
            }
            res.push_back({newInterval[0], cmp});
            while (i < len) {
                res.push_back(intervals[i]);
                i++;
            }
            return res;
        }
        while (i < len && intervals[i][0] <= newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }
        int flag = -1;
        if (intervals[i - 1][1] >= newInterval[0]) {
            flag = i - 1;
        }
        while (i < len && intervals[i][0] <= cmp) {
            cmp = max(cmp, intervals[i][1]);
            i++;
        }
        if (flag != -1) {
            res[flag][1] = max(cmp,res[flag][1]);
        } else {
            res.push_back({newInterval[0], cmp});
        }
        while (i < len) {
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};


##这个是应该的版本
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res; // ✅ 结果容器应为字符串向量
        int n = nums.size();
        if (n == 0) return res;

        int begin = nums[0];
        int end = nums[0];

        for (int i = 1; i <= n; ++i) { // ✅ 包含 i == n 以处理最后一个区间
            if (i < n && nums[i] == end + 1) {
                // 当前元素连续，扩展区间
                end = nums[i];
            } else {
                // 添加当前区间
                if (begin == end) {
                    res.push_back(to_string(begin));
                } else {
                    res.push_back(to_string(begin) + "->" + to_string(end));
                }
                // 重置区间起点（需检查 i < n）
                if (i < n) {
                    begin = nums[i];
                    end = nums[i];
                }
            }
        }
        return res;
    }
};
