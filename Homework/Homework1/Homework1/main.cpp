#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void Problem1()
{
    int listCount;
    cin >> listCount;
    
    vector<int> outputs;
    
    for(int i = 0; i < listCount; i++)
    {
        int listLength;
        cin >> listLength;
        string list;
        cin >> list;
        bool lastIsP;
        if(list[0] == 'P')
        {
            lastIsP = true;
        }
        else
        {
            lastIsP = false;
        }
        
        int countOfDeletes = 0;
        for(int i = 1; i < list.length(); i++)
        {
            if((lastIsP && list[i] == 'P')||(!lastIsP && list[i] == 'I'))
            {
                countOfDeletes++;
            }
            
            if(lastIsP && list[i] == 'I')
            {
                lastIsP = false;
            }
            else if(!lastIsP && list[i] == 'P')
            {
                lastIsP = true;
            }
        }
        
        outputs.push_back(countOfDeletes);
    }
    
    for(int i = 0; i < listCount; i++)
    {
        cout << outputs[i] << endl;
    }
}

void Problem2()
{
    int daysCount;
    cin >> daysCount;
    vector<int> coinsPrice;
    int coinPrice;
    for(int i = 0; i < daysCount; i++)
    {
        cin >> coinPrice;
        coinsPrice.push_back(coinPrice);
    }
    
    int profit = 0;
    int curresntSmallest;
    int currentBiggest;
    bool goingUp;
    bool notAllEqual = false;
    
    for(int i = 0; i < daysCount - 1; i++)
    {
        if(coinsPrice[i] < coinsPrice[i + 1])
        {
            curresntSmallest = coinsPrice[i];
            goingUp = true;
            notAllEqual = true;
            break;
        }
        
        if(coinsPrice[i] > coinsPrice[i + 1])
        {
            currentBiggest = coinsPrice[i];
            goingUp = false;
            notAllEqual = true;
            break;
        }
    }
    
    if(!notAllEqual)
    {
        cout << 0;
    }
    
    for(int i = 0; i < daysCount - 1; i++)
    {
        if(coinsPrice[i] > coinsPrice[i + 1] && goingUp)
        {
            currentBiggest = coinsPrice[i];
            profit += (currentBiggest - curresntSmallest);
            curresntSmallest = coinsPrice[i + 1];
            goingUp = false;
        }
        
        if(coinsPrice[i] < coinsPrice[i + 1] && !goingUp)
        {
            curresntSmallest = coinsPrice[i];
            currentBiggest = coinsPrice[i + 1];
            goingUp = true;
        }
        
        if(goingUp && i == daysCount - 2 && coinsPrice[i] < coinsPrice[i + 1])
        {
            currentBiggest = coinsPrice[i + 1];
            profit += (currentBiggest - curresntSmallest);
        }
    }
    
    cout << profit;
}

void Problem3()
{
    int ticketsCount;
    cin >> ticketsCount;
    
    vector<int> tickets;
    for(int i = 0; i < ticketsCount; i++)
    {
        int ticket;
        cin >> ticket;
        tickets.push_back(ticket);
    }
    
    sort(tickets.begin(), tickets.end());
    
    int result = 1;
    for(int i = 0; i < ticketsCount; i++)
    {
        if(tickets[i] == result)
        {
            result++;
        }
    }
    
    cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Problem3();
    return 0;
}
