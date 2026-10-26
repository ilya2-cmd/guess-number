#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    srand(time(0));
    char play_again;

    do{
    
        int rand_number = rand()% 100 + 1;
        int number = 0;
        int cnt = 0;
        const int MAX_ATTEMPTS = 7;
    
        while (number != rand_number && cnt < MAX_ATTEMPTS){
            cnt++;
            cout << "Your number: "; cin >> number;
            if (cin.fail()){
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input! Please enter a number" << endl;
                cnt--;
                continue;
            }
            if (cnt < MAX_ATTEMPTS){
                if (number < rand_number){
                    cout << "Too low! Try again" << endl;
                }
                else if (number > rand_number){
                    cout << "Too high! Try again" << endl;
                }
            }
        }
    
        if (number == rand_number){
            cout << "Correct! You guessed it in " << cnt << " attempts" << endl;
        }
        else {
            cout << "You lose! Correct answer: " << rand_number << endl;
        }
    
        cout << "Play again?(y/n): "; cin >> play_again;
    } while (play_again == 'y' || play_again == 'Y');

    return 0;
}