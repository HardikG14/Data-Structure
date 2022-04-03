#include <bits/stdc++.h>
#include "PriorityQueue.h"
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

void inplaceHeapSort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int childIndex = i;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (arr[childIndex] < arr[parentIndex])
            {
                swap(arr[childIndex], arr[parentIndex]);
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }

    int size = n;
    while (size > 1)
    {
        swap(arr[0], arr[size - 1]);
        size--;
        int parentIndex = 0;
        int childleft = 2 * parentIndex + 1;
        int childRight = 2 * parentIndex + 2;

        while (childleft < size)
        {
            int minIndex = parentIndex;
            if (arr[minIndex] > arr[childleft])
            {
                minIndex = childleft;
            }

            if (childRight < size && arr[minIndex] > arr[childRight])
            {
                minIndex = childRight;
            }

            if (minIndex == parentIndex)
            {
                break;
            }

            swap(arr[minIndex], arr[parentIndex]);
            parentIndex = minIndex;
            childleft = 2 * parentIndex + 1;
            childRight = 2 * parentIndex + 2;
        }
    }
}

class comp
{
public:
    bool cpm(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
    {
        return a.first > b.first;
    }
};

int buyTicket(int *arr, int n, int k)
{
    int time = 0;
    queue<int> que;
    priority_queue<int> pr;
    for (int i = 0; i < n; i++)
    {
        que.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        pr.push(arr[i]);
    }

    while (!que.empty())
    {
        if (pr.top() != arr[que.front()])
        {
            que.push(que.front());
            que.pop();
        }
        else
        {
            time++;
            if (que.front() == k)
            {
                return time;
            }
            pr.pop();
            que.pop();
        }
    }
}

// 6
// 6 2 1 3 7 5
void findMedian(int *arr, int n)
{
    // Write your code here
}
int main()
{
    // 5
    // 2 3 2 2 4
    // 3
    int a[] = {2, 3, 2, 2, 4};
    cout << buyTicket(a, 5, 3);
    // priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;

    // int n;
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     int x, y, z;
    //     cin >> x >> y >> z;
    //     pair<int, pair<int, int>> p;
    //     p.first = x;
    //     pair<int, int> np;
    //     np = {y, z};
    //     p.second = np;
    //     q.push(p);
    // }

    // while (!q.empty())
    // {
    //     pair<int, pair<int, int>> top = q.top();
    //     cout << top.first << " " << top.second.first << " " << top.second.second << endl;
    //     q.pop();
    // }
    // int a[] = {99, 32, 23, 4, 56, 7, 823, 22, 0};
    // inplaceHeapSort(a, 9);
    // for (int i = 0; i < 9; i++)
    // {
    //     cout << a[i] << " ";
    // }

    return 0;
}