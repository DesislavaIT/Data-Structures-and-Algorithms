#include <iostream>

using namespace std;

void RockPaperScissors()
{
    long long sum = 0;
    char opponent, me;
    
    while(cin >> opponent >> me)
    {
        switch (opponent) {
            case 'A':
                switch (me) {
                    case 'X':
                        sum += 1;
                        sum += 3; //draw
                        break;
                    case 'Y':
                        sum += 2;
                        sum += 6; //win
                        break;
                    case 'Z':
                        sum += 3;
                        sum += 0; //loss
                        break;
                }
                break;
            case 'B':
                switch (me) {
                    case 'X':
                        sum += 1;
                        sum += 0; //loss
                        break;
                    case 'Y':
                        sum += 2;
                        sum += 3; //draw
                        break;
                    case 'Z':
                        sum += 3;
                        sum += 6; //win
                        break;
                }
                break;
            case 'C':
                switch (me) {
                    case 'X':
                        sum += 1;
                        sum += 6; //win
                        break;
                    case 'Y':
                        sum += 2;
                        sum += 0; //loss
                        break;
                    case 'Z':
                        sum += 3;
                        sum += 3; //draw
                        break;
                }
                break;
        }
    }
    
    cout << sum << endl;
}

void LossDrawWin()
{
    long long sum = 0;
    char opponent, me;
    
    while(cin >> opponent >> me)
    {
        switch (opponent) {
            case 'A':
                switch (me) {
                    case 'X':
                        sum += 3; //choose scissors
                        sum += 0; //loss
                        break;
                    case 'Y':
                        sum += 1; //choose rock
                        sum += 3; //draw
                        break;
                    case 'Z':
                        sum += 2; //choose paper
                        sum += 6; //win
                        break;
                }
                break;
            case 'B':
                switch (me) {
                    case 'X':
                        sum += 1; //choose rock
                        sum += 0; //loss
                        break;
                    case 'Y':
                        sum += 2; //choose paper
                        sum += 3; //draw
                        break;
                    case 'Z':
                        sum += 3; //choose scissors
                        sum += 6; //win
                        break;
                }
                break;
            case 'C':
                switch (me) {
                    case 'X':
                        sum += 2; //choose paper
                        sum += 0; //loss
                        break;
                    case 'Y':
                        sum += 3; //choose scissors
                        sum += 3; //draw
                        break;
                    case 'Z':
                        sum += 1; //choose rock
                        sum += 6; //win
                        break;
                }
                break;
        }
    }
    
    cout << sum << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    LossDrawWin();
    return 0;
}
