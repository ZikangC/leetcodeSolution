class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        vector<int> res(len,0);
        stack<int> st;
        int i = 0;
        while(i < len){
            if(!st.empty() &&temperatures[i] > temperatures[st.top()]){
                res[st.top()] = i - st.top();
                st.pop();
            }else{
                st.push(i);
                i++;
            }
        }
        return res;
    }
};
