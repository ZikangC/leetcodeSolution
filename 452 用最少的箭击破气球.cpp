class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[0] < b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        int pos = points[0][1];
        int len = points.size();
        int res = 1;
        for(int i = 1; i < len; i++){
            if(points[i][0] > pos){
                res++;
                pos = points[i][1];
            }else{
                pos = min(pos,points[i][1]);
            }
        }
        return res;
    }
};
