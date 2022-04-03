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

void is_Connected_helper(int **edges, int n, int s, bool *visited)
{
    visited[s] = true;
    for (int i = 0; i < n; i++)
    {
        if (edges[s][i] == 1 && !visited[i])
        {
            is_Connected_helper(edges, n, i, visited);
        }
    }
}

bool isConnected(int **edges, int n)
{
    bool *visited = new bool[n];
    rep(i, 0, n)
    {
        visited[i] = false;
    }
    is_Connected_helper(edges, n, 0, visited);
    bool ans = true;
    rep(j, 0, n)
    {
        if (!visited[j])
        {
            ans = false;
            break;
        }
    }
    delete[] visited;
    return ans;
}

int main()
{

    int n, e;
    cin >> n >> e;

    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    // function goes here;
    cout << isConnected(edges, n);

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}