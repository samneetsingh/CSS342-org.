#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

int randomNumber() {
    
    int randomNumber;
    randomNumber = (rand() % 3) + 1;

    return(randomNumber);
}

bool validInputGame(string userInput) {
    
    string rock = "rock";
    string paper = "paper";
    string scissors = "scissors";
    if(userInput == rock || userInput == paper || userInput == scissors) {
        return true;
    } else {
        return false;
    }
}

bool validInputReplay(string userInputReplay) {
    
    bool valid;
    string yes = "yes";
    string no = "no";

    if(userInputReplay == yes || userInputReplay == no) {
        valid = true;
    } else {
        valid = false;
        cout << "Invalid Input, please reenter 'yes' or 'no': " << endl;
        cin >> userInputReplay;
        validInputReplay(userInputReplay);
    }

    return valid;
}

string Initial() {
    
    string userInput;
    cout << endl << "Hi Chase!!! Rock, Paper, or Scissors?" << endl;
    cin >> userInput;
    return(userInput);
}

string ReRunProgram() {

    string userInput;
    cout << endl << "Rock, Paper, or Scissors?" << endl;
    cin >> userInput;
    return(userInput);
}

int inputToInt(string userInput) {
    
    bool valid = validInputGame(userInput);

    if(valid == true) {
        string rock = "rock";
        string paper = "paper";
        string scissors = "scissors";
        int rpc;

        if(userInput == rock) {
                rpc = 1;
            } else if(userInput == paper) {
                rpc = 2;
            } else if(userInput == scissors) {
                rpc = 3;
            }

        return(rpc);
    } else {
        cout << endl << "Invalid Input, please try again." << endl;
        ReRunProgram();
    }
    return(0);
}

int sol(int rpc, int computer) {
    
    int solution;

    if((rpc == 1 && computer == 1) || (rpc == 2 && computer == 2) || (rpc == 3 && computer == 3)) {
        solution = 0;
    } else if ((rpc == 1 && computer == 3) || (rpc == 2 && computer == 1) || (rpc == 3 && computer == 2)) {
        solution = 1;
    } else if((rpc == 1 && computer == 2) || (rpc == 2 && computer == 3) || (rpc == 3 && computer == 1)) {
        solution = 2;
    }

    return(solution);
}

int game(int rpc) {
    
    int computer = 0;
    int answer;
    computer = randomNumber();

    answer = sol(rpc, computer);

    if(answer == 0) {
        cout << "You tied. You got close, but try again." << endl;
    } else if(answer == 1) {
        cout << "Nice job!! You won!!" << endl;
    } else if(answer == 2) {
        cout << "You lost! Fucking idiot!" << endl;
    }
    return answer;
}

bool replayGame(string userInputReplay) {
    
    string yes = "yes";
    string no = "no";

    cout << "Do you want to replay the game? Enter 'yes' or 'no' : ";
    cin >> userInputReplay;
    bool isValidReplay = validInputReplay(userInputReplay);

    if(userInputReplay == yes) {
        return true;
    } else if(userInputReplay == no) {
        return false;
    }
    return false;
}

void stats(int win, int lose, int draw) {
    cout << "Your stats are as follows: ";
            cout << endl << "Wins: " << win;
            cout << endl << "Losses: " << lose;
            cout << endl << "Draws: " << draw << endl;
}

int main() {

    int rpc;
    int win = 0;
    int lose = 0;
    int draw = 0;
    string userInput;

    userInput = Initial();

    int endProgram = 1;
    while(endProgram != 2) {
        
        rpc = inputToInt(userInput);

        int gameSol;
        gameSol = game(rpc);

        if(gameSol == 0) {
            draw++;
        } else if(gameSol == 1) {
            win++;
        } else if(gameSol == 2) {
            lose++;
        }
        
        string userInputReplay;
        bool replay = replayGame(userInputReplay);

        if(replay == false) {
            endProgram = 2;
            cout << "Thanks for playing!! ";
            stats(win, lose, draw);
        }

    }
}

