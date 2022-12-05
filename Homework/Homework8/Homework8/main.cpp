#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <set>

using namespace std;

struct Banitsa
{
    int start;
    int duration;
    int index;
    Banitsa()
    {
        start = duration = 0;
    }
    
    Banitsa(int s, int d, int i)
    {
        start = s;
        duration = d;
        index = i;
    }
};

bool operator<(const Banitsa& b1, const Banitsa& b2)
{
    if(b1.start == b2.start)
        return b1.duration > b2.duration;
    return b1.start > b2.start;
}

struct Banitsa2
{
    int start;
    int duration;
    int index;
    Banitsa2()
    {
        start = duration = 0;
    }
    
    Banitsa2(int s, int d, int i)
    {
        start = s;
        duration = d;
        index = i;
    }
};

bool operator<(const Banitsa2& b1, const Banitsa2& b2)
{
    if(b1.duration == b2.duration)
        return b1.index > b2.index;
    return b1.duration > b2.duration;
}

void Problem1()
{
    int N;
    cin >> N;
    
    priority_queue<Banitsa> pq;
    for(int i = 0; i < N; i++)
    {
        int s;
        cin >> s;
        int d;
        cin >> d;
        Banitsa b(s, d, i);
        pq.push(b);
    }
    
    vector<int> answer;
    Banitsa current = pq.top();
    answer.push_back(current.index);
    pq.pop();
    int time = current.start + current.duration;
    priority_queue<Banitsa2> pq2;
    while(pq2.size() > 0 || pq.size() > 0)
    {
        while(time < pq.top().start && pq2.size() == 0)
        {
            time++;
        }
        
        while(pq.top().start <= time && pq.size() > 0)
        {
            Banitsa b = pq.top();
            Banitsa2 b2(b.start, b.duration, b.index);
            pq2.push(b2);
            pq.pop();
        }
        
        current.start= pq2.top().start;
        current.duration= pq2.top().duration;
        current.index= pq2.top().index;
        answer.push_back(current.index);
        pq2.pop();
        time += current.duration;
    }
    
    for(int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }
}

void Problem2()
{
    cout << fixed << setprecision(1);
    int N;
    cin >> N;
    
    multiset<int, less<int>> s;
    multiset<int, less<int>>::iterator itr;
    double mid = 0;
    for(int i = 0; i < N; i++)
    {
        int number;
        cin >> number;
        
        if(number >= 0)
        {
            s.insert(number);
            
            if(s.size() == 1)
            {
                itr = s.find(number);
                mid = *itr;
                cout << 1.0 * mid << '\n';
                continue;
            }
            
            if(s.size() % 2 == 1) //odd
            {
                if(number >= *itr)
                {
                    itr++;
                }
                
                mid = (*itr);
                cout << 1.0 * mid << '\n';
            }
            else //even
            {
                if(number < *itr)
                {
                    itr--;
                }
                
                int left = *(itr++);
                int right = *itr;
                itr--;
                mid = 1.0 * (left + right) / 2;
                cout << mid << '\n';
            }
        }
    }
}

void Problem3()
{
    int K, T, B;
    cin >> K >> T >> B;
    int N;
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> answer;
    for(int i = 1; i <= N; i++)
    {
        int number;
        cin >> number;
        pq.push(number);
        
        if(i % T == 0)
        {
            int counter = 0;
            while(counter++ < K && pq.size() > 0)
            {
                answer.push_back(pq.top());
                pq.pop();
            }
        }
    }
    
    while(answer.size() < K * B)
    {
        answer.push_back(pq.top());
        pq.pop();
    }
    
    for(int i = 0; i < K * B; i++)
    {
        cout << answer[i] << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Problem3();
    return 0;
}
