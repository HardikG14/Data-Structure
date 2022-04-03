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

//* 2^n-1 = 1,3,7,15,31,63;

void intToBinary(int n)
{
    for (int i = 30; i >= 0; i--)
    {
        // cout << ((1 << i) & n);
        int a = ((1 << i) & n);
        if (a != 0)
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
    }
    cout << "\n";
}

bool checkIfIthBitIsSet(int n, int i)
{
    if (((1 << i) & n) != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void setIthBit(int &n, int i)
{
    n = ((1 << i) | n);
}

void unsetIthBit(int &n, int i)
{
    n = ((1 << i) ^ n);
}

int noOfSetBits(int n)
{
    int count = 0;
    for (int i = 31; i >= 0; i--)
    {
        if (((1 << i) & n) != 0)
        {
            count++;
        }
    }
    return count;
}
int main()
{

    // intToBinary(123);
    // cout << ((1 << 1) & 123);
    int i = 13;
    intToBinary(i);
    // setIthBit(i, 2);
    cout << noOfSetBits(i);
    // unsetIthBit(i, 2);
    cout << __builtin_popcount(i);
    // intToBinary(~i);
    // intToBinary(i);
    // cout << checkIfIthBitIsSet(9, 3);
    return 0;
}