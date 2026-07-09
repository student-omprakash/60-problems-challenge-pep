class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        //now build the adjecency list and indegree matrix
        for(auto &pair:prerequisites){
            int course=pair[0];
            int pre=pair[1];
            adj[pre].push_back(course);
            indegree[course]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int completed=0;

        while(!q.empty()){
            int current=q.front();
            q.pop();
            completed++;
            for(int next:adj[current]){
                indegree[next]--;
                if(indegree[next]==0){
                    q.push(next);
                }
            }
        }
        return completed==numCourses;

        
        
    }
};