#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <queue>
#include <deque>

using namespace std;

void RotApple(vector<vector<int>>& apples, queue<pair<int, int>>& q, int N, int M)
{
    int size = q.size();
    for(int i = 0; i < size; i++)
    {
        pair<int, int> p = q.front();
        q.pop();
        if(p.first > 0)
        {
            if(apples[p.first - 1][p.second] != 0)
            {
                apples[p.first - 1][p.second] = 0;
                pair<int, int> newPair(p.first - 1, p.second);
                q.push(newPair);
            }
        }
        if(p.first < N - 1)
        {
            if(apples[p.first + 1][p.second] != 0)
            {
                apples[p.first + 1][p.second] = 0;
                pair<int, int> newPair(p.first + 1, p.second);
                q.push(newPair);
            }
        }
        if(p.second > 0)
        {
            if(apples[p.first][p.second - 1] != 0)
            {
                apples[p.first][p.second - 1] = 0;
                pair<int, int> newPair(p.first, p.second - 1);
                q.push(newPair);
            }
        }
        if(p.second < M - 1)
        {
            if(apples[p.first][p.second + 1] != 0)
            {
                apples[p.first][p.second + 1] = 0;
                pair<int, int> newPair(p.first, p.second + 1);
                q.push(newPair);
            }
        }
    }
}

void Problem1()
{
    int N, M, T;
    cin >> N >> M >> T;
    vector<vector<int>> apples(N);
    int goodApples = N * M;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            apples[i].push_back(1);
        }
    }
    
    int x, y;
    queue<pair<int, int>> q;
    while(cin >> x >> y)
    {
        x--;
        y--;
        apples[x][y] = 0;
        pair<int, int> newPair(x, y);
        q.push(newPair);
        goodApples--;
    }
    
    for(int i = 0; i < T; i++)
    {
        RotApple(apples, q, N, M);
        goodApples -= q.size();
    }
    
    cout << goodApples;
}

void Problem2()
{
    int N, K;
    cin >> N >> K;
    vector<int> people(N);
    for(int i = 0; i < N; i++)
    {
        cin >> people[i];
    }
    
    queue<int> q;
    deque<int> d;
    
    int counter = 0;
    for(; counter < K; counter++)
    {
        q.push(people[counter]);
        if(d.size() > 0)
        {
            while(d.back() >= people[counter])
            {
                d.pop_back();
                if(d.size() <= 0)
                {
                    break;
                }
            }
        }
        
        d.push_back(people[counter]);
    }
    
    int sum = 0;
    for(; counter < N; counter++)
    {
        sum += d.front();
        if(q.front() == d.front())
        {
            d.pop_front();
        }
        
        q.pop();
        
        q.push(people[counter]);
        while(d.back() >= people[counter])
        {
            d.pop_back();
            if(d.size() <= 0)
            {
                break;
            }
        }
        
        d.push_back(people[counter]);
    }
    
    sum += d.front();
    cout << sum;
}

void Fight(list<int>& BS, list<int>& SB)
{
    if(BS.back() > -1 * SB.front())
    {
        SB.pop_front();
    }
    else if(BS.back() < -1 * SB.front())
    {
        BS.pop_back();
    }
    else
    {
        SB.pop_front();
        BS.pop_back();
    }
}

void Problem3()
{
    int N;
    cin >> N;
    list<int> BS;
    list<int> SB;
    vector<int> people;
    for(int i = 0; i < N; i++)
    {
        int number;
        cin >> number;
        people.push_back(number);
    }
    
    vector<int> answer;
    bool negativeGo = true;
    for(int i = 0; i < N; i++)
    {
        if(people[i] > 0)
        {
            BS.push_back(people[i]);
            negativeGo = false;
        }
        else
        {
            SB.push_back(people[i]);
            if(negativeGo)
            {
                while(SB.size() > 0)
                {
                    int a = SB.front();
                    SB.pop_front();
                    answer.push_back(a);
                }
                
                continue;
            }
        }
        
        while(BS.size() > 0 && SB.size() > 0)
        {
            Fight(BS, SB);
        }
        
        if(SB.size() > 0)
        {
            while(SB.size() > 0)
            {
                int a = SB.front();
                SB.pop_front();
                answer.push_back(a);
            }
        }
    }
    
    while(BS.size() > 0)
    {
        int a = BS.front();
        BS.pop_front();
        answer.push_back(a);
    }
    
    for(int i = 0 ; i < answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }
    
    if(answer.size() == 0)
    {
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Problem3();
    return 0;
}
