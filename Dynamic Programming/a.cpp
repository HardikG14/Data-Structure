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

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        int n = x;
        int e = 0, o = 0;
        int first;
        while (x != 0)
        {
            if (x % 2 == 0)
            {
                e++;
            }
            else
            {
                o++;
            }
            if (x >= 1 && x <= 9)
            {
                first = x;
            }
            x /= 10;
        }

        if (e == 1 && o == 1)
        {
            cout << "NO" << endl;
        }
        else if (o >= 2 && e == 1)
        {
            if (n % 2 == 0)
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
        else if (e >= 2 && o == 1)
        {
            if (n % 2 != 0)
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
        else if (o >= 2 && e == 2)
        {
            if (n % 2 == 0 && first % 2 == 0)
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
        else if (e >= 2 && o == 2)
        {
            if (n % 2 != 0 && first % 2 != 0)
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
        else
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}