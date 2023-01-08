#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Signals()
{
    string action;
    int value;
    int X = 1;
    int timer = 0;
    int check = 20;
    int sum = 0;
    while(cin >> action)
    {
        if(action == "addx")
        {
            cin >> value;
            timer += 2;
            if(timer >= check && check <= 220)
            {
                sum += X * check;
                check += 40;
            }
            
            X += value;
        }
        else
        {
            timer += 1;
            if(timer >= check && check <= 220)
            {
                sum += X * check;
                check += 40;
            }
        }
    }
    
    cout << sum << endl;
}

bool CheckPosition(int pos, const vector<int>& sprite)
{
    for(int i = 0; i < sprite.size(); i++)
    {
        if(pos == sprite[i])
        {
            return true;
        }
    }
    
    return false;
}

void Capitals()
{
    string action;
    int value;
    int timer = -1;
    int check = 40;
    int position = 0;
    vector<int> sprite(3);
    for(int i = 0; i < 3; i++)
    {
        sprite[i] = i;
    }
    
    while(cin >> action)
    {
        if(action == "addx")
        {
            cin >> value;
            cout << (CheckPosition(position, sprite) ? '#' : ' ');
            timer++;
            position++;
            if(position == check)
            {
                cout << endl;
                timer = -1;
                position = 0;
            }
            
            cout << (CheckPosition(position, sprite) ? '#' : ' ');
            timer++;
            position++;
            if(position == check)
            {
                cout << endl;
                timer = -1;
                position = 0;
            }
            
            for(int i = 0; i < 3; i++)
            {
                sprite[i] += value;
            }
        }
        else
        {
            cout << (CheckPosition(position, sprite) ? '#' : ' ');
            timer++;
            position++;
            if(position == check)
            {
                cout << endl;
                timer = -1;
                position = 0;
            }
        }
    }
}

int main() {
    Capitals();
    return 0;
}
