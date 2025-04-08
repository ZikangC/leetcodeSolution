#可以用left = mid+1这种方式来规避最后的死循环
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        while(left < right-1){
            if(target == nums[(left+right)/2]){
                return (left+right)/2;
            }else if(target > nums[(left+right)/2]){
                left = (left+right)/2;
            }else{
                right = (left+right)/2;
            }
        }
        if(target == nums[left] || target == nums[right]){
            return target==nums[left]?left:right;
        }
        return -1;
    }
};
