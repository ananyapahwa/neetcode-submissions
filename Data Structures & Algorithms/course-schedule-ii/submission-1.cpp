class Solution {
public:
    void dfs(vector<vector<int>>& adj,vector<int>& topo, vector<bool>& visited, int node
    , vector<bool>& pathVisited){
        visited[node] = true;
        pathVisited[node] = true;
        for(int n: adj[node]){
            if(!visited[n])
                dfs(adj, topo,visited, n, pathVisited);
            else{
                if(pathVisited[n]) return; 
            }
        }

        //when the dfs is complete add it to the topo sort
        topo.push_back(node);
        pathVisited[node] = false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         vector<vector<int>>adj(numCourses);
         vector<bool>visited(numCourses, false);
         vector<bool> pathVisited(numCourses , false);
          vector<int> topo;

         //first creating an adjascency list and calculate the indegree
         for(auto p : prerequisites){
            int v = p[0];
            int u = p[1];
            adj[u].push_back(v);
         }
        for(int i=0; i<numCourses; i++)
            if(!visited[i])
                dfs(adj,topo, visited, i, pathVisited);
        
         if(topo.size() != numCourses) return {};
         reverse(topo.begin(), topo.end());
         return topo;

    }
};
