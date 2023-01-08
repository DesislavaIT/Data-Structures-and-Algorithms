#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>

using namespace std;

map<string, string> m; //name, value;

long long GetValue(string name)
{
    char ch = m[name][0];
    bool t = (ch >= '0' && ch <= '9');
    long long result = 0;
    if(!(t))
    {
        string name1 = "";
        string name2 = "";
        for(long long i = 0; i < 4; i++)
        {
            name1 += m[name][i];
        }
        
        char sign = m[name][5];
        
        for(long long i = 7; i < m[name].length(); i++)
        {
            name2 += m[name][i];
        }
        
        long long value1 = GetValue(name1);
        long long value2 = GetValue(name2);
        switch (sign) {
            case '+':
                result = value1 + value2;
                break;
            case '-':
                result = value1 - value2;
                break;
            case '*':
                result = value1 * value2;
                break;
            case '/':
                result = value1 / value2;
                break;
        }
        
        m[name] = result;
    }
    else
    {
        result = stoi(m[name]);
    }
    
    return result;
}

void MonkeyYelling()
{
    string input;
    while(getline(cin, input))
    {
        string name = "";
        for(int i = 0; i < 4; i++)
        {
            name += input[i];
        }
        
        string value = "";
        for(int i = 6; i < input.length(); i++)
        {
            value += input[i];
        }
        
        m.insert({name, value});
    }
    
    long long result = GetValue("root");
    cout << result << endl;
}

int main() {
    MonkeyYelling();
    return 0;
}
