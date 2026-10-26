#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    srand(time(0));
    char play_again;

    do{
        int level = 0;
        int max_attempts = 0;
        int max_number = 0;
        while (level != 1 && level != 2 && level != 3){
            cout << "Select the difficulty level(1-3): "; cin >> level;
            if (cin.fail()){
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input! Please enter a number" << endl;
            }
            else if (level == 1){
                max_attempts = 10;
                max_number = 50;
            }
            else if (level == 2){
                max_attempts = 7;
                max_number = 100;
            }
            else if (level == 3){
                max_attempts = 9;
                max_number = 500;
            }
            else {
                cout << "Invalid level! Please choose 1, 2 or 3" << endl;
            }
        }
        
        int rand_number = rand()% max_number + 1;
        int number = 0;
        int cnt = 0;
    
        while (number != rand_number && cnt < max_attempts){
            cnt++;
            cout << "Your number: "; cin >> number;
            if (cin.fail()){
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input! Please enter a number" << endl;
                cnt--;
                continue;
            }
            if (cnt < max_attempts){
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