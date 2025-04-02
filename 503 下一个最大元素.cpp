#可以直接设置结果 然后更新就好
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st; // 存储的是索引，而非值
        
        for (int i = 0; i < 2 * n; ++i) {
            int idx = i % n;
            while (!st.empty() && nums[idx] > nums[st.top()]) {
                res[st.top()] = nums[idx];
                st.pop();
            }
            if (i < n) {
                st.push(idx);
            }
        }
        return res;
    }
};
