#include <iostream>
#include <string>
#include <queue>
#include <set>

using namespace std;

void DetectFirstPacket()
{
    string input;
    getline(cin, input);
    queue<char> q;
    multiset<char> s;
    for(int i = 0; i < input.length(); i++)
    {
        q.push(input[i]);
        s.insert(input[i]);
        if(q.size() == 4)
        {
            queue<char> temp;
            set<char> checker;
            for(int i = 0; i < 4; i++)
            {
                checker.insert(q.front());
                temp.push(q.front());
                q.pop();
            }
            
            if(checker.size() == 4)
            {
                cout << i + 1 << endl;
                break;
            }
            
            temp.pop();
            for(int i = 0; i < 3; i++)
            {
                q.push(temp.front());
                temp.pop();
            }
        }
    }
}

void DetectFirstMessage()
{
    string input;
    getline(cin, input);
    queue<char> q;
    multiset<char> s;
    for(int i = 0; i < input.length(); i++)
    {
        q.push(input[i]);
        s.insert(input[i]);
        if(q.size() == 14)
        {
            queue<char> temp;
            set<char> checker;
            for(int i = 0; i < 14; i++)
            {
                checker.insert(q.front());
                temp.push(q.front());
                q.pop();
            }
            
            if(checker.size() == 14)
            {
                cout << i + 1 << endl;
                break;
            }
            
            temp.pop();
            for(int i = 0; i < 13; i++)
            {
                q.push(temp.front());
                temp.pop();
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    DetectFirstMessage();
    return 0;
}
