#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

long long TurnToDecimal(string input)
{
    long long num = 0;
    long long i = input.length() - 1;
    for(int j = 0; i >= 0; i--, j++)
    {
        int digit = 0;
        switch (input[i]) {
            case '=':
                digit = -2;
                break;
            case '-':
                digit = -1;
                break;
            case '0':
                digit = 0;
                break;
            case '1':
                digit = 1;
                break;
            case '2':
                digit = 2;
                break;
        }
        
        long long multiplayer = pow(5, j);
        num += (multiplayer * digit);
    }
    
    return num;
}

string TurnToSNAFU(long long number)
{
    string result = "";

    while(number) {
        switch(number % 5)
        {
            case 0:
                result += '0';
                number /= 5;
                break;
            case 1:
                result += '1';
                number /= 5;
                break;
            case 2:
                result += '2';
                number /= 5;
                break;
            case 3:
                result += '=';
                number /= 5;
                number++;
                break;
            case 4:
                result += '-';
                number /= 5;
                number++;
                break;
        }
    }

    reverse(result.begin(), result.end());

    return result;
}

void SNAFU()
{
    string input;
    long long sum = 0;
    while(getline(cin, input))
    {
        long long num = TurnToDecimal(input);
        sum += num;
    }
    
    cout << sum << endl;
    string output = TurnToSNAFU(sum);
    cout << output << endl;
}

int main() {
    SNAFU();
    return 0;
}
