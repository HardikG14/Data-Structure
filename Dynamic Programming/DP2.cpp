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
const int N = 100;

int dpArr[N];
int dp[N][N];

// void takeInput(int m, int n)
// {
//     rep(i, 0, m)
//     {
//         rep(j, 0, n)
//         {
//             cin >> arr[i][j];
//         }
//     }
// }

void print2D(int m, int n)
{
    rep(i, 0, m)
    {
        rep(j, 0, n)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int minCostPathBruteForce(int arr[][100], int m, int n, int i, int j)
{
    if (i == m)
    {
        return INT_MAX;
    }
    if (j == n)
    {
        return INT_MAX;
    }

    if (i == m - 1 && j == n - 1)
    {
        return arr[i][j];
    }

    int f = minCostPathBruteForce(arr, m, n, i, j + 1);
    int s = minCostPathBruteForce(arr, m, n, i + 1, j);
    int t = minCostPathBruteForce(arr, m, n, i + 1, j + 1);

    return arr[i][j] + min(f, min(s, t));
}

int minCostmemoization_helper(int arr[][100], int m, int n, int i, int j)
{
    if (i == m || j == n)
    {
        return INT_MAX;
    }

    if (i == m - 1 && j == n - 1)
    {
        return arr[i][j];
        // dp[i][j]
    }

    //  memoizationStep: check if ans already exists
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    // if ans doesnt exists then further calculations
    int a = minCostmemoization_helper(arr, m, n, i + 1, j);
    int b = minCostmemoization_helper(arr, m, n, i, j + 1);
    int c = minCostmemoization_helper(arr, m, n, i + 1, j + 1);

    // save ans then return
    return dp[i][j] = arr[i][j] + min(a, min(b, c));
}

int minCostMemoization(int arr[][100], int m, int n, int i, int j)
{
    memset(dp, -1, sizeof(dp));
    return minCostmemoization_helper(arr, m, n, i, j);
}

int minCostdp(int arr[][100], int m, int n, int i, int j)
{
    dp[m - 1][n - 1] = arr[m - 1][n - 1];
    for (int k = m - 2; k >= 0; k--)
    {
        dp[k][n - 1] = arr[k][n - 1] + dp[k + 1][n - 1];
    }

    for (int k = n - 2; k >= 0; k--)
    {
        dp[m - 1][k] = arr[m - 1][k] + dp[m - 1][k + 1];
    }

    for (int k = m - 2; k >= 0; k--)
    {
        for (int l = n - 2; l >= 0; l--)
        {
            dp[k][l] = arr[k][l] + min(dp[k][l + 1], min(dp[k + 1][l], dp[k + 1][l + 1]));
        }
    }

    return dp[0][0];
}

int lcs(string s, string t, int i, int j)
{
    if (i == s.size() || j == t.size())
    {
        return 0;
    }

    int a = lcs(s, t, i + 1, j);
    int b = lcs(s, t, i, j + 1);
    int c = lcs(s, t, i + 1, j + 1);

    if (s[i] == t[j])
    {
        return max(a, max(b, c)) + 1;
    }
    return max(a, max(b, c));
}

int helper(string s, string t, int i, int j)
{
    if (i == s.size() || j == t.size())
    {
        // dp[i][j] = 0;
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if (s[i] == t[j])
    {
        return dp[i][j] = 1 + helper(s, t, i + 1, j + 1);
    }

    int a = helper(s, t, i + 1, j);
    int b = helper(s, t, i, j + 1);
    int c = helper(s, t, i + 1, j + 1);

    return dp[i][j] = max(a, max(b, c));
}

int longestCommonSubSeq(string s, string t)
{
    memset(dp, -1, sizeof(dp));
    return helper(s, t, 0, 0);
}

int editDistBF(string s, string t)
{
    if (s.size() == 0 || t.size() == 0)
    {
        return max(s.size(), t.size());
    }

    if (s[0] == t[0])
    {
        return editDistBF(s.substr(1), t.substr(1));
    }
    int i = editDistBF(s.substr(1), t) + 1;
    int r = editDistBF(s, t.substr(1)) + 1;
    int u = editDistBF(s.substr(1), t.substr(1)) + 1;

    return min(i, min(r, u));
}

int editDistMem(string s, string t)
{
    if (s.size() == 0 || t.size() == 0)
    {
        return max(s.size(), t.size());
    }
    int m = s.size(), n = t.size();
    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }

    if (s[0] == t[0])
    {
        return editDistMem(s.substr(1), t.substr(1));
    }

    // insert
    int i = editDistMem(s.substr(1), t) + 1;
    // remove
    int r = editDistMem(s, t.substr(1)) + 1;
    // update
    int u = editDistMem(s.substr(1), t.substr(1)) + 1;

    return min(i, min(r, u));
}

int editDistm(string s, string t)
{
    memset(dp, -1, sizeof(dp));
    return editDistMem(s, t);
}

int knapsack(int *wei, int *val, int i, int n, int w)
{
    if (w <= 0 || i == n)
    {
        return 0;
    }

    if (wei[i] > w)
    {
        return knapsack(wei, val, i + 1, n, w);
    }

    int a = knapsack(wei, val, i + 1, n, w - wei[i]) + val[i];
    int b = knapsack(wei, val, i + 1, n, w);
    return max(a, b);
}

int maxMoneymem(int *arr, int i, int n)
{
    if (i >= n)
    {
        return 0;
    }

    if (dpArr[i] != -1)
    {
        return dpArr[i];
    }
    int a = arr[i] + maxMoneymem(arr, i + 2, n);
    int b = maxMoneymem(arr, i + 1, n);

    return dpArr[i] = max(a, b);
}

int maxMon(int *arr, int n)
{
    memset(dpArr, -1, sizeof(dpArr));
    return maxMoneymem(arr, 0, n);
}

int longestIncreasingSubseq(int *arr, int i, int n)
{
    int a = 1;
    if (dpArr[i] != -1)
    {
        return dpArr[i];
    }
    for (int j = i - 1; j >= 0; j--)
    {
        if (arr[j] < arr[i])
        {
            a = max(a, longestIncreasingSubseq(arr, j, n) + 1);
        }
        int b = longestIncreasingSubseq(arr, i - 1, n);
    }
    return dpArr[i] = a;
}

int lcs(int *arr, int i, int n)
{
    memset(dpArr, -1, sizeof(dpArr));
    return longestIncreasingSubseq(arr, i, n);
}

int countWaysToMakeChange(int arr[], int n, int w)
{
    // Write your code here
    if (w <= 0)
    {
        return 0;
    }
    int ways = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= w)
        {
            ways = min(ways, 1 + countWaysToMakeChange(arr, n, w - arr[i]));
        }
    }

    return ways;
}

int knapSackDP(int *wei, int *val, int n, int w)
{
    int arr[n + 1][w + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
            {
                arr[i][j] = 0;
            }
            else
            {
                if (wei[i - 1] > j)
                {
                    arr[i][j] = arr[i - 1][j];
                }
                else
                {
                    arr[i][j] = max(val[i - 1] + arr[i - 1][j - wei[i - 1]], arr[i - 1][j]);
                }
            }
        }
    }
    rep(i, 0, n + 1)
    {
        rep(j, 0, w + 1)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return arr[n][w];
}

int helper_noOfWays(int x, int currNo, int b)
{
    if (x < 0)
    {
        return 0;
    }

    if (x == 0)
    {
        return 1;
    }

    int ans = 0;
    for (int i = currNo; pow(i, b) <= x; i++)
    {
        ans += helper_noOfWays(x - pow(i, b), i + 1, b);
    }

    return dpArr[x] = ans;
}

int main()
{
    int n, w;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> w;
    cout << CC(arr, n, w);
    return 0;
}