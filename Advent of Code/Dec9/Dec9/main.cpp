#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>

using namespace std;

void AdjustTail(pair<int, int>& head, pair<int, int>& tail, set<pair<int, int>>& coveredSpaces, char direction)
{
    int xDifference = abs(head.first - tail.first);
    int yDifference = abs(head.second - tail.second);
    
    if((xDifference == 1 && yDifference == 2) || (xDifference == 2 && yDifference == 1))
    {
        if(head.first > tail.first)
        {
            tail.first++;
        }
        else
        {
            tail.first--;
        }
        
        if(head.second > tail.second)
        {
            tail.second++;
        }
        else
        {
            tail.second--;
        }
    }
    else if(xDifference > 1 || yDifference > 1)
    {
        switch (direction) {
            case 'U':
                tail.second++;
                break;
            case 'D':
                tail.second--;
                break;
            case 'R':
                tail.first++;
                break;
            case 'L':
                tail.first--;
                break;
        }
    }

    coveredSpaces.insert(tail);
}

void AdjustAdditionalTails(pair<int, int>& head, pair<int, int>& tail, char direction, vector<char>& lastD, int index)
{
    int xDifference = abs(head.first - tail.first);
    int yDifference = abs(head.second - tail.second);
    
    if((xDifference == 1 && yDifference == 2) || (xDifference == 2 && yDifference == 1))
    {
        if(head.first > tail.first)
        {
            tail.first++;
        }
        else
        {
            tail.first--;
        }
        
        if(head.second > tail.second)
        {
            tail.second++;
        }
        else
        {
            tail.second--;
        }
    }
    else if(xDifference > 1 || yDifference > 1)
    {
        lastD[index] = direction;
        switch (direction) {
            case 'U':
                tail.second++;
                break;
            case 'D':
                tail.second--;
                break;
            case 'R':
                tail.first++;
                break;
            case 'L':
                tail.first--;
                break;
        }
    }
}

void TailPositions()
{
    char direction;
    int spaces;
    set<pair<int, int>> coveredSpaces;
    pair head(0, 0);
    pair tail(0, 0);
    coveredSpaces.insert(tail);
    while(cin >> direction >> spaces)
    {
        for(int i = 0; i < spaces; i++)
        {
            switch (direction) {
                case 'U':
                    head.second++;
                    break;
                case 'D':
                    head.second--;
                    break;
                case 'R':
                    head.first++;
                    break;
                case 'L':
                    head.first--;
                    break;
            }
            
            AdjustTail(head, tail, coveredSpaces, direction);
        }
    }
    
    cout << coveredSpaces.size() << endl;
}

void TenTailPositions()
{
    char direction;
    int spaces;
    set<pair<int, int>> coveredSpaces;
    pair head(0, 0);
    pair t1(0, 0);
    pair t2(0, 0);
    pair t3(0, 0);
    pair t4(0, 0);
    pair t5(0, 0);
    pair t6(0, 0);
    pair t7(0, 0);
    pair t8(0, 0);
    pair tail(0, 0);
    vector<char> lastD(10);
    coveredSpaces.insert(tail);
    while(cin >> direction >> spaces)
    {
        for(int i = 0; i < spaces; i++)
        {
            switch (direction) {
                case 'U':
                    head.second++;
                    break;
                case 'D':
                    head.second--;
                    break;
                case 'R':
                    head.first++;
                    break;
                case 'L':
                    head.first--;
                    break;
            }
            lastD[0] = direction;
            AdjustAdditionalTails(head, t1, lastD[0], lastD, 1);
            AdjustAdditionalTails(t1, t2, lastD[1], lastD, 2);
            AdjustAdditionalTails(t2, t3, lastD[2], lastD, 3);
            AdjustAdditionalTails(t3, t4, lastD[3], lastD, 4);
            AdjustAdditionalTails(t4, t5, lastD[4], lastD, 5);
            AdjustAdditionalTails(t5, t6, lastD[5], lastD, 6);
            AdjustAdditionalTails(t6, t7, lastD[6], lastD, 7);
            AdjustAdditionalTails(t7, t8, lastD[7], lastD, 8);
            AdjustTail(t8, tail, coveredSpaces, lastD[8]);
        }
    }
    
    cout << coveredSpaces.size() << endl;
}

int main() {
    TenTailPositions();
    return 0;
}
