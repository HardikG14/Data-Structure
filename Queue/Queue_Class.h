#include <iostream>
using namespace std;

template <typename T>
class QueueUsingArr
{
    T *data;
    int len;
    int capacity;
    int firstIndex;
    int nextIndex;

public:
    QueueUsingArr(int s)
    {
        data = new T[s];
        capacity = s;
        firstIndex = -1;
        nextIndex = 0;
        len = 0;
    }

    QueueUsingArr()
    {
        data = new T[4];
        capacity = 4;
        firstIndex = -1;
        nextIndex = 0;
        len = 0;
    }

    int size()
    {
        return len;
    }

    bool is_empty()
    {
        return len == 0;
    }

    void enqueue(T element)
    {
        if (len == capacity)
        {
            T *newData = new T[capacity * 2];
            int j = 0;
            for (int i = firstIndex; i < capacity; i++)
            {
                newData[j] = data[i];
                j++;
            }

            for (int i = 0; i < firstIndex; i++)
            {
                newData[j] = data[i];
                j++;
            }
            delete[] data;
            data = newData;
            firstIndex = 0;
            nextIndex = capacity;
            capacity *= 2;
        }
        if (firstIndex == -1)
        {
            firstIndex = 0;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        len++;
    }

    T front()
    {
        if (is_empty())
        {
            cout << "Queue is Empty !" << endl;
            return 0;
        }
        return data[firstIndex];
    }

    T dequeue()
    {
        if (is_empty())
        {
            cout << "Queue is Empty !" << endl;
            return 0;
        }
        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        len--;
        if (len == 0)
        {
            firstIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }
};

template <typename T>
class Node
{
public:
    Node<T> *next;
    T data;

    Node(T data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

template <typename T>
class QueueUsingLL
{
private:
    Node<T> *head;
    Node<T> *tail;
    int len;

public:
    QueueUsingLL()
    {
        head = nullptr;
        tail = nullptr;
        len = 0;
    }

    bool is_empty()
    {
        return head == nullptr;
    }

    int size()
    {
        return len;
    }

    void enqueue(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        len++;
    }

    void dequeue()
    {
        if (is_empty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        Node<T> *temp = head->next;
        delete head;
        len--;
        head = temp;
    }

    T front()
    {
        if (is_empty())
        {
            cout << "Queue is Empty !!" << endl;
            return 0;
        }
        return head->data;
    }
};