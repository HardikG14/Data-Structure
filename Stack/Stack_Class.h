#include <iostream>
#include <climits>
using namespace std;

class StackUsingArray
{
private:
    int *data;
    int capacity;
    int nextIndex;

public:
    StackUsingArray()
    {
        capacity = 4;
        data = new int[4];
        nextIndex = 0;
    }

    // return the size of the Stack
    int size()
    {
        return nextIndex;
    }

    // returns if stack is empty or not
    bool is_empty()
    {
        return nextIndex == 0;
    }

    // insert element in the stack
    void push(int ele)
    {
        if (nextIndex == capacity)
        {
            // cout << "stack is full" << endl;
            // return;
            int *newData = new int[capacity * 2];
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            capacity *= 2;
            delete[] data;
            data = newData;
        }
        data[nextIndex] = ele;
        nextIndex++;
    }

    // delete element from the stack
    int pop()
    {
        if (nextIndex == 0)
        {
            cout << "stack is empty" << endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    // access element at the top of stack
    int top()
    {
        if (is_empty())
        {
            cout << "Stack is Empty" << endl;
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }
};

template <typename T>
class Stackusingtemplate
{
private:
    T *data;
    int capacity;
    int nextIndex;

public:
    Stackusingtemplate()
    {
        data = new T[4];
        capacity = 4;
        nextIndex = 0;
    }

    int size()
    {
        return nextIndex;
    }

    bool is_empty()
    {
        return nextIndex == 0;
    }

    T top()
    {
        if (nextIndex == 0)
        {
            cout << "Stack is empty" << endl;
            return 0;
        }
        return data[nextIndex - 1];
    }

    T pop()
    {
        if (nextIndex == 0)
        {
            cout << "Stack is Empty !!" << endl;
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }

    void push(T ele)
    {
        if (nextIndex == capacity)
        {
            T *newData = new T[capacity * 2];
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            delete data;
            data = newData;
            capacity *= 2;
        }
        data[nextIndex] = ele;
        nextIndex++;
    }
};

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

template <typename T>
class stackUsingLL
{
private:
    int len;
    Node<T> *head;

public:
    stackUsingLL()
    {
        head = nullptr;
        len = 0;
    }

    int size()
    {
        return len;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void push(T data)
    {
        Node<T> *newHead = new Node<T>(data);
        newHead->next = head;
        head = newHead;
        len++;
    }

    T top()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty!!" << endl;
            return 0;
        }
        return head->data;
    }

    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty!!" << endl;
            return 0;
        }
        T data = head->data;
        Node<T> *newHead = head->next;
        delete head;
        len--;
        head = newHead;
        return data;
    }
};