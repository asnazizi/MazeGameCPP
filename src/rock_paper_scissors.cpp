#include <iostream> 
#define rounds 3
#include <fstream>
using namespace std;


const char Rock = 'r';
const char Paper = 'p';
const char Scissors = 's';
static int user_status = 0;
static int computer_status = 0;
int win; 
//Input : number of symbols (type int) and the symbol to print (type char)
//Output : 
//Function: create a format for printing
void format(int n, char symbol)
{
    
    for (int i = 0; i < n; i++)
    {
        
        cout << symbol;
    }
    
    cout << endl;
}
//Input : -
//Output : a randomly outputted letter from 's', 'p' or 'r'
//Function: returns the computer's choice 
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
//Input : asks for user input for a letter (type char)
//Output : outputs 's' or 'p' or 'r'(type char)
//Function: returns the user's input 
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

//Input : current round (type int)
//Output : - 
//Function: checks the user choice compared to computer choice to check who won the current round 
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
        computer_status++;
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

//Input : -
//Output : 1 if user is the winner, 0 if computer is the winner (type bool)
//Function: checks who won the game compared to all 3 rounds 
bool winner()
{
    if (user_status == computer_status)
    {
        //cout << "This game was a tie, please try again" << endl;
        win = computer_status;
        return false; 
    }
    
    else if (user_status > computer_status)
    {
        //cout << "You won the game! You may pass through" << endl;
        win = user_status;
        return true;
        
    }
    
    else
    {
        //cout << "You lost this game, please try again" << endl;
        win = computer_status;
        return false; 
    }
}

int main() 
{
    format(80, '_');
    cout << endl;
    cout << "ROCK, PAPER, SCISSORS!" << endl; 
    format(80, '_');
    cout << endl;
    cout << "Play a best out of 3 match and win agaisnt the maze to continue." << endl;
    cout << endl;
    cout << "Choose one of the following options: " << endl; 
    cout << "\'r\' for Rock" << endl << "\'p\' for Paper" << endl << "\'s\' for Scissors" << endl;
    format(80, '*');
    cout << endl; 
    
    play_game(0);
    winner();
    
    ofstream myfile; // storing status of game in file.txt
    myfile.open("file.txt");
    if (win == true )
    {
        cout << "\nYou won! You may proceed.\n" << endl;    
        myfile << 1 << endl;
    }
    else
    {
        cout << "\nYou lost! Try again.\n" << endl;
        myfile << 0 << endl;
    }

    myfile.close();

    
    return 0; 
    
}


