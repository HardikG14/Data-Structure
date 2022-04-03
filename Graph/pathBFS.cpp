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

vector<int> path_BFS(int **edges, int n, int s, int e, bool *visited)
{
    queue<int> que;
    unordered_map<int, int> mp;
    vector<int> ans;
    que.push(s);
    visited[s] = true;

    while (!que.empty() && que.front() != e)
    {
        int top = que.front();
        que.pop();
        for (int i = 0; i < n; i++)
        {
            if (edges[top][i] == 1 && !visited[i])
            {
                que.push(i);
                mp.insert({i, top});
                visited[i] = true;
            }
        }
    }

    if (que.front() == e)
    {
        ans.push_back(e);
        int q = e;
        while (q != s)
        {
            q = mp[q];
            ans.push_back(q);
        }
    }

    return ans;
}

vector<int> BFSPath(int **edges, int n, int s, int e)
{
    bool *visited = new bool[n];
    rep(i, 0, n)
    {
        visited[i] = false;
    }
    return path_BFS(edges, n, s, e, visited);
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
    vector<int> re = BFSPath(edges, n, v1, v2);

    for (auto &it : re)
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