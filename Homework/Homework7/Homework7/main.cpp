#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;

void CheckMask(int mask, set<unsigned int>& s, int current)
{
    if(current > mask)
    {
        return;
    }
    
    if((current & mask) == current)
    {
        s.insert(current);
    }
}

void AddSubMasks(int mask, set<unsigned int>& s)
{
    for(int i = 0; i <= mask; i++)
    {
        CheckMask(mask, s, i);
    }
}

void Problem1()
{
    int N;
    cin >> N;
    vector<int> masks(N);
    for(int i = 0; i < N; i++)
    {
        cin >> masks[i];
    }
    
    set<unsigned int> s;
    for(int i = 0; i < N; i++)
    {
        AddSubMasks(masks[i], s);
    }
    
    cout << s.size() << ' ';
}

void Problem2()
{
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++)
    {
        int N;
        cin >> N;
        vector<int> sweets(N);
        for(int j = 0; j < N; j++)
        {
            cin >> sweets[j];
        }
        
        int maxCount = 0;
        map<int, int> m;
        int startIndex = 0;
        
        for(int j = 0; j < N; j++)
        {
            if(m.find(sweets[j]) == m.end())
            {
                m.insert(pair<int, int>(sweets[j], j));
            }
            else
            {
                if(m[sweets[j]] < startIndex)
                {
                    m[sweets[j]] = j;
                    continue;
                }
                
                if(j - startIndex > maxCount)
                {
                    maxCount = j - startIndex;
                }
                
                if(m[sweets[j]] == startIndex)
                {
                    startIndex++;
                }
                else
                {
                    startIndex = m[sweets[j]] + 1;
                }
                
                m[sweets[j]] = j;
            }
        }
        
        if(N - startIndex > maxCount)
        {
            maxCount = N - startIndex;
        }
        
        cout << maxCount << '\n';
    }
}

int ShipsInInterval(int start, int end, int shipLength)
{
    int places = end - start;
    int ships = places / (shipLength + 1);
    
    return ships;
}

void Problem3()
{
    int N;
    cin >> N;
    int K;
    cin >> K;
    int A;
    cin >> A;
    int Q;
    cin >> Q;
    
    int maxShips = ShipsInInterval(1, N + 2, A);
    
    int pos;
    set<int> s;
    s.insert(0);
    s.insert(N + 1);
    for(int i = 0; i < Q; i++)
    {
        cin >> pos;
        s.insert(pos);
        auto rightR = s.find(pos);
        rightR++;
        int right = *rightR;
        
        auto leftR = s.find(pos);
        leftR--;
        int left = *leftR;
        
       if(ShipsInInterval(left, pos, A) + ShipsInInterval(pos, right, A) < ShipsInInterval(left, right, A))
        {
            maxShips--;
        }
        
        if(maxShips < K)
        {
            cout << i + 1;
            return;
        }
    }
    
    cout << -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Problem3();
    return 0;
}
