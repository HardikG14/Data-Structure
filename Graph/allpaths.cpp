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

void allPaths(vector<vector<int>> &edges, int s, int e, int n, vector<bool> &visited, vector<int> &curr, vector<vector<int>> &all)
{
    if (s == e)
    {
        curr.push_back(s);
        all.push_back(curr);
        curr.pop_back();
        return;
    }

    visited[s] = true;
    curr.push_back(s);
    rep(i, 0, n)
    {
        if (edges[s][i] == 1 && !visited[i])
        {
            allPaths(edges, i, e, n, visited, curr, all);
        }
    }
    visited[s] = false;
    curr.pop_back();
}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<vector<int>> edges;
    rep(i, 0, n)
    {
        vector<int> ne(n, 0);
        edges.push_back(ne);
    }

    rep(i, 0, e)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    vector<bool> visited(n, false);
    vector<int> curr;
    vector<vector<int>> ans;
    int v1, v2;
    cin >> v1 >> v2;

    allPaths(edges, v1, v2, n, visited, curr, ans);
    rep(i, 0, ans.size())
    {
        rep(j, 0, ans[i].size())
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}