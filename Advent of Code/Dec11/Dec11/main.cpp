#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

struct Monkey
{
    list<unsigned long> startingItems;
    char operationSign;
    string operationNum;
    int test;
    int ifT;
    int ifF;
};

void MostActiveMonkeys()
{
    vector<Monkey> monkeys(8);
    monkeys[0].startingItems = {54, 98, 50, 94, 69, 62, 53, 85};
    monkeys[1].startingItems = {71, 55, 82};
    monkeys[2].startingItems = {77, 73, 86, 72, 87};
    monkeys[3].startingItems = {97, 91};
    monkeys[4].startingItems = {78, 97, 51, 85, 66, 63, 62};
    monkeys[5].startingItems = {88};
    monkeys[6].startingItems = {87, 57, 63, 86, 87, 53};
    monkeys[7].startingItems = {73, 59, 82, 65};
    
    for(int i = 0; i < 8; i++)
    {
        string firstRow;
        getline(cin, firstRow);
        string secondRow;
        getline(cin, secondRow);
        char freeSpace;
        cin >> freeSpace >> freeSpace;
        string someWords;
        cin >> someWords >> someWords >> someWords >> someWords;
        cin >> monkeys[i].operationSign >> monkeys[i].operationNum;
        cin >> freeSpace >> freeSpace;
        cin >> someWords >> someWords >> someWords >> monkeys[i].test;
        cin >> freeSpace >> freeSpace >> freeSpace >> freeSpace;
        cin >> someWords >> someWords >> someWords >> someWords >> monkeys[i].ifT;
        cin >> freeSpace >> freeSpace >> freeSpace >> freeSpace;
        cin >> someWords >> someWords >> someWords >> someWords >> monkeys[i].ifF;
        if(i == 7)
        {
            break;
        }
        
        cin.ignore();
        getline(cin, someWords);
    }
    
    vector<unsigned long> inspectations(8);
    for(int j = 0; j < 20; j++)
    {
        for(int i = 0; i < 8; i++)
        {
            inspectations[i] += monkeys[i].startingItems.size();
            unsigned long fixedSize =  monkeys[i].startingItems.size();
            for(int k = 0; k < fixedSize; k++)
            {
                long long m = monkeys[i].startingItems.front();
                monkeys[i].startingItems.pop_front();
                if(monkeys[i].operationSign == '*')
                {
                    m *= (monkeys[i].operationNum == "old" ? m : stoll(monkeys[i].operationNum));
                }
                else
                {
                    m += (monkeys[i].operationNum == "old" ? m : stoll(monkeys[i].operationNum));
                }
                
                m /= 3;
                if(m % monkeys[i].test == 0)
                {
                    monkeys[monkeys[i].ifT].startingItems.push_back(m);
                }
                else
                {
                    monkeys[monkeys[i].ifF].startingItems.push_back(m);
                }
            }
        }
    }
    
    sort(inspectations.begin(), inspectations.end());
    cout << inspectations[7] * inspectations[6] << endl;
}

void MostActiveMonkeysWithoutWoriesRelief()
{
    vector<Monkey> monkeys(8);
    monkeys[0].startingItems = {54, 98, 50, 94, 69, 62, 53, 85};
    monkeys[1].startingItems = {71, 55, 82};
    monkeys[2].startingItems = {77, 73, 86, 72, 87};
    monkeys[3].startingItems = {97, 91};
    monkeys[4].startingItems = {78, 97, 51, 85, 66, 63, 62};
    monkeys[5].startingItems = {88};
    monkeys[6].startingItems = {87, 57, 63, 86, 87, 53};
    monkeys[7].startingItems = {73, 59, 82, 65};
    
    for(int i = 0; i < 8; i++)
    {
        string firstRow;
        getline(cin, firstRow);
        string secondRow;
        getline(cin, secondRow);
        char freeSpace;
        cin >> freeSpace >> freeSpace;
        string someWords;
        cin >> someWords >> someWords >> someWords >> someWords;
        cin >> monkeys[i].operationSign >> monkeys[i].operationNum;
        cin >> freeSpace >> freeSpace;
        cin >> someWords >> someWords >> someWords >> monkeys[i].test;
        cin >> freeSpace >> freeSpace >> freeSpace >> freeSpace;
        cin >> someWords >> someWords >> someWords >> someWords >> monkeys[i].ifT;
        cin >> freeSpace >> freeSpace >> freeSpace >> freeSpace;
        cin >> someWords >> someWords >> someWords >> someWords >> monkeys[i].ifF;
        if(i == 7)
        {
            break;
        }
        
        cin.ignore();
        getline(cin, someWords);
    }
    
    vector<unsigned long> inspectations(8);
    for(int j = 0; j < 10000; j++)
    {
        for(int i = 0; i < 8; i++)
        {
            inspectations[i] += monkeys[i].startingItems.size();
            unsigned long fixedSize =  monkeys[i].startingItems.size();
            for(int k = 0; k < fixedSize; k++)
            {
                unsigned long m = monkeys[i].startingItems.front();
                monkeys[i].startingItems.pop_front();
                if(monkeys[i].operationSign == '*')
                {
                    m *= (monkeys[i].operationNum == "old" ? m : stoll(monkeys[i].operationNum));
                }
                else
                {
                    m += (monkeys[i].operationNum == "old" ? m : stoll(monkeys[i].operationNum));
                }
                
                if(m % monkeys[i].test == 0)
                {
                    monkeys[monkeys[i].ifT].startingItems.push_back(m);
                }
                else
                {
                    monkeys[monkeys[i].ifF].startingItems.push_back(m);
                }
            }
        }
    }
    
    sort(inspectations.begin(), inspectations.end());
    cout << inspectations[7] * inspectations[6] << endl;
}

int main() {
    MostActiveMonkeysWithoutWoriesRelief();
    return 0;
}
