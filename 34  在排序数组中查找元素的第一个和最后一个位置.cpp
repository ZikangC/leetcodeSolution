class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 0){
            return {-1,-1};
        }
        int left = 0;
        int right = len - 1;
        int mid = 0;
        while(left <= right){
            mid = (left + right)/2;
            if(nums[mid] == target){
                left = mid;
                break;
            }else if(nums[mid] > target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        if(left > right||nums[left] != target){
            return {-1,-1};
        }
        mid = left;
        right = left;
        while(left-1>=0 && nums[left-1] == target){
            left--;
        }
        while(right+1<len && nums[right+1] == target){
            right++;
        }
        return {left,right};
    }
};
