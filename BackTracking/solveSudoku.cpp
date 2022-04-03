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
#define N 9

const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;
// const int N = 0;

bool findEmptyLocation(int grid[N][N], int &row, int &col)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == 0)
            {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

bool isPoss(int grid[N][N], int key, int row, int col)
{
    for (int i = 0; i < N; i++)
    {
        if (grid[row][i] == key)
        {
            return false;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (grid[i][col] == key)
        {
            return false;
        }
    }

    int rowfac = row - (row % 3);
    int colfac = col - (col % 3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i + rowfac][j + colfac] == key)
            {
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(int grid[N][N])
{
    int row, col;
    if (!findEmptyLocation(grid, row, col))
    {
        return true;
    }

    for (int i = 1; i <= N; i++)
    {
        if (isPoss(grid, i, row, col))
        {
            grid[row][col] = i;
            bool smallAns = solveSudoku(grid);
            if (smallAns == true)
            {
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}
int main()
{

    // input
    int grid[N][N];
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < str.length(); j++)
        {
            grid[i][j] = str[j] - '0';
        }
    }

    solveSudoku(grid);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}

// 006307000
// 004000005
// 100006082
// 205030106
// 000200300
// 900070004
// 050000000
// 010000000
// 008109040