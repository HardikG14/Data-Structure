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

bool isPoss(vector<vector<char>> &board, int i, int j, string s, int m, int n, vector<vector<bool>> &visited)
{

    if (board[i][j] == 'A')
    {
        return true;
    }

    visited[i][j] = true;
    bool ans = false;
    if ((i - 1 >= 0 && j - 1 >= 0) && board[i - 1][j - 1] == s[0] && !visited[i - 1][j - 1])
    {
        ans = isPoss(board, i - 1, j - 1, s.substr(1), m, n, visited);
        if (ans)
        {
            return ans;
        }
    }
    if ((i - 1 >= 0) && board[i - 1][j] == s[0] && !visited[i - 1][j])
    {
        ans = isPoss(board, i - 1, j, s.substr(1), m, n, visited);
        if (ans)
        {
            return ans;
        }
    }
    if ((i - 1 >= 0 && j + 1 < n) && board[i - 1][j + 1] == s[0] && !visited[i - 1][j + 1])
    {
        ans = isPoss(board, i - 1, j + 1, s.substr(1), m, n, visited);
        if (ans)
        {
            return ans;
        }
    }
    if ((j + 1 < n) && board[i][j + 1] == s[0] && !visited[i][j + 1])
    {
        ans = isPoss(board, i, j + 1, s.substr(1), m, n, visited);
        if (ans)
        {
            return ans;
        }
    }
    if ((i + 1 < m && j + 1 < n) && board[i + 1][j + 1] == s[0] && !visited[i + 1][j + 1])
    {
        ans = isPoss(board, i + 1, j + 1, s.substr(1), m, n, visited);
        if (ans)
        {
            return ans;
        }
    }
    if ((i + 1 < m) && board[i + 1][j] == s[0] && !visited[i + 1][j])
    {
        ans = isPoss(board, i + 1, j, s.substr(1), m, n, visited);
        if (ans)
        {
            return ans;
        }
    }
    if ((i + 1 < m && j - 1 >= 0) && board[i + 1][j - 1] == s[0] && !visited[i + 1][j - 1])
    {
        ans = isPoss(board, i + 1, j - 1, s.substr(1), m, n, visited);
        if (ans)
        {
            return ans;
        }
    }
    if ((j - 1 >= 0) && board[i][j - 1] == s[0] && !visited[i][j - 1])
    {
        ans = isPoss(board, i, j - 1, s.substr(1), m, n, visited);
        if (ans)
        {
            return ans;
        }
    }

    return ans;
}

bool hasPath(vector<vector<char>> &board, int m, int n)
{
    vector<vector<bool>> visited;
    rep(i, 0, m)
    {
        vector<bool> ne(n);
        rep(j, 0, n)
        {
            ne[j] = false;
        }
        visited.push_back(ne);
    }
    string s = "ODINGNINJA";
    bool ans = false;
    rep(i, 0, m)
    {
        rep(j, 0, n)
        {
            if (board[i][j] == 'C')
            {
                ans = isPoss(board, i, j, s, m, n, visited);
            }
        }
    }
    return ans;
}

int main()
{

    return 0;
}