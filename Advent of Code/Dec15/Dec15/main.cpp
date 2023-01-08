#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

void MakeVisited(map<pair<long long, long long>, pair<long long, long long>>& sAndB, long long difference, long long x1, long long y1)
{
    int counter = 1;
    while(counter <= difference)
    {
        
        
        
        
        
        counter++;
    }
}

void SensorsAndBeacons()
{
    map<pair<long long, long long>, pair<long long, long long>> sAndB;
    string input;
    string sensor, at, xS, yS, closest, beacon, is, xB, yB;
    long long minX = 0;
    long long maxX = 0;
    long long maxY = 0;
    while(cin >> sensor >> at >> xS >> yS >> closest >> beacon >> is >> at >> xB >> yB)
    {
        long long XS = stoll(xS.substr(2, xS.length() - 3));
        long long YS = stoll(yS.substr(2, xS.length() - 3));
        long long XB;
        if(xB[2] == '-')
        {
            XB = -1 * stoll(xB.substr(3, xB.length() - 4));
        }
        else
        {
            XB = stoll(xB.substr(2, xB.length() - 3));
        }
        long long YB = stoll(yB.substr(2, xS.length() - 2));
        sAndB.insert({{XS, YS}, {XB, YB}});
        minX = min(minX, min(XS, XB));
        maxX = max(maxX, max(XS, XB));
        maxY = max(maxY, max(YS, YB));
    }
    
    map<pair<long long, long long>, pair<long long, long long>> sAndB2;
    if(minX < 0)
    {
        maxX += (-1) * minX;
        for(auto it = sAndB.begin(); it != sAndB.end(); it++)
        {
            it->second.first += (-1) * minX;
            sAndB2.insert({{it->first.first + (-1) * minX, it->first.second}, {it->second.first, it->second.second}});
        }
        
        sAndB = sAndB2;
    }
    
    vector<vector<char>> matrix(maxY + 1);
    for(long long i = 0; i < maxY + 1; i++)
    {
        vector<char> temp(2 * maxX + 1, '.');
        matrix[i] = temp;
    }
    
    //TODO: Logic
    for(auto it = sAndB.begin(); it != sAndB.end(); it++)
    {
        long long x1 = it->first.first;
        long long y1 = it->first.second;
        long long x2 = it->second.first;
        long long y2 = it->second.second;
        matrix[x1][y1] = 'S';
        matrix[x2][y2] = 'B';
    }
    
    for(auto it = sAndB.begin(); it != sAndB.end(); it++)
    {
        long long x1 = it->first.first;
        long long y1 = it->first.second;
        long long x2 = it->second.first;
        long long y2 = it->second.second;
        long long difference = abs(x1 - x2) + abs(y1 - y2);
        MakeVisited(sAndB, difference, x1, y1);
    }
    
    long long counter = 0;
    for(long long i = 0; i < 2 * maxX + 1; i++)
    {
        if(matrix[10][i] == '#')
        {
            counter++;
        }
    }
    
    cout << counter << endl;
}

int main() {
    SensorsAndBeacons();
    return 0;
}
