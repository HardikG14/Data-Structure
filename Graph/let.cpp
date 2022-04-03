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

    priority_queue<int, vector<int>, greater<int>> que;
    // int data;
    // cin >> data;
    // while (data != -1)
    // {
    //     que.push(data);
    //     cin >> data;
    // }

    // while (!que.empty())
    // {
    //     cout << que.top() << " ";
    //     que.pop();
    // }
    vector<int> vec = {1, 2, 3, 4, 5};
    cout << vec.size();
    vec.clear();
    cout << vec.size();

    return 0;
}