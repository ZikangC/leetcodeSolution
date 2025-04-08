class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int left = 0;
        int res= 0;
        int right = len-1;
        while(left <= right){
            if(nums[left]!=val){
                left++;
                res++;
            }else{
                if(nums[right] != val){
                    nums[left] = nums[right];
                    right--;
                    left++;
                    res++;
                }else{
                    right--;
                }
            }
        }
        return res;
    }
};
