#include <bits/stdc++.h>
#include "HashMaps.h"
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

int getBucketIndex(string key)
{
    int hashCode = 0;
    int curr = 1;
    for (int i = key.size() - 1; i >= 0; i--)
    {
        hashCode += key[i] * curr;
        hashCode = hashCode % 20;
        curr *= 37;
        curr = curr % 20;
    }
    return hashCode % 20;
}
int main()
{

    // HashMaps<int> h;
    // // cout << h.size() << endl;
    // h.insert("hardik", 22);
    // h.insert("swagat", 15);
    // h.insert("avishkar", 18);
    // // cout << h.getValue("hardik");
    // h.remove("hardik");
    // h.remove("Harfik");
    // cout << h.getValue("hardik");
    cout << getBucketIndex("hardik");
    cout << getBucketIndex("Hardik");
    return 0;
}