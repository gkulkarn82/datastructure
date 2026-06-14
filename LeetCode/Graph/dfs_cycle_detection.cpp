//Detecting a cycle in undirected graph DFS
#include <vector>
#include <stack>
using namespace std;

class Solution
{
    public:
        bool detectCycle(int V, vector<int> adj[])
        {
            int vis[V] = { 0 };
            std::stack<pair<int, int>> s;
            vis[0] = 1;
            s.push({0, -1});
            
            
            while(!s.empty())
            {
                int node = s.top().first;
                int parent = s.top().second;
                s.pop();

                for(auto it: adj[node])
                {
                    if(!vis[it])
                    {
                        s.push({it, node});
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