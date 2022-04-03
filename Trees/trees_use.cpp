#include <bits/stdc++.h>
#include "TreeNode_Class.h"
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

    TreeNode<int> *root = new TreeNode<int>(10);
    TreeNode<int> *node1 = new TreeNode<int>(20);
    TreeNode<int> *node2 = new TreeNode<int>(30);

    root->children.pb(node1);
    root->children.pb(node2);

    cout << root->children.size() << endl;
    cout << node1->children.size() << endl;
    cout << node2->children.size() << endl;

    return 0;
}