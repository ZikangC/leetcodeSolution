class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int* degree = new int[numCourses](0);
        queue<int> q;
        vector<vector<int>> relation(numCourses,vector<int>());
        for(auto i : prerequisites){
            degree[i[0]]++;
            relation[i[1]].push_back(i[0]);
        }
        for(int i = 0; i < numCourses; i++){
            if(degree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int tmp = q.front();
            for(auto i : relation[tmp]){
                degree[i]--;
                if(degree[i] == 0){
                    q.push(i);
                }
            }
            q.pop();
        }
        for(int i = 0; i < numCourses; i++){
            if(degree[i] != 0){
                return false;
            }
        }
        return true;
    }
};
