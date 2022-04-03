#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define all(x) (x).begin(), (x).end()
#define uniq(v) (v).erase(unique(all(v)), (v).end())
#define sz(x) (int)((x).size())
#define fr first
#define sc second
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define ppc __builtin_popcount
#define ppcll __builtin_popcountll

const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;
const int N = 0;

int grid[10][10];

bool isPossible(int grid[][10], int n, int row, int col)
{
    // coloumn check
    for (int i = row - 1; i >= 0; i--)
    {
        if (grid[i][col] == 1)
        {
            return false;
        }
    }
    // row check
    for (int i = col - 1; i >= 0; i--)
    {
        if (grid[row][i] == 1)
        {
            return false;
        }
    }

    // left diagonal check;
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (grid[i][j] == 1)
        {
            return false;
        }
    }

    // right diag _Check
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (grid[i][j] == 1)
        {
            return false;
        }
    }
    return true;
}
void helper(int grid[10][10], int n, int row)
{
    if (row == n)
    {
        // print matrix
        rep(i, 0, n)
        {
            rep(j, 0, n)
            {
                cout << grid[i][j] << " ";
            }
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (isPossible(grid, n, row, i))
        {
            grid[row][i] = 1;
            helper(grid, n, row + 1);
            grid[row][i] = 0;
        }
    }
}
void nQueen(int n)
{
    memset(grid, 0, 10 * 10 * sizeof(int));
    helper(grid, n, 0);
}
int main()
{
    int n;
    cin >> n;
    nQueen(n);
    return 0;
}
