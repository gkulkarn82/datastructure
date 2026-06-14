// Number of Island
#include <vector>
#include <queue>
using namespace std;

class Solution
{
    private:
        void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid)
        {
            vis[row][col] = 1;
            std::queue<pair<int, int>> q;
            q.push({row, col});

            while(!q.empty())
            {
                int noderow = q.front().first;
                int nodecol = q.front().second;
                q.pop();
                int n = grid.size();
                int m = grid[0].size();

                //This is important the traversal
                for(int deltaRow = -1; deltaRow <= 1; ++deltaRow)
                {
                    for(int deltaCol = -1; deltaCol <= 1; ++ deltaCol)
                    {
                        int nrow = noderow + deltaRow;
                        int ncol = nodecol + deltaCol;

                        if( grid[nrow][nodecol] != 0 && 
                            !vis[nrow][ncol] &&
                            nrow >= 0 && nrow < n &&
                            ncol >=0 && ncol < m
                          )
                          {
                                vis[nrow][ncol] = 1;
                                q.push({nrow, ncol});
                          }
                    }                   
                }
            }
        }
    public:
        int numIsland(vector<vector<char>>& grid)
        {
            int n = grid.size();
            int m = grid[0].size();
            int count;
            vector<vector<int>> vis(n, vector<int>(m,0));

            for(int i = 0 ; i < n ; ++i)
            {
                for(int j = 0; j < m ; ++j)
                {
                    if(!vis[i][j] && grid[i][j] == 1)
                    {
                        count++;
                        bfs(i, j, vis, grid);
                    }
                }
            }

        }
};