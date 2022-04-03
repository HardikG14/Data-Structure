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

void printGraphDFS(int **edges, int n, int sv, bool *arr)
{
    cout << sv << " ";
    arr[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (edges[sv][i] == 1)
        {
            if (arr[i])
            {
                continue;
            }
            printGraphDFS(edges, n, i, arr);
        }
    }
}

void printGraphBFS(int **edges, int sv, int n, bool *visited)
{
    queue<int> que;
    que.push(sv);
    visited[sv] = true;

    while (!que.empty())
    {
        int top = que.front();
        cout << top << " ";
        que.pop();
        for (int i = 0; i < n; i++)
        {
            if (edges[top][i] == 1)
            {
                if (visited[i])
                {
                    continue;
                }
                else
                {
                    que.push(i);
                    visited[i] = true;
                }
            }
        }
    }
}

void bfsConnected(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            printGraphBFS(edges, i, n, visited);
        }
    }

    delete[] visited;
}

void dfsConnected(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            printGraphDFS(edges, n, i, visited);
        }
    }

    delete[] visited;
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

    bfsConnected(edges, n);
    cout << endl;
    dfsConnected(edges, n);

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}