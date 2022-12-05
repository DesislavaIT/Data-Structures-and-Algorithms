#include <iostream>
#include <string>
#include <queue>
#include <set>

using namespace std;

void Rucksacks()
{
    priority_queue<long long> pq;
    string str = " ";
    while(getline(cin, str))
    {
        set<char> s;
        for(int i = 0; i < str.length() / 2; i++)
        {
            s.insert(str[i]);
        }
        
        for(int i = str.length() / 2; i < str.length(); i++)
        {
            if(s.find(str[i]) != s.end())
            {
                if(str[i] >= 'a' && str[i] <= 'z')
                    pq.push(str[i] - 97 + 1);
                else
                    pq.push(str[i] - 65 + 27);
                
                break;
            }
        }
    }
    
    int sum = 0;
    while(pq.size() > 0)
    {
        sum += pq.top();
        pq.pop();
    }
    
    cout << sum << endl;
}

void Badges()
{
    priority_queue<long long> pq;
    string str = " ";
    while(getline(cin, str))
    {
        string str2 = " ";
        getline(cin, str2);
        string str3 = " ";
        getline(cin, str3);
        set<char> s;
        for(int i = 0; i < str.length(); i++)
        {
            s.insert(str[i]);
        }
        
        set<int> s2;
        for(int i = 0; i < str2.length(); i++)
        {
            if(s.find(str2[i]) != s.end())
                s2.insert(str2[i]);
        }
        
        for(int i = 0; i < str3.length(); i++)
        {
            if(s2.find(str3[i]) != s2.end())
            {
                if(str3[i] >= 'a' && str3[i] <= 'z')
                    pq.push(str3[i] - 97 + 1);
                else
                    pq.push(str3[i] - 65 + 27);
                
                break;
            }
        }
    }
    
    int sum = 0;
    while(pq.size() > 0)
    {
        sum += pq.top();
        pq.pop();
    }
    
    cout << sum << endl;
}

int main() {
    Badges();
    return 0;
}
