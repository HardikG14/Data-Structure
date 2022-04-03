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

bool getPath(int **edges, int n, int s, int e, bool *visited, vector<int> &ans)
{
    if (s == e)
    {
        ans.push_back(s);
        return true;
    }

    visited[s] = true;
    bool b = false;
    rep(i, 0, n)
    {
        if (edges[s][i] == 1 && !visited[i])
        {
            b = getPath(edges, n, i, e, visited, ans);
            if (b)
            {
                ans.push_back(s);
                return true;
            }
        }
    }
    return b;
}

vector<int> GetPath(int **edges, int n, int s, int e)
{
    vector<int> ans;
    bool *visited = new bool[n];
    rep(i, 0, n)
    {
        visited[i] = false;
    }

    bool b = getPath(edges, n, s, e, visited, ans);
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

    int v1, v2;
    cin >> v1 >> v2;
    vector<int> ans;
    ans = GetPath(edges, n, v1, v2);

    for (auto &it : ans)
    {
        cout << it << " ";
    }

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}