#include <iostream> 
#include <cstring>
#include <cstdlib> 
#include <ctime> 
#include <fstream>
#define rounds 3

using namespace std; 

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

//Input : current round to start with (type int)
//Output : the final amount left and current round 
//Function: returns the final amount to indicate if its a loss or win

void play_game(int current)
{
    int amount = 40; 
    do
    {
        while(amount != 0)
        {
    int bet; 
    int dice; 
    int guess;
    srand(time(0));
    
    dice = 1 + rand() %10; 
    
    cout << "Enter betting amount (must be more than 10) : " ;
    cin >> bet;
    cout << endl;
    
    while(bet < 10 || bet > amount)
    {
        cout << "Your betting amount should be more than $10 and less than your current balance\n" << endl;
        cout << "Please re-enter amount :" ; 
        cin >> bet; 
    }
    
    // if(bet > amount)
    // {
    //     cout << "Your betting amount is more than your current balance\n";
    //     cout << "Please re-enter amount :" ; 
    //     cin >> bet; 
    // }
    
    cout << "Guess a number between 1 and 10 : "; 
    cin >> guess;
    cout << endl; 
    
    if(guess <= 0 || guess > 10)
                cout << "Please check the number!! should be between 1 to 10\n"
                    <<"\nRe-enter data\n ";
                    
    if (dice == guess)
    {
        cout << "Congratulation! You won $" << bet*2 << endl; 
        amount += (bet*2);
    }
    
    else
    {
       cout << "Better luck next time! You lost $" << bet << endl; 
       amount -= bet; 
    }
    
    cout << "The winning number was : " << dice <<endl;
    cout << endl;
    
    cout << "You have $ " << amount << " remaining" << endl;
    
        
        current++; //update the current round after each a loop
        } break;
    } while (current != rounds);
    
    ofstream fout;    // storing status of game in file.txt
    fout.open("file.txt");
    if (amount > 10)
    {
        cout << "\nYou won! You may proceed.\n" << endl;    
        fout << 1 << endl;
    }
    else
    {
        cout << "\nYou have too less money to continue! Try again.\n" << endl;
        fout << 0 << endl;
    }

    fout.close();
   
}

int main()
{
    format(80, '_');
    cout << endl;
    cout << "CASINO GUESSING GAME" << endl;
    format(80, '_');
    cout << endl;
    cout << "1. Choose any number between 1 to 10\n";
    cout << "2. If you win you will get 2 times of money you bet\n";
    cout << "3. If you bet on wrong number you will lose your betting amount\n";
    cout << "To win the game, you must have more than $10 after 3 rounds\n";
    cout << endl; 
    cout << "You are provided with an initial deposit of $40" << endl << endl; 
    format(80, '*');
    
    play_game(0); //starting the game with current round set to 0
    
}
