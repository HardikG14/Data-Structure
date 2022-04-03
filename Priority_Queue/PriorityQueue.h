#include <bits/stdc++.h>
using namespace std;

class PriorityQueue
{
private:
    vector<int> arr;

public:
    PriorityQueue()
    {
    }

    int getSize()
    {
        return arr.size();
    }

    bool isEmpty()
    {
        return arr.size() == 0;
    }

    int getMin()
    {
        if (isEmpty())
        {
            return 0;
        }
        return arr[0];
    }

    void insert(int data)
    {
        arr.push_back(data);

        int childIndex = arr.size() - 1;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;

            if (arr[childIndex] < arr[parentIndex])
            {
                swap(arr[childIndex], arr[parentIndex]);
            }
            else
            {
                return;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin()
    {
        // Write your code here
        if (isEmpty())
        {
            return -1;
        }

        int ans = arr[0];
        arr[0] = arr[arr.size() - 1];
        arr.pop_back();

        int parentIndex = 0;
        int childLeft = 2 * parentIndex + 1;
        int childRight = 2 * parentIndex + 2;
        while (childLeft < arr.size())
        {

            int minIndex = parentIndex;
            if (arr[minIndex] > arr[childLeft])
            {
                minIndex = childLeft;
            }

            if (childRight < arr.size() && arr[minIndex] > arr[childRight])
            {
                minIndex = childRight;
            }

            if (minIndex == parentIndex)
            {
                break;
            }

            swap(arr[parentIndex], arr[minIndex]);
            parentIndex = minIndex;
            childLeft = 2 * parentIndex + 1;
            childRight = 2 * parentIndex + 2;
        }
        return ans;
    }
};

class MaxPriorityQueue
{
private:
    vector<int> pq;

public:
    bool isEmpty()
    {
        return pq.size() == 0;
    }

    int getSize()
    {
        return pq.size();
    }

    int getMax()
    {
        if (isEmpty())
        {
            return -1;
        }
        return pq[0];
    }

    void insert(int data)
    {
        pq.push_back(data);

        int childIndex = pq.size() - 1;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[parentIndex] < pq[childIndex])
            {
                swap(pq[parentIndex], pq[childIndex]);
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }

    int removeMax()
    {
        if (isEmpty())
        {
            return -1;
        }

        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        int parentIndex = 0;
        int childLeft = 2 * parentIndex + 1;
        int childRight = 2 * parentIndex + 2;

        while (childLeft < pq.size())
        {
            int maxIndex = parentIndex;
            if (pq[childLeft] > pq[maxIndex])
            {
                maxIndex = childLeft;
            }

            if (childRight < pq.size() && pq[childRight] > pq[maxIndex])
            {
                maxIndex = childRight;
            }

            if (maxIndex == parentIndex)
            {
                break;
            }

            swap(pq[maxIndex], pq[parentIndex]);
            parentIndex = maxIndex;
            childLeft = 2 * parentIndex + 1;
            childRight = 2 * parentIndex + 2;
        }
        return ans;
    }
};