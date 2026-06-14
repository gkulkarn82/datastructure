// BFS traversal graph
/*
    The data structure used in stroing the graph data is generally an adjusancy list.
    This is nothing but the vector<vector<int>> means mapping which vertices are rechanble from current node

    One more thing which is needed for the graph is visitors array to make sure we visited the node.

    These 2 things are most important for the grpah issues.
    1. Adjesensy List
    2. Visitors Array
*/
#include <vector>
#include <queue>
using namespace std;

class Solution
{

    public:
        vector<int> bfsOfGraph(int V, vector<int> adj[])
        {
            int vis[V] = {0};
            vis[0] = 1;
            std::queue<int> qu;
            qu.push(0);
            vector<int> bfs;

            while(!qu.empty())
            {
                int node = qu.front();;
                qu.pop();
                bfs.push_back(node);

                for(auto& it: adj[node])
                {
                    if(!vis[node])
                    {
                        vis[node] = 1;
                        qu.push(it);
                    }
                }
            }

            return bfs; 
        }
};

/*
    Space Complexity
        Visited Array : 1 (n)
        Adj List      : 1 (n)  //This is provided hence can be skipped
        Queue         : 1 (n)
        BFS List      : 1 (n)

                    3N which is N

    Time Complexity
        Total Nodes : N
        Queue Run for all its egdes : which is 2E

        N + 2E


*/