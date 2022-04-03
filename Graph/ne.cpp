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

void printBFS(int **edges, int n, int sv, bool *visited)
{
    queue<int> que;
    que.push(sv);
    visited[sv] = true;

    while (!que.empty())
    {
        int topNode = que.front();
        cout << topNode << " ";
        que.pop();
        rep(i, 0, n)
        {
            if (edges[topNode][i] == 1 && !visited[i])
            {
                que.push(i);
                visited[i] = true;
            }
        }
    }
}

void BFS(int **edges, int n)
{
    bool *visited = new bool[n];
    rep(i, 0, n)
    {
        visited[i] = 0;
    }
    rep(i, 0, n)
    {
        if (!visited[i])
        {
            printBFS(edges, n, i, visited);
        }
    }
}

int main()
{

    // making graph;
    int n, e;
    cin >> n >> e;

    int **edges = new int *[n];
    rep(i, 0, n)
    {
        edges[i] = new int[n];
        rep(j, 0, n)
        {
            edges[i][j] = 0;
        }
    }

    rep(i, 0, e)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    // print bfs traversal
    BFS(edges, n);

    rep(i, 0, n)
    {
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}