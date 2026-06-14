// DFS traversal graph
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
#include <stack>
using namespace std;

class Solution
{
    private:
        void dfs(int node, std::vector<int> adj[], int vis[], std::vector<int>& ls)
        {
            vis[node] = 1;
            ls.push_back(node);

            for(auto it: adj[node])
            {
                if(!vis[it])
                {
                    dfs(it, adj, vis, ls);
                }
            }
        }
    public:
        vector<int> dfsOfGraph(int V, vector<int> adj[])
        {
            int vs[V] = {0};
            int start = 0;
            std::vector<int> ls;
            
            //With Recursion
            dfs(start, adj, vs, ls);
            return ls;


            //Without recursion
            std::stack<int> st;
            st.push(0);
            while(!st.empty())
            {
                int node = st.top();
                st.pop();
                vs[node] = 1;
                ls.push_back(node);
                for(auto it: adj[node])
                {
                    if(!vs[it])
                    {
                        st.push(it);
                    }
                }
            }
        }
};