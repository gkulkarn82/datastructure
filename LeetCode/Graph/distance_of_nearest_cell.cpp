//Distance of nearest cell having 1
#include <vector>
#include <queue>
using namespace std;

class Solution
{
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n ,vector<int>(m, 0));
        vector<vector<int>> dist(n ,vector<int>(m, 0));
        std::queue<pair<pair<int, int>, int>> q;

        for(int i =0 ; i < n ; ++i)
        {
            for(int j =0 ; j < m; ++j)
            {
                if(grid[i][j] == 1)
                {
                    q.push({{1,j}, 0});
                    vis[i][j] = 1;
                }
                else
                {
                    vis[i][j] = 0;
                }
            }
        }

        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};

        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int distance = q.front().second;

            dist[row][col] = distance;
            for(int i = -1; i <=1; ++i)
            {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if(nrow >=0 && nrow < n && ncol >= 0 && ncol < m 
                && vis[nrow][ncol] == 0)
                {
                    vis[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, distance + 1});
                }
            }
        }
        return dist;
    }  
};