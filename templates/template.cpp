#include <iostream>
using namespace std;

template <typename T, typename V>
class Pair
{
private:
    T x;
    V y;

public:
    void display()
    {
        cout << x << " " << y << endl;
    }

    void setX(T x)
    {
        this->x = x;
    }

    void setY(V y)
    {
        this->y = y;
    }

    T getX()
    {
        return x;
    }

    V getY()
    {
        return y;
    }
};