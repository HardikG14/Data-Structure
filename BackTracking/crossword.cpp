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

bool poss(char grid[4][4], string word, int &row, int &col)
{
    rep(i, 0, 4)
    {
        rep(j, 0, 4)
        {
            if (grid[i][j] == '-' || grid[i][j] == word[0])
            {
                i = row;
                j = col;
                return true;
            }
        }
    }
    return false;
}
void fillWord(char grid[4][4], string word, int i, int j)
{
    int row, col;
    if (!poss(grid, word, row, col))
    {
        return;
    }
    i = row;
    j = col;
}
int main()
{

    char grid[4][4];
    fillWord(grid, ok)

        return 0;
}