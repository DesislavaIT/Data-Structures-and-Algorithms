#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std;

struct Query
{
    int index;
    int waiting;
    Query(int w, int i)
    {
        waiting = w;
        index = i;
    }
};

bool operator<(const Query& q1, const Query& q2)
{
    return q1.waiting > q2.waiting;
}

void Queries()
{
    int N;
    cin >> N;
    int min = INT_MAX;
    int max = INT_MIN;
    int time = 0;
    priority_queue<Query> pq;
    for(int i = 0; i < N; i++)
    {
        int number;
        while(i < time && i < N)
        {
            cin >> number;
            Query q(number, i);
            pq.push(q);
            i++;
        }
        
        if(i != N)
        {
            cin >> number;
            Query q(number, i);
            pq.push(q);
        }
        
        int allWaiting = time - pq.top().index + pq.top().waiting;
        if(allWaiting > max)
        {
            max = allWaiting;
        }

        if(allWaiting < min)
        {
            min = allWaiting;
        }
        
        time += pq.top().waiting;
        pq.pop();
    }
    
    while(pq.size() > 0)
    {
        int allWaiting = time - pq.top().index + pq.top().waiting;
        if(allWaiting > max)
        {
            max = allWaiting;
        }

        if(allWaiting < min)
        {
            min = allWaiting;
        }
        time += pq.top().waiting;
        pq.pop();
    }
    
    cout << min << ' ' << max;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Queries();
    return 0;
}
