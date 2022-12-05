#include <iostream>
#include <string>

using namespace std;

void FullyContainedPairs()
{
    int fullyContainedPairs = 0;
    string str;
    while(getline(cin, str))
    {
        int start1 = 0, end1 = 0, start2 = 0, end2 = 0;
        
        int firstTireIndex = str.find_first_of("-");
        int firstCommaIndex = str.find_first_of(",");
        int LastTireIndex = str.find_last_of("-");
        
        int counter = 0;
        for(; counter < firstTireIndex; counter++)
        {
            start1 = start1 * 10 + (str[counter] - 48);
        }
        
        counter++;
        for(; counter < firstCommaIndex; counter++)
        {
            end1 = end1 * 10 + (str[counter] - 48);
        }
        
        counter++;
        for(; counter < LastTireIndex; counter++)
        {
            start2 = start2 * 10 + (str[counter] - 48);
        }
        
        counter++;
        for(; counter < str.length(); counter++)
        {
            end2 = end2 * 10 + (str[counter] - 48);
        }
        
        if(start2 >= start1 && end2 <= end1)
        {
            fullyContainedPairs++;
        }
        else if(start1 >= start2 && end1 <= end2)
        {
            fullyContainedPairs++;
        }
    }
    
    cout << fullyContainedPairs << endl;
}

void OverlapedPairs()
{
    int overlapedPairs = 0;
    string str;
    while(getline(cin, str))
    {
        int start1 = 0, end1 = 0, start2 = 0, end2 = 0;
        
        int firstTireIndex = str.find_first_of("-");
        int firstCommaIndex = str.find_first_of(",");
        int LastTireIndex = str.find_last_of("-");
        
        int counter = 0;
        for(; counter < firstTireIndex; counter++)
        {
            start1 = start1 * 10 + (str[counter] - 48);
        }
        
        counter++;
        for(; counter < firstCommaIndex; counter++)
        {
            end1 = end1 * 10 + (str[counter] - 48);
        }
        
        counter++;
        for(; counter < LastTireIndex; counter++)
        {
            start2 = start2 * 10 + (str[counter] - 48);
        }
        
        counter++;
        for(; counter < str.length(); counter++)
        {
            end2 = end2 * 10 + (str[counter] - 48);
        }
        
        if(start2 >= start1 && start2 <= end1)
        {
            overlapedPairs++;
        }
        else if(start1 >= start2 && start1 <= end2)
        {
            overlapedPairs++;
        }
    }
    
    cout << overlapedPairs << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    OverlapedPairs();
    return 0;
}
