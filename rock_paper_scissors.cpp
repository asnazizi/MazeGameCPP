#include <iostream> 
#define rounds 3
using namespace std;


const char Rock = 'r';
const char Paper = 'p';
const char Scissors = 's';
static int user_status = 0;
static int computer_status = 0;

char Computerchoice ()
{
    int num;
    srand(time(0));
    num = 1 + rand() % 3; 
    
    if(num == 1)
    {
        return 'r';
    }
    
    else if (num == 2)
    {
        return 'p';
    }
    
    else 
    {
        return 's';
    }
}

char Userchoice()
{
    char input; 
    cout << "rock, paper, scissors, shoot!: ";
    cin >> input; 
    
    if (input != 'r' && input != 'p' && input != 's')
    {
        cout << "Please enter either (r), (p) or (s)." << endl;
        cin >> input;
    }
    
    return input; 
}

void play_game(int current)
{
    if (current == rounds) return;
    //Userchoice();
    char user = Userchoice();
    char maze;
    maze = Computerchoice();
    
    if (maze == 'r')
    {
        cout << "The maze played rock" << endl;
        cout << endl;
    }
    
    else if (maze == 'p')
    {
        cout << "The maze played paper" << endl;
        cout << endl;
    }
    
    else
    {
        cout << "The maze played scissors" << endl;
        cout << endl;
    }
    
    if (user == maze)
    {
        cout << "THIS ROUND IS A TIE" << endl;
        cout << endl;
    }
    
    else if (user == 'r' && maze == 's' ||user == 's' && maze == 'p' || user == 'p' && maze == 'r')
    {
        cout << "YOU WIN THIS ROUND!" << endl;
        cout << endl;
        user_status ++;
    }
    
    else
    {
        cout << "YOU LOSE THIS ROUND" << endl;
        cout << endl;
        computer_status ++; 
    }
    
    play_game(++current);
}

void winner()
{
    if (user_status == computer_status)
    {
        cout << "This game was a tie, please try again" << endl;
    }
    
    else if (user_status > computer_status)
    {
        cout << "You won the game! You may pass through" << endl;
    }
    
    else
    {
        cout << "You lost this game, please try again" << endl;
    }
}

int main() 
{
    
    cout << "LET'S PLAY ROCK, PAPER, SCISSORS!" << endl; 
    cout << "Play a best out of 3 match and win agaisnt the maze to continue." << endl;
    cout << endl;
    cout << "Choose one of the following options: " << endl; 
    cout << "\'r\' for Rock" << endl << "\'p\' for Paper" << endl << "\'s\' for Scissors" << endl;
    cout << endl; 
    
    play_game(0);
    winner();
    
    return 0; 
    
}

