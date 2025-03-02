// class Solution {
// public:
//     int n;
//     vector<int> degreein;
//     vector< vector<int> > rGraph;
//     vector<int> ans;
    
//     void init(vector<vector<int>>& G){
//         n = G.size();
//         degreein = vector<int>(n,0);
//         rGraph.resize(n, vector<int>(0) );
        
//         for (int u=0; u<n; u++){
//             for (int v:G[u]){
//                 rGraph[v].push_back(u);
//                 degreein[u]++;
//             }
//         }
//     }
    
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         init(graph);
//         queue<int> que;
//         for (int i=0; i<n; i++){
//             if (degreein[i]==0) que.push(i);
//         }
//         while (que.size()){
//             int u = que.front(); que.pop();
//             ans.push_back(u);
//             for (int v:rGraph[u]){
//                 degreein[v]--;
//                 if (degreein[v]==0) que.push(v);
//             }
//         }
//         sort(ans.begin(),ans.end());
//         return ans;
//     }
// };
class Solution {
public:
    bool dfs(int node,vector<int> &visited,vector<int> &pathVisited,vector<int> &checked,vector<vector<int>> &graph)
    {
        visited[node]=1;
        pathVisited[node]=1;

        for(int nei : graph[node])
        {
            if(!visited[nei])
            {
                if(dfs(nei,visited,pathVisited,checked,graph))
                {
                    return true;
                }
            }
              else if(pathVisited[nei]==1)
                {
                    return true;
                }
        }
        checked[node]=1;
        pathVisited[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
     int n = graph.size();
     vector<int> visited(n,0);
     vector<int> pathVisited(n,0);
     vector<int> checked(n,0);
     vector<int> safe;

     for(int i=0;i<n;i++)
     {
        if(!visited[i])
        {
            dfs(i,visited,pathVisited,checked,graph);
        }
     }

     for(int i=0;i<n;i++)
     {
        if(checked[i]==1)
        safe.push_back(i);
     }
     return safe;
    }
};