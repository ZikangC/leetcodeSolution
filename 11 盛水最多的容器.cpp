class Solution {
public:
    int maxArea(vector<int>& height) {
        int res;
        int len = height.size();
        if(len == 2){
            return min(height[0],height[1]);
        }
        int left = 0;
        int right = len - 1;
        res = (len - 1)*min(height[left],height[right]);
        while(left < right){
            if(height[left] <= height[right]){
                left++;
                res = max(res, (right - left) * min(height[left],height[right]));
            }else{
                right--;
                res = max(res, (right - left) * min(height[left],height[right]));
            }
        }
        return res;
    }
};
