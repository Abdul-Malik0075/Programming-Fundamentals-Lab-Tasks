#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

// Function to add delay effect
void delay(int ms) {
    Sleep(ms);
}

// Function to print fancy title
void printTitle() {
    cout << "==============================================\n";
    cout << "          ?? NUMBER GUESSING GAME ??           \n";
    cout << "==============================================\n";
}

// Function to print loading animation
void loading() {
    cout << "\nLoading";
    for (int i = 0; i < 5; i++) {
        cout << ".";
        Sleep(400);
    }
    cout << "\n";
}

// Function for easy animation
void typeText(string text, int speed = 25) {
    for (char c : text) {
        cout << c;
        Sleep(speed);
    }
    cout << endl;
}

// Function to play one round
int playLevel(int level, int &score) {
    srand(time(0));
    int number, guess, attempts = 0, maxAttempts;
    int range;

    switch (level) {
        case 1: range = 10; maxAttempts = 5; break;
        case 2: range = 50; maxAttempts = 6; break;
        case 3: range = 100; maxAttempts = 7; break;
        case 4: range = 500; maxAttempts = 8; break;
        default: range = 1000; maxAttempts = 9; break;
    }

    number = rand() % range + 1;

    cout << "\nLevel " << level << " - Guess a number between 1 and " << range << " ??" << endl;

    while (attempts < maxAttempts) {
        cout << "\nEnter your guess: ";
        cin >> guess;
        attempts++;

        if (guess == number) {
            int points = (maxAttempts - attempts + 1) * 10 * level;
            score += points;
            cout << "\n?? Correct! You earned " << points << " points.\n";
            cout << "Current Score: " << score << "\n";
            return 1;
        } else if (guess < number)
            cout << "Too low! Try again.\n";
        else
            cout << "Too high! Try again.\n";
    }

    cout << "\n? You ran out of attempts! The correct number was " << number << ".\n";
    return 0;
}

// Function to show game instructions
void showInstructions() {
    system("cls");
    printTitle();
    cout << "\n?? HOW TO PLAY:\n";
    cout << "1. You’ll be given a random number to guess.\n";
    cout << "2. The difficulty increases each level.\n";
    cout << "3. Each wrong guess costs you an attempt.\n";
    cout << "4. Earn points based on accuracy & level.\n";
    cout << "5. Try to beat your highest score!\n";
    cout << "\nPress any key to go back to the menu...";
    cin.ignore();
    cin.get();
}

// Function for main menu
int menu() {
    int choice;
    cout << "\n================== MAIN MENU ==================\n";
    cout << "1. Play Game ??\n";
    cout << "2. Instructions ??\n";
    cout << "3. Exit ?\n";
    cout << "==============================================\n";
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

// Function for high score system
void saveHighScore(int score) {
    int highscore = 0;
    ifstream fin("highscore.txt");
    if (fin)
        fin >> highscore;
    fin.close();

    if (score > highscore) {
        ofstream fout("highscore.txt");
        fout << score;
        fout.close();
        cout << "\n?? New High Score! " << score << " Points!\n";
    } else {
        cout << "\nYour Score: " << score << " | High Score: " << highscore << "\n";
    }
}

int main() {
    system("cls");
    int choice, level = 1, score = 0;
    printTitle();
    loading();

    while (true) {
        system("cls");
        printTitle();
        choice = menu();

        if (choice == 1) {
            score = 0;
            level = 1;
            while (true) {
                system("cls");
                printTitle();
                typeText("Get ready for Level " + to_string(level) + "...");
                delay(500);
                int won = playLevel(level, score);
                if (won) {
                    level++;
                    if (level > 5) {
                        cout << "\n?? You completed all levels! Final Score: " << score << "\n";
                        saveHighScore(score);
                        break;
                    }
                    char next;
                    cout << "\nProceed to next level? (y/n): ";
                    cin >> next;
                    if (next != 'y' && next != 'Y') {
                        saveHighScore(score);
                        break;
                    }
                } else {
                    saveHighScore(score);
                    break;
                }
            }
        }
        else if (choice == 2)
            showInstructions();
        else if (choice == 3) {
            typeText("\nExiting Game...");
            break;
        }
        else {
            cout << "\nInvalid choice! Try again.\n";
            Sleep(1000);
        }
    }

    cout << "\nThanks for playing! ??\n";
    return 0;
}

