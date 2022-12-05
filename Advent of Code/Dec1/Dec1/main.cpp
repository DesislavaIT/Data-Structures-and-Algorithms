#include <iostream>
#include <string>
#include <queue>
#include <set>

using namespace std;

void MostCalories()
{
    priority_queue<int> pq;
    string str;
    int cals = 0;
    while (getline(cin, str))
    {
        if (str == "")
        {
            pq.push(cals);
            cals = 0;
            continue;
        }
        else
        {
            cals += stoi(str);
        }
    }
    
    pq.push(cals);
    cout << pq.top() << endl;
}

void TopThreeSum()
{
    priority_queue<int> pq;
    string str;
    int cals = 0;
    while (getline(cin, str))
    {
        if (str == "")
        {
            pq.push(cals);
            cals = 0;
            continue;
        }
        else
        {
            cals += stoi(str);
        }
    }
    
    pq.push(cals);
    
    int sum = 0;
    for(int i = 0; i < 3; i++)
    {
        sum += pq.top();
        pq.pop();
    }
    
    cout << sum << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    TopThreeSum();
    return 0;
}
