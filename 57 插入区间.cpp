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
