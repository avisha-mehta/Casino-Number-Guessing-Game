#include <iostream>
using namespace std;

int main() {
    int a, b;
    char op;

    cout << "Enter expression (e.g. 10 + 5): ";
    cin >> a >> op >> b;

    switch (op) {
        case '+':
            cout << a + b;
            break;
```cpp
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


// User-defined data type
struct Difficulty
{
    string name;
    int maxNumber;
    int attempts;
    int prize;
};


// Class for the Casino Game
class CasinoGame
{
private:
    int money;

public:

    // Constructor
    CasinoGame(int startingMoney)
    {
        money = startingMoney;
    }


    // Function to display money
    void showMoney()
    {
        cout << "Current Money: $" << money << endl;
    }


    // Function to play the game
    void playGame(Difficulty level)
    {
        cout << "\n===== " << level.name << " Level =====\n";

        cout << "Guess a number between 1 and "
             << level.maxNumber << endl;

        cout << "You have " << level.attempts
             << " attempts.\n";

        cout << "Prize: $" << level.prize << endl;


        // Generate a random number
        int randomNumber =
            rand() % level.maxNumber + 1;

        int guess;
        bool won = false;


        // Loop for number of attempts
        for (int i = 1; i <= level.attempts; i++)
        {
            cout << "\nAttempt " << i << ": ";
            cin >> guess;


            // Check the guess
            if (guess == randomNumber)
            {
                cout << "Congratulations! You guessed it right.\n";
                cout << "You won $" << level.prize << "!\n";

                money += level.prize;

                won = true;

                break;
            }
            else if (guess < randomNumber)
            {
                cout << "Too low! Try again.\n";
            }
            else
            {
                cout << "Too high! Try again.\n";
            }
        }


        // If player did not guess correctly
        if (!won)
        {
            cout << "\nYou lost the game.\n";
            cout << "The correct number was "
                 << randomNumber << ".\n";
        }
    }
};


int main()
{
    // Seed for random number generation
    srand(time(0));


    // STL vector containing difficulty levels
    vector<Difficulty> levels =
    {
        {"Easy", 50, 10, 50},
        {"Medium", 100, 7, 100},
        {"Hard", 500, 5, 500}
    };


    // Create game object
    CasinoGame game(100);

    int choice;


    cout << "====================================\n";
    cout << "     CASINO NUMBER GUESSING GAME\n";
    cout << "====================================\n";

    cout << "Starting Money: $100\n";


    // Main game loop
    while (true)
    {
        cout << "\n";
        game.showMoney();


        cout << "\nChoose Difficulty:\n";
        cout << "1. Easy\n";
        cout << "2. Medium\n";
        cout << "3. Hard\n";
        cout << "4. Exit\n";


        cout << "Enter your choice: ";
        cin >> choice;


        // Exit the game
        if (choice == 4)
        {
            cout << "\nThank you for playing!\n";
            break;
        }


        // Check valid choice
        if (choice >= 1 && choice <= 3)
        {
            game.playGame(levels[choice - 1]);
        }
        else
        {
            cout << "Invalid choice! Please try again.\n";
        }
    }


    return 0;
}
```
        case '-':
            cout << a - b;
            break;

        case '*':
            cout << a * b;
            break;

        case '/':
            if (b == 0)
                cout << "Cannot divide by zero";
            else
                cout << (double)a / b;
            break;

        case '%':
            if (b == 0)
                cout << "Cannot modulo by zero";
            else
                cout << a % b;
            break;

        default:
            cout << "Invalid operator";
    }

    return 0;
}