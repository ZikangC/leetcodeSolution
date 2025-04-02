class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp2;
        stack<int> st;
        vector<int> res;
        int len1 = nums1.size();
        int len2 = nums2.size();
        int i = 0;
        while(i < len2){
            if(st.empty()||nums2[i] < st.top()){
                st.push(nums2[i]);
                i++;
            }else{
                mp2[st.top()] = nums2[i];
                st.pop();
            }
        }
        while(!st.empty()){
            mp2[st.top()] = -1;
            st.pop();
        }
        for(int j = 0; j < len1; j++){
            res.push_back(mp2[nums1[j]]);
        }
        return res;
    }
};
