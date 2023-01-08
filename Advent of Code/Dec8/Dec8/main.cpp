#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool CheckLeft(string& str, int index)
{
    for(int i = index - 1; i >= 0; i--)
    {
        if(str[index] <= str[i])
        {
            return false;
        }
    }
    
    return true;
}

bool CheckRight(string& str, int index)
{
    for(int i = index + 1; i < str.length(); i++)
    {
        if(str[index] <= str[i])
        {
            return false;
        }
    }
    
    return true;
}

bool CheckUp(vector<string>& input, int rowIndex, int index)
{
    for(int i = rowIndex - 1; i >= 0; i--)
    {
        if(input[rowIndex][index] <= input[i][index])
        {
            return false;
        }
    }
    
    return true;
}

bool CheckDown(vector<string>& input, int rowIndex, int index)
{
    for(int i = rowIndex + 1; i < input.size(); i++)
    {
        if(input[rowIndex][index] <= input[i][index])
        {
            return false;
        }
    }
    
    return true;
}

void VisibleTrees()
{
    vector<string> input;
    string str = "";
    while(getline(cin, str))
    {
        input.push_back(str);
    }
    
    int outer = input.size() * 2 + 2 * (input[0].length() - 2);
    int inner = 0;
    for(int i = 1; i < input.size() - 1; i++)
    {
        for(int j = 1; j < input[i].length() - 1; j++)
        {
            if(CheckLeft(input[i], j))
            {
                inner++;
                continue;
            }
            
            if(CheckRight(input[i], j))
            {
                inner++;
                continue;
            }
            
            if(CheckUp(input, i, j))
            {
                inner++;
                continue;
            }
            
            if(CheckDown(input, i, j))
            {
                inner++;
                continue;
            }
        }
    }
    
    cout << inner + outer << endl;
}

int CheckLeft2(string& str, int index)
{
    for(int i = index - 1; i >= 0; i--)
    {
        if(str[index] <= str[i])
        {
            return index - i;
        }
    }
    
    return index;
}

int CheckRight2(string& str, int index)
{
    for(int i = index + 1; i < str.length(); i++)
    {
        if(str[index] <= str[i])
        {
            return i - index;
        }
    }
    
    return str.length() - index - 1;
}

int CheckUp2(vector<string>& input, int rowIndex, int index)
{
    for(int i = rowIndex - 1; i >= 0; i--)
    {
        if(input[rowIndex][index] <= input[i][index])
        {
            return rowIndex - i;
        }
    }
    
    return rowIndex;
}

int CheckDown2(vector<string>& input, int rowIndex, int index)
{
    for(int i = rowIndex + 1; i < input.size(); i++)
    {
        if(input[rowIndex][index] <= input[i][index])
        {
            return i - rowIndex;
        }
    }
    
    return input[rowIndex].length() - rowIndex - 1;
}

void HighestScenicScorePossible()
{
    vector<string> input;
    string str = "";
    while(getline(cin, str))
    {
        input.push_back(str);
    }
    
    int max = 0;
    for(int i = 0; i < input.size(); i++)
    {
        for(int j = 0; j < input[i].length(); j++)
        {
            int curr = CheckLeft2(input[i], j) + CheckRight2(input[i], j) + CheckUp2(input, i, j) + CheckDown2(input, i, j);
            if(curr > max)
            {
                max = curr;
            }
        }
    }
    
    cout << max << endl;
}

int main() {
//    VisibleTrees();
    HighestScenicScorePossible();
    return 0;
}
