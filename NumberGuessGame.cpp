#include <iostream>  

using namespace std;

class game {
private:
    int guess, attempts;
    int randomnumber;

public:
    game() {
        guess = 0;
        attempts = 0;
        srand(time(0));
        randomnumber = rand() % 100 + 1;
    }

    void playgame() {
        cout << "*****Welcome to Number Guess Game*****\n" << endl;
        cout << "I have selected a number between 1 - 100, and you have to guess the number\n" << endl;
    }

    void guessnumber() {
        cout << "Please Enter your Guess: ";
        cin >> guess;
        if (guess == randomnumber) {
            cout << "Congratulations! You have guessed the number right!!\n" << endl;
        }
        else {
            if (guess > randomnumber) {
                if (guess >= randomnumber + 1 && guess <= randomnumber + 10) {
                    cout << "Very Close, but a little bit lower\n" << endl;
                }
                else {
                    cout << "Very High, Try Again\n" << endl;
                }
            }
            if (guess < randomnumber) {
                if (guess <= randomnumber - 1 && guess >= randomnumber - 10) {
                    cout << "Very Close, but a little bit higher\n" << endl;
                }
                else {
                    cout << "Very Low, Try Again\n" << endl;
                }
            }
        }
        attempts++;

        cout << "Number of Attempts: " << attempts << "\n" << endl;

        if (guess != randomnumber) {
            guessnumber();
        }
    }
};

int main() {
    game g;
    g.playgame();
    int choice;

    while (true) {
        cout << "Press 1 to Start the game" << endl;
        cout << "Press 0 to Exit the game\n" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;
        cout << "\n";
        switch (choice) {
        case 1:
            g.guessnumber();
            return 0; 
        case 0:
            return 0;  
        default:
            cout << "Invalid Entry!!\n" << endl;
            break;
        }
    }

    return 0;
}
