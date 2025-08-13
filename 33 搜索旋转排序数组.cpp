class Solution {
public:
    int searchpart(vector<int>& nums, int target, int begin, int end){
        if(end < begin){
            return -1;
        }
        if(target > nums[end]){
            return -1;
        }else if(target < nums[begin]){
            return -1;
        }
        int index = (begin + end)/2;
        if(nums[index] == target){
            return index;
        }
        if(nums[index] < target){
            return searchpart(nums,target,index+1,end);
        }else{
            return searchpart(nums,target,begin,index-1);
        }
        return 0;
    }
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        while(left <= right){
            int mid = (left + right) /2;
            if(nums[mid] < nums[right]){
                right = mid;
            }else if(nums[mid] > nums[right]){
                left = mid + 1;
            }else{
                left = mid;
                break;
            }
        }
        if(target == nums[len -1]){
            return len - 1;
        }else if(target > nums[len - 1]){
            return searchpart(nums,target,0,left-1);
        }else{
            return searchpart(nums,target,left,len-1);
        }
        return 0;
    }
};
