class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue <int> q;
        vector<int> res;
        int len = nums.size();
        unordered_map<int,int> mp;
        for(int i = 0; i < k; i++){
            mp[nums[i]] = i;
            q.push(nums[i]);
        }
        res.push_back(q.top());
        for(int i = 0; i < len - k; i++){
            q.push(nums[i+k]);
            mp[nums[i+k]] = i+k;
            while(mp[q.top()] < i+1){
                q.pop();
            }
            res.push_back(q.top());
        }
        return res;
    }
};
