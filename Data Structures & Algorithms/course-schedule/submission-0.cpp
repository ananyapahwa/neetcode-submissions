class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
         vector<vector<int>>adj(numCourses);
         vector<int> indegree(numCourses);
         queue<int> q;

         //first creating an adjascency list and calculate the indegree
         for(auto p : prerequisites){
            int v = p[0];
            int u = p[1];
            adj[u].push_back(v);
            indegree[v]++;
         }

        //push those nodes whose indegree = 0
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> topo;
        //kanhs algorithm
        while(!q.empty()){
            int f = q.front();
            q.pop();

            for(int n: adj[f]){
                indegree[n]--;
                if(indegree[n] == 0) q.push(n); 
            }

            topo.push_back(f);
        }

        if(topo.size() == numCourses) return true;
        else return false;
    }
};
