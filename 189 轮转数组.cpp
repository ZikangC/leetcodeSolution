class Solution {
public:
    void rever(vector<int>& nums, int n, int k){
        int tmp;
        while(n < k){
            tmp = nums[n];
            nums[n] = nums[k];
            nums[k] = tmp;
            n++;
            k--;
        }
        return;
    }
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        while(k > len){
            k = k - len;
        }
        rever(nums,0,len-1);
        rever(nums,0,k-1);
        rever(nums,k,len-1);
        return;
    }
};
