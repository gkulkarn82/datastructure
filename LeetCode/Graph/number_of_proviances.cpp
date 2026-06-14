//Number Of Proviances
#include <vector>
using namespace std;

class Solution
{
    private:
        void dfs(int node, vector<int> adjLS[], int vis[])
        {
            vis[node] = 1;
            for(auto it: adjLS[node])
            {
                if(!vis[it])
                {
                    dfs(it, adjLS, vis);
                }
            }
        }
    public:
        int numberProviances(vector<vector<int>> adj, int v)
        {
            int vis[v] ={0};
            vector<int> adjLs[v];

            //We have given matrix from that we need to create adjesensy list
            for(int i = 0 ; i < v; ++i)
            {
                for(int j = 0; j < v; ++j)
                {
                    if(adj[i][j] == 1 && i != j)
                    {
                        adjLs[i].push_back(j);
                        adjLs[j].push_back(i);
                    }
                }
            }

            int cnt = 0;
            for(int i = 0 ; i <v; ++i)
            {
                if(!vis[i])
                {
                    cnt++;
                    dfs(i, adjLs, vis);
                }
            }

            return cnt;
        }
};