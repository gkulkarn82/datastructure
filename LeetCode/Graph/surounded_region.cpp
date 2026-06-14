//Surrounded region
#include <vector>
#include <queue>
using namespace std;

class Solution
{
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& mat)
    {
        vis[row][col] = 1;

        int n = mat.size();
        int m = mat[0].size();
    
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0 , -1};

        for(int i = 0 ; i < 4; ++i)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if(nrow >= 0 && nrow < n && ncol >=0 && ncol <m &&
                mat[nrow][ncol] == '0')
            {
                dfs(nrow, ncol, vis, mat);
            }
        }
    }
    public:
        vector<vector<char>> fill(int n, int m, vector<vector<char>>& mat)
        {
            vector<vector<int>> vis(n, vector<int>(m, 0));
            for(int i = 0 ; i < n; ++i)
            {
                if(mat[0][i] == '0' && !vis[0][i])
                {
                    dfs(0, i, vis, mat);
                }

                if(mat[n - 1][i] == '0' && !vis[n-1][i])
                {
                    dfs(n-1, i, vis, mat);
                }
            }

            for(int i = 0 ; i < m; ++i)
            {
                if(mat[i][0] == '0' && !vis[i][0])
                {
                    dfs(i, 0, vis, mat);
                }

                if(mat[i][m - 1] == '0' && !vis[i][m - 1])
                {
                    dfs(i, m - 1, vis, mat);
                }
            }


            for(int i = 0 ; i < n; ++i)
            {
                for(int j =0 ; j < m; ++j)
                {
                    if(mat[i][j] == '0' && !vis[i][j])
                    {
                        mat[i][j] = 'x';
                    }
                }
            }

            return mat;
        }
};