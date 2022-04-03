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

int helper(vector<vector<int>> &cake, int i, int j, int n, vector<vector<bool>> &visited)
{
    visited[i][j] = true;
    int a = 0, b = 0, c = 0, d = 0;

    if ((i - 1 >= 0) && cake[i - 1][j] == 1 && !visited[i - 1][j])
    {
        a = helper(cake, i - 1, j, n, visited);
    }

    if ((j - 1 >= 0) && cake[i][j - 1] == 1 && !visited[i][j - 1])
    {
        b = helper(cake, i, j - 1, n, visited);
    }

    if ((i + 1 < n) && cake[i + 1][j] == 1 && !visited[i + 1][j])
    {
        c = helper(cake, i + 1, j, n, visited);
    }

    if ((j + 1 < n) && cake[i][j + 1] == 1 && !visited[i][j + 1])
    {
        d = helper(cake, i, j + 1, n, visited);
    }

    return a + b + c + d + 1;
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n)
{
    // Write your code here
    vector<vector<bool>> visited;
    rep(i, 0, n)
    {
        vector<bool> a(n);
        rep(j, 0, n)
        {
            a[j] = false;
        }
        visited.push_back(a);
    }

    int m = INT_MIN;
    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
            if (cake[i][j] == 1 && !visited[i][j])
            {
                int x = helper(cake, i, j, n, visited);
                m = max(m, x);
            }
        }
    }
    return m;
}

template <typename T>
void print(vector<vector<T>> &arr, int n)
{
    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{

    int n;
    cin >> n;
    vector<vector<int>> cake;

    rep(i, 0, n)
    {
        vector<int> a(n);
        rep(j, 0, n)
        {
            cin >> a[j];
        }
        cake.push_back(a);
    }

    cout << getBiggestPieceSize(cake, n);

    return 0;
}