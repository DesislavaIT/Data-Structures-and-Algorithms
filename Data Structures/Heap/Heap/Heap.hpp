#ifndef Heap_hpp
#define Heap_hpp
#include <vector>
#include <iostream>

using namespace std;

class Heap
{
private:
    vector<int> data;

    int getLeft(int) const;
    int getRight(int) const;
    int getParent(int) const;
    void shiftUp(int);
    void shiftDown(int);
public:
    bool isEmpty() const;
    void add(int);
    int peekTop() const;
    void popTop();
};

#endif
