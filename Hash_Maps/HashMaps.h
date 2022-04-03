#include <bits/stdc++.h>
using namespace std;

template <typename V>
class Node
{
public:
    string key;
    V value;
    Node<V> *next;

    Node(string key, V value)
    {
        this->key = key;
        this->value = value;
        this->next = nullptr;
    }

    ~Node()
    {
        delete next;
    }
};

template <typename V>
class HashMaps
{
private:
    Node<V> **buckets;
    int count;
    int numBuckets;

public:
    HashMaps()
    {
        count = 0;
        numBuckets = 20;
        buckets = new Node<V> *[numBuckets];
        for (int i = 0; i < numBuckets; i++)
        {
            buckets[i] = nullptr;
        }
    }

    ~HashMaps()
    {
        for (int i = 0; i < numBuckets; i++)
        {
            delete buckets[i];
        }
        delete[] buckets;
    }

    int getSize()
    {
        return count;
    }

private:
    int getBucketIndex(string key)
    {
        int hashCode = 0;
        int curr = 1;
        for (int i = key.size() - 1; i >= 0; i--)
        {
            hashCode += key[i] * curr;
            hashCode = hashCode % numBuckets;
            curr *= 37;
            curr = curr % numBuckets;
        }
        return hashCode % numBuckets;
    }

public:
    void insert(string key, V val)
    {
        int bucketIndex = getBucketIndex(key);
        Node<V> *head = buckets[bucketIndex];
        while (head != nullptr)
        {
            if (head->key == key)
            {
                head->value = val;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketIndex];
        Node<V> *newNode = new Node<V>(key, val);
        newNode->next = head;
        buckets[bucketIndex] = newNode;
        count++;
    }

    V getValue(string key)
    {
        int bucketIndex = getBucketIndex(key);
        Node<V> *head = buckets[bucketIndex];
        while (head != nullptr)
        {
            if (head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }

    V remove(string key)
    {
        int bucketIndex = getBucketIndex(key);
        Node<V> *head = buckets[bucketIndex];
        Node<V> *prev = nullptr;
        while (head != nullptr)
        {
            if (head->key == key)
            {
                if (prev = nullptr)
                {
                    buckets[bucketIndex] = head->next;
                }
                else
                {
                    prev->next = head->next;
                }
                V ans = head->value;
                head->next = nullptr;
                delete head;
                count--;
                return ans;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }
};
