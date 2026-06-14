// Rotten oranges
#include <vector>
#include <queue>
using namespace std;

class Solution
{
    public:
        int rottenOranges(vector<vector<int>>& grid)
        {
            int n = grid.size();
            int m = grid[0].size();
            int fresh = 0;
            int vis[n][m];

            //Here we are keeping pair of pair in quque
            // reason is first pair will have i and j location and last int will capture count 
            // the time BFS attempted which will give us how many attempt it took to rotten
            queue<pair<pair<int,int>, int>> q;

            for(int i = 0 ; i < n ; ++i)
            {
                for(int j =0 ; j < m; ++j)
                {
                    if(grid[i][j] == 2)
                    {
                        q.push({{i, j}, 0});
                        vis[i][j] = 2;
                    }
                    else
                    {
                        vis[i][j] = 0;
                    }

                    if(grid[i][j] == 1)
                        fresh++;
                }
            }

            int count = 0;
            while(!q.empty())
            {
                int row = q.front().first.first;
                int col = q.front().first.second;
                int time = q.front().second;
                count = max(count, time);

                int delRow[] = {-1 ,0 , +1, 0};
                int delCol[] = {0, +1, 0, -1};
                for(int i = 0 ; i < 4; ++i)
                {
                    int nrow = row + delRow[i];
                    int ncol = col + delCol[i];
                    
                    if(nrow >=0 && nrow <n && ncol >=0 && ncol <m &&
                       grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0)
                       {
                            q.push({{nrow, ncol}, time + 1});
                            vis[nrow][ncol] = 2;
                       }
                }
            }

            // There is one more way to fix this
            for(int i = 0; i < n;  ++i)
            {
                for(int j =0 ; j < m; ++j)
                {
                    if(vis[i][j] != 2 && grid[i][j] == 1)
                        return -1;
                }
            }

            if(count != fresh)
                return -1;
            else
                return count;
        }
};