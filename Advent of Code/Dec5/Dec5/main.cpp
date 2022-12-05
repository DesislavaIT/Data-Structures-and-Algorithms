#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector<stack<char>> stacks(9);

void FillStack()
{
    stacks[0].push('R');
    stacks[0].push('S');
    stacks[0].push('L');
    stacks[0].push('F');
    stacks[0].push('Q');

    stacks[1].push('N');
    stacks[1].push('Z');
    stacks[1].push('Q');
    stacks[1].push('G');
    stacks[1].push('P');
    stacks[1].push('T');

    stacks[2].push('S');
    stacks[2].push('M');
    stacks[2].push('Q');
    stacks[2].push('B');

    stacks[3].push('T');
    stacks[3].push('G');
    stacks[3].push('Z');
    stacks[3].push('J');
    stacks[3].push('H');
    stacks[3].push('C');
    stacks[3].push('B');
    stacks[3].push('Q');

    stacks[4].push('P');
    stacks[4].push('H');
    stacks[4].push('M');
    stacks[4].push('B');
    stacks[4].push('N');
    stacks[4].push('F');
    stacks[4].push('S');

    stacks[5].push('P');
    stacks[5].push('C');
    stacks[5].push('Q');
    stacks[5].push('N');
    stacks[5].push('S');
    stacks[5].push('L');
    stacks[5].push('V');
    stacks[5].push('G');

    stacks[6].push('W');
    stacks[6].push('C');
    stacks[6].push('F');

    stacks[7].push('Q');
    stacks[7].push('H');
    stacks[7].push('G');
    stacks[7].push('Z');
    stacks[7].push('W');
    stacks[7].push('V');
    stacks[7].push('P');
    stacks[7].push('M');

    stacks[8].push('G');
    stacks[8].push('Z');
    stacks[8].push('D');
    stacks[8].push('L');
    stacks[8].push('C');
    stacks[8].push('N');
    stacks[8].push('R');
}

void RearrangeStacks()
{
    string moveFromTo;
    int from, to, count;
    while(cin >> moveFromTo >> count >> moveFromTo >> from >> moveFromTo >> to)
    {
        from--;
        to--;
        for(int i = 0; i < count; i++)
        {
            char stock = stacks[from].top();
            stacks[from].pop();
            stacks[to].push(stock);
        }
    }
}

void RearrangeStacksVolume2()
{
    string moveFromTo;
    int from, to, count;
    while(cin >> moveFromTo >> count >> moveFromTo >> from >> moveFromTo >> to)
    {
        from--;
        to--;
        stack<char> temp;
        for(int i = 0; i < count; i++)
        {
            char stock = stacks[from].top();
            stacks[from].pop();
            temp.push(stock);
        }
        
        for(int i = 0; i < count; i++)
        {
            char stock = temp.top();
            temp.pop();
            stacks[to].push(stock);
        }
    }
}

void PrintTopStacks()
{
    for(int i = 0; i < stacks.size(); i++)
    {
        cout << stacks[i].top();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    FillStack();
    RearrangeStacksVolume2();
    PrintTopStacks();
    return 0;
}
