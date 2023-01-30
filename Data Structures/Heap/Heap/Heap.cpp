#include "Heap.hpp"

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int Heap::getLeft(int pos) const
{
    return (pos * 2) + 1;
}

int Heap::getRight(int pos) const
{
    return (pos * 2) + 2;
}

int Heap::getParent(int pos) const
{
    return (pos - 1) / 2;
}

void Heap::shiftUp(int pos)
{
    int parent = getParent(pos);
    while (data[pos] > data[parent])
    {
        swap(data[pos], data[parent]);
        if (parent <= 0)
        {
            return;
        }
        
        parent = getParent(parent);
        pos = getParent(pos);
    }
}

void Heap::shiftDown(int pos)
{
    bool hasRight = getRight(pos) < data.size();
    bool hasLeft = getLeft(pos) < data.size();

    if (hasRight && (data[pos] < data[getLeft(pos)] || data[pos] < data[getRight(pos)]))
    {
        int swapWith = -1;
        if (data[getLeft(pos)] < data[getRight(pos)])
        {
            swapWith = getRight(pos);
        }
        else
        {
            swapWith = getLeft(pos);
        }
        
        swap(data[pos], data[swapWith]);
        shiftDown(swapWith);
    }
    else if (hasLeft && data[pos] < data[getLeft(pos)])
    {
        swap(data[pos], data[getLeft(pos)]);
        shiftDown(getLeft(pos));
    }
}

bool Heap::isEmpty() const
{
    return data.size() == 0;
}

void Heap::add(int number)
{
    data.push_back(number);
    if (data.size() != 0)
    {
        shiftUp(data.size() - 1);
    }
}

int Heap::peekTop() const
{
    return data[0];
}

void Heap::popTop()
{
    if (isEmpty())
    {
        return;
    }

    swap(data[0], data[data.size() - 1]);
    data.pop_back();
    shiftDown(0);
}

int main()
{
    Heap s;
    s.add(1);
    s.add(5);
    s.add(3);
    s.add(4);
    s.add(2);

    while(!s.isEmpty())
    {
        cout << s.peekTop() << " ";
        s.popTop();
    }
    
    cout << "\n";
}
