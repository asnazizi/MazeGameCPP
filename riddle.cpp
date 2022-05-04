#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>


using namespace std; 
const int num_riddles = 3;

void format(int n, char symbol)
{
    
    for (int i = 0; i < n; i++)
    {
        
        cout << symbol;
    }
    
    cout << endl;
}

void play_game()
{  
    enum array{word, riddle, num};
    const string easy_riddles[num_riddles][num] = 
    {
        {"library", "What building has the most stories?"},
        {"coin", "What has a head and tail but no body"},
        {"towel", "What gets wet while drying"}
        
        
    };
    
    const string medium_riddles[num_riddles][num] = 
    {
        {"bank", "I have branches, but no fruit, trunk, or leaves. What am I?"},
        {"teapot","What starts with a T, ends with a T, and has T in it?"},
        {"envelope", "What begins with an “e” and only contains one letter?"}
    };
    
    const string hard_riddles[num_riddles][num] = 
    {
        {"silence", "What is so fragile that saying its name breaks it?"},
        {"tongue" , "What tastes better than it smells?"},
        {"footsteps" , "The more you take, the more you leave behind. What are they?"}
        
    };
    
    srand(time(0));
    int random = rand() % num_riddles; 
    int level;
    int tries = 1; 

    cout << "Choose the difficulty level - "; 
    cout << "(1) Easy , (2) Medium , (3) Hard : " ; 
    
    cin >> level; 
    string guess;
    cout << endl; 
    
    if (level ==1)
    {
        string the_word = easy_riddles[random][word];
        string the_riddle = easy_riddles[random][riddle];
        
        cout << the_riddle << endl;
        
        cout << "Guess : ";
        cin >> guess;
        cout << endl;
        
    while(guess != the_word && tries != 2)
    {
        cout << "You guessed wrong. Please try again" << endl;
        cout << endl;
        tries++;
        
        cout << "Guess : ";
        cin >> guess;
        cout << endl;
    }
    
     ofstream fout;
    fout.open("file.txt");
    
    if (tries == 2 && guess != the_word)
    {
        cout << "\nYou lost! Try again.\n" << endl;
        fout << 0 << endl;
    }
    
    else if (guess == the_word)
    {
       cout << "\nYou won! You may proceed." << endl; 
       fout << 1 << endl;
    }
    
    fout.close();
    }
    
    
    else if (level ==2)
    {
        string the_word = medium_riddles[random][word];
        string the_riddle = medium_riddles[random][riddle];
        
        cout << the_riddle << endl;
        
        cout << "Guess : ";
        cin >> guess;
        cout << endl;
        
        while(guess != the_word && tries != 2)
    {
        cout << "You guessed wrong. Please try again" << endl;
        cout << endl;
        tries++;
        
        cout << "Guess : ";
        cin >> guess;
        cout << endl;
    }
    
    ofstream fout;
    fout.open("file.txt");
    
    if (tries == 2 && guess != the_word)
    {
        cout << "\nYou lost! Try again.\n" << endl;
        fout << 0 << endl;
    }
    
    else if (guess == the_word)
    {
       cout << "\nYou won! You may proceed." << endl; 
       fout << 1 << endl;
    }
    
    fout.close();
    
    }
    
    
    else if (level ==3)
    {
        string the_word = hard_riddles[random][word];
        string the_riddle = hard_riddles[random][riddle];
        
        cout << the_riddle << endl;
        
        cout << "Guess : ";
        cin >> guess;
        cout << endl;
        
        while(guess != the_word && tries!= 2)
    {
        cout << "You guessed wrong. Please try again" << endl;
        cout << endl;
        tries++;
        
        cout << "Guess : ";
        cin >> guess;
        cout << endl;
    }
    
    ofstream fout;
    fout.open("file.txt");
    
    if (tries == 2 && guess != the_word)
    {
        cout << "\nYou lost! Try again.\n" << endl;
        fout << 0 << endl;
    }
    
    else if (guess == the_word)
    {
       cout << "\nYou won! You may proceed." << endl; 
       fout << 1 << endl;
    }
    
    fout.close();
    }

    
    else
    {
        cout << "Please select a valid option" << endl;
    }
    

}

int main()
{
    format(80, '_');
    cout << endl;
    cout << "SOLVE A RIDDLE!" << endl; 
    format(80, '_');
    cout << endl; 
    cout << "Solve the given riddle within 2 tries to pass through" << endl;
    cout << "Hint - the riddle has a one word answer only)" << endl;
    cout << endl; 
    format(80, '*');
    cout << endl;
    play_game();
    
    return 0;
}