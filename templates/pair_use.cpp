#include <bits/stdc++.h>
#include "template.cpp"
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
    /*
    Pair<Pair<int, int>, double> p1;
    Pair<int, int> p2;
    p2.setX(100);
    p2.setY(200);
    p1.setX(p2);
    p1.setY(123.321);
    cout << p1.getX().getX() << " " << p1.getX().getY() << " " << p1.getY() << endl;
    // p1.display();
    */
    Pair<int, Pair<double, char>> p2;
    p2.setX(100);
    Pair<double, char> p1;
    p1.setX(100.2133);
    p1.setY('A');

    p2.setY(p1);
    cout << p2.getX() << " " << p2.getY().getX() << " " << p2.getY().getY() << endl;
}