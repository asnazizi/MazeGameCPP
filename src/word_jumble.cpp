#include <iostream>
#include <string>
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

//Input : user guess (type string) 
//Output : -
//Function: checks whether the guess and word is the same 
void play_game()
{
    //if (current == rounds) return;
    enum subject {word, hint, num};
    const int num_words = 7; 
    const string words[num_words][num] = 
    {
        {"crowd", "A group of many people"}, 
        {"cinnamon", "An ingredient used in sweet dishes"},
        {"electricity", "All your appliances work on this"},
        {"scramble", "A synonym of jumble"},
        {"hardworking", "You must be ___ to be successful"},
        {"australian", "A nationality"},
        {"capital","The administrative centre of a country"}
        
    };
    
    
    srand(time(0));
    int random = rand() % num_words;
    string the_word = words[random][word];
    string the_hint = words[random][hint];
    
    string jumble = the_word;
    int jumble_len = jumble.size();
    for (int i =0; i< jumble_len;i++)
    {
        int idx1 = rand() % jumble_len; //random index from the word
        int idx2 = rand() % jumble_len; // random index from the word
        
        char temp = jumble[idx1];
        jumble[idx1] = jumble[idx2];
        jumble[idx2] = temp; //swap the idices to give a jumbled word 
    }
    
    cout << "Unjumble the word : " << jumble << endl;
    
    int tries = 0;
    string guess;
    cout << "Guess : ";
    cin >> guess; 
    cout << endl;
    
    while ( tries != 2 && guess != the_word) // user is allowed to guess twice 
    {
        if (guess == "hint")
        {
            cout << the_hint;
            cout << endl;
        }
        
        else
        {
            cout << "You guessed wrong! try again" << endl;
            cout << endl;
            tries++;
        }
        
        cout << "Guess : ";
        cin >> guess;
        cout << endl;
    }
    
    ofstream fout;    // storing status of game in file.txt
    fout.open("file.txt");
    if (guess == the_word)
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
    
    
    //play_game(++current);
}
int main()
{
    format(80, '_');
    cout << endl;
    cout << "WELCOME TO WORD JUMBLE!" << endl; 
    format(80, '_');
    cout << endl;
    cout << "Unjumble the given word to continue" << endl;
    cout << "Enter 'hint' for a hint" << endl;
    cout << "Enter 'quit' to quit the game" << endl; 
    cout << endl; 
    format(80, '*');
    cout << endl;
    
    play_game();
    
    
    return 0;
}
