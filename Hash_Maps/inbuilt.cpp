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
vector<int> removeDuplicate(int *arr, int n)
{
    vector<int> out;
    unordered_map<int, bool> m;
    for (int i = 0; i < n; i++)
    {
        if (m.count(arr[i]) == 0)
        {
            m.insert({arr[i], true});
            out.push_back(arr[i]);
        }
    }
    return out;
}

void printVec(vector<long long int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
vector<long long int> factorial(int N)
{
    // code here
    vector<long long int> ans;
    ans.push_back(1l);
    for (int i = 1; i < N + 1; i++)
    {
        ans.push_back(i * ans[i - 1]);
    }
    return ans;
}
int main()
{

    // int arr[] = {1, 2, 3, 3, 2, 1, 2, 3, 4, 5, 4, 3, 2, 7, 8};
    // vector<int> ans = removeDuplicate(arr, 15);
    // printVec(ans);
    vector<long long int> ans = factorial(15);
    printVec(ans);
    return 0;
}