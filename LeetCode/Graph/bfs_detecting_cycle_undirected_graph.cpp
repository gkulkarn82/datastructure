//Detecting a cycle in undirected graph
#include <vector>
#include <queue>
using namespace std;

class Solution
{
    public:
        bool detectCycle(int V, vector<int> adj[])
        {
            int vis[V] = { 0 };
            std::queue<pair<int, int>> q;
            vis[0] = 1;
            q.push({0, -1});
            
            while(!q.empty())
            {
                int node = q.front().first;
                int parent = q.front().second;
                q.pop();

                for(auto it: adj[node])
                {
                    if(!vis[it])
                    {
                        q.push({it, node});
                        vis[it] = 1;
                    }
                    else if(parent != it)
                    {
                        return true;
                    }
                }
                return false;
            }
        }
};