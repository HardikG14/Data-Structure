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

    unordered_map<string, int> m;
    m["hardik"] = 1;
    m["manu"] = 2;
    m["swagat"] = 3;

    for (auto it : m)
    {
        cout << it.first << " " << it.second << endl;
    }
    // unordered_map<string, int>::iterator it;
    // it = m.begin();

    // while (it != m.end())
    // {
    //     cout << it->first << " " << it->second << endl;
    //     it++;
    // }

    return 0;
}