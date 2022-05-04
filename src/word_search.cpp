#include <iostream> 
#include <string>
#include <ctime> 
#include <cstdlib>
#include <fstream>
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

//Input : -
//Output : outputs the total score of the game (type int)
//Function: prints a randomly generated 10*10 word search box, inserts three randomly selected words into the box horizontally or vertically and checks whether user guess is equal to the 3 words
int Game()
{
    //if (current = rounds) return; 
    char board[10][10];
    string words[10] = {"aircraft", "ashtray", "backhand", "realize", "happy", "basque", "engage", "taxi", "party", "four"};
    int random; 
    char a; 
    int score = 0 ; 
    
    srand(time(0));
    
    for(int i = 0; i < 10; i++)
    {
        for (int j =0; j < 10; j++)
        {
            random = rand() % 26; 
            a = 'a' + random;
            board[i][j] = a; //output a 10*10 alphabet board
        }
    }
    
    
    int idx = rand() % 10; // three random words from the array
    int idx2 = rand() % 10;
    int idx3 = rand() % 10; 
    
    if (idx2 == idx || idx2 == idx3)
    {
        idx2 = idx2 + 1;
    }
    
    if (idx3 == idx)
    {
        idx3 = idx3 + 1;
    }
    
    if (words[idx].length() % 2 == 0) //horizontally
    {
        int row = rand() % 10; 
        int col = rand() % 3; 
        
        for(int i =0; words[idx][i] != '\0'; i++, col++) //so that row remains constant but col gets updated
        {
           board[row][col] = words[idx][i];
        }
    }
    
    else //vertically
    {
        int row = rand() % 3; 
        int col = rand() % 10; 
        
        for(int i =0; words[idx][i] != '\0'; i++, row++) //so that col remains constant but row gets updated
        {
           board[row][col] = words[idx][i];
        }
        
    }
    
    if (words[idx2].length() % 2 == 0) //horizontally
    {
        int row = rand() % 10; 
        int col = rand() % 3; 
        
        for(int i =0; words[idx2][i] != '\0'; i++, col++) //so that row remains constant but col gets updated
        {
           board[row][col] = words[idx2][i];
        }
    }
    
    else //vertically
    {
        int row = rand() % 3; 
        int col = rand() % 10; 
        
        for(int i =0; words[idx2][i] != '\0'; i++, row++) //so that col remains constant but row gets updated
        {
           board[row][col] = words[idx2][i];
        }
        
    }
    
    if (words[idx3].length() % 2 == 0) //horizontally
    {
        int row = rand() % 10; 
        int col = rand() % 3; 
        
        for(int i =0; words[idx3][i] != '\0'; i++, col++) //so that row remains constant but col gets updated
        {
           board[row][col] = words[idx3][i];
        }
    }
    
    else //vertically
    {
        int row = rand() % 3; 
        int col = rand() % 10; 
        
        for(int i =0; words[idx3][i] != '\0'; i++, row++) //so that col remains constant but row gets updated
        {
           board[row][col] = words[idx3][i];
        }
        
    }
    
    
    format(80, '*');
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j =0; j < 10; j++)
        {
            cout << board[i][j] << " "; 
        }
        
        cout << endl;
    }
    cout << endl;
    // cout << words[idx] << endl; 
    // cout << words[idx2] <<endl;
    // cout << words[idx3] << endl;
    
    int rounds = 1;
    string guess;
    cout << "Enter your guess : " ; 
    cin >> guess; 
    
    if (guess == words[idx] || guess == words[idx2] || guess == words[idx3])
    {
        cout << "You guessed the right word! Guess 2 more words" << endl; 
        cout << endl;
        score ++;
    }
    

    else //(guess != words[idx] || guess != words[idx2] || guess != words[idx3])
    {
       cout << "You guessed the wrong word. Try again" << endl << endl; 
       
    }
    
    cout << "Enter your guess : " ;
    cin >> guess; 
    
    if (guess == words[idx] || guess == words[idx2] || guess == words[idx3])
    {
        cout << "You guessed the right word! Guess 1 more word" << endl; 
        cout << endl;
        score++;
    }
    

    else //(guess != words[idx] || guess != words[idx2] || guess != words[idx3])
    {
       cout << "You guessed the wrong word. Try again" << endl << endl; 
       
    }
    
    cout << "Enter your guess : " ;
    cin >> guess; 
    
    if (guess == words[idx] || guess == words[idx2] || guess == words[idx3]) //3 turns 
    {
        cout << "You guessed the right word!" << endl; 
        cout << endl;
        score++; 
    }
    

    else //(guess != words[idx] || guess != words[idx2] || guess != words[idx3])
    {
       cout << "You guessed the wrong word." << endl << endl; 
       
    }
    
    return score; // return the final score after all 3 tries
    
    
}

int main()
{
    int score = 0; 
    format(80, '_');
    cout << endl;
    cout << "WELCOME TO WORD SEARCH!" << endl; 
    format(80, '_');
    cout << endl;
    cout << "A word search puzzle is displayed on the screen" << endl;
    cout << "Find 3 hidden words, placed vertically or horizontally in the puzzle." << endl;
    cout << "Each word is for one point. Score atleast 2 point to win" << endl;
    cout << endl; 
    cout << "Words to search : " << endl; 
    cout << endl;
    cout << "aircraft\tashtray" << endl;
    cout << "backhand\trealize" << endl; 
    cout << "happy\t\tbasque" << endl;
    cout << "engage\t\ttaxi" << endl; 
    cout << "party\t\tfour" << endl;
    cout << endl;
      
    score = score + Game();
    
    cout << "Your total score is : " << score; 
    cout << endl; 
    
    ofstream fout;    // storing status of game in file.txt
    fout.open("file.txt");
    if (score >=2)
    {
        cout << "\nYou won! You may proceed.\n" << endl;    
        fout << 1 << endl;
    }
    else
    {
        cout << "\nYou lost! Try again.\n" << endl;
        fout << 0 << endl;
    }

    fout.close();
    
    return 0;

}
