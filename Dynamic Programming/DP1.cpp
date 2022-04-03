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
const int N = 1e5 + 10;

int dp[N];

/* -------------------------- Brute-force approach -------------------------- */
int fibN(int n)
{
    if (n <= 1)
    {
        return n;
    }
    int a = fibN(n - 1);
    int b = fibN(n - 2);
    return a + b;
}
/* ------------------------------- memoization (top-down approach)------------------------------ */
int fib_helper(int n)
{
    if (n <= 1)
    {
        return n;
    }

    // check if ans already exists
    if (dp[n] != -1)
    {
        return dp[n];
    }

    // if ans doesnt exists then we called first time
    int a = fib_helper(n - 1);
    int b = fib_helper(n - 2);

    // save the ans for future use and return
    return dp[n] = a + b;
}

int fib(int n)
{
    memset(dp, -1, sizeof(dp));
    return fib_helper(n);
}

/* --------------------------- Dynamic programming (bottom-up approach)-------------------------- */
int fibDp(int n)
{
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

//! ---------------------------- /? min steps to 1 --------------------------- */

int mST11(int n)
{
    if (n == 1)
    {
        return 0;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int a = INT_MAX, b = INT_MAX, c = INT_MAX;
    a = mST11(n - 1);
    if (n % 2 == 0)
    {
        b = mST11(n / 2);
    }

    if (n % 3 == 0)
    {
        c = mST11(n / 3);
    }

    return dp[n] = 1 + min(a, min(b, c));
}

int mST1(int n)
{
    memset(dp, -1, sizeof(dp));
    return mST11(n);
}

int minStepsToOne(int n)
{
    // memset(dp,-1,sizeof(dp));
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 4; i <= n; i++)
    {
        int a = dp[i - 1];
        int b = INT_MAX, c = INT_MAX;
        if (i % 2 == 0)
        {
            b = dp[i / 2];
        }

        if (i % 3 == 0)
        {
            c = dp[i / 3];
        }

        dp[i] = 1 + min(a, min(b, c));
    }
    return dp[n];
}

//*  -------------------------------- staircase ------------------------------- */
int sc1(int n)
{
    if (n == 1)
    {
        return 1;
    }

    if (n == 2)
    {
        return 2;
    }

    if (n == 3)
    {
        return 4;
    }

    int a = sc1(n - 1);
    int b = sc1(n - 2);
    int c = sc1(n - 3);
    return a + b + c;
}

int sc2(int n)
{
    if (n == 1)
    {
        return 1;
    }

    if (n == 2)
    {
        return 2;
    }

    if (n == 3)
    {
        return 4;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int a = sc2(n - 1);
    int b = sc2(n - 2);
    int c = sc2(n - 3);

    return dp[n] = a + b + c;
}

int stairCase(int n)
{
    memset(dp, -1, sizeof(dp));
    return sc2(n);
}

int minCount(int n)
{
    if (n == 0)
    {
        return 0;
    }

    int min_count = INT_MAX;
    for (int i = 1; i * i <= n; i++)
    {
        int a = minCount(n - i * i);
        min_count = 1 + min(a, min_count);
    }
    return min_count;
}

int lis(string s, int i)
{
    // if (s.size() == 0)
    // {
    //     return 0;
    // }

    int ans = 1;
    for (int j = i - 1; j >= 0; j--)
    {
        if (s[j] <= s[i])
        {
            ans = max(ans, lis(s, j) + 1);
        }
    }

    return ans;
}

int mc_helper(int n)
{
    if (n == 0)
    {
        return 0;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int min_count = INT_MAX;
    for (int i = 1; i * i <= n; i++)
    {
        min_count = min(min_count, 1 + mc_helper(n - i * i));
    }

    return dp[n] = min_count;
}

int mC1(int n)
{
    memset(dp, -1, sizeof(dp));
    return mc_helper(n);
}

int possCombinations(int n)
{
    if (n == 1 || n == 0)
    {
        return n;
    }

    if (n == 2)
    {
        return 3;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int sa1 = possCombinations(n - 1);
    int sa2 = possCombinations(n - 2);
    int f = (int)(((long)(sa1)*sa1) % M);
    int s = (int)((2 * (long)(sa1)*sa2) % M);
    int ans = (f + s) % M;
    return dp[n] = ans;
}

int balancedBtCombinations(int n)
{
    memset(dp, -1, sizeof(dp));
    return possCombinations(n);
}

int main()
{

    // cout << possCombinations(5);
    cout << balancedBtCombinations(10);

    return 0;
}