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

void dfs(int **edges, int n, int s, bool *visited)
{
    visited[s] = true;
    rep(i, 0, n)
    {
        if (edges[s][i] == 1 && !visited[i])
        {
            dfs(edges, n, i, visited);
        }
    }
}

int islands(int **edges, int n)
{
    bool *visited = new bool[n];
    rep(i, 0, n)
    {
        visited[i] = false;
    }
    int count = 0;
    rep(i, 0, n)
    {
        if (!visited[i])
        {
            count++;
            dfs(edges, n, i, visited);
        }
    }
    return count;
}

int main()
{

    int n, e;
    cin >> n >> e;

    int **path = new int *[n];
    rep(i, 0, n)
    {
        path[i] = new int[n];
        rep(j, 0, n)
        {
            path[i][j] = 0;
        }
    }

    rep(i, 0, e)
    {
        int f, s;
        cin >> f >> s;
        path[s][f] = 1;
        path[f][s] = 1;
    }

    cout << islands(path, n);
    rep(i, 0, n)
    {
        delete[] path[i];
    }
    delete[] path;
    return 0;
}