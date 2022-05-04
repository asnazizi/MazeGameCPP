#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
using namespace std;

// Input: maze (type char pointer), column (type integer), row (type integer)
// Output: -
// Function: print maze
void ShowMaze(char*maze,int c,int r)
{
    int i,j;
    for(i=0;i<r;++i)
    {
        for(j=0;j<c;++j)
            cout<<setw(2)<<maze[i*c+j];  // format output
        cout<<endl;
    }
}

int count = 0;
// Input:column (type integer), row (type integer)
// Output: maze (type char pointer)
// Function: generate random maze based on column and row input
char* mazegenerator(int c, int r)
{
    char * maze = new char[c*r];    //1D array storing maze grid
    srand(int(time(0)));

    /* randomely filling maze */

    for (int i=0;i<c*r;++i)
    {   if (rand()%11 > 6)
            maze[i] = '.';
        else
            maze[i] = '#';
    }

    /* setting boundaries of maze */

    for(int i=0;i<c;++i)    // north maze boundary
        maze[i] = '#';

    for(int i=0;i<c*r;i+=c)    // west maze boundary
        maze[i] = '#';

    for(int i=c*(r-1);i<c*r;++i)    // south maze boundary
        maze[i] = '#';
    
    for(int i=c-1;i<c*r;i+=c)   // east maze boundary
        maze[i] = '#';

    /* starting point of maze */

    maze[c] = maze[c+1] = maze[c+2]= maze[2*c+1]= maze[3*c+1] = '.';    

   /* solved path pattern */
   
    int k, pos, row_fr;

    pos = 3;
    k = rand()%r/5+1; // 1-fifthofmaze down
    for(int i=1;i<=k;++i)
    {
        maze[i*c+pos] = '.';  
        count+=1;
    }

    pos += c*k;
    row_fr = (pos+c)/c;     // row of first right movement, to be used
    k = rand()%(c-5-pos%c)+2;    // 1-twolessthanboundary right
    for(int i=0; i<=k;++i)  
    {
        maze[i+c+pos] = '.';
        count+=1;
    }

    pos += c+k;
    k = rand()%r/5+1; // 1-fifthofmaze down
    for(int i=1;i<=k;++i)
    {
        maze[i*c+pos] = '.'; 
        count+=1; 
    }

    pos += c*k;
    k = rand()%(pos%c - 2)+1;  // 1-twolessthanboundary left
    for(int i=0; i<=k;++i)  
    {
        maze[-i+c+pos] = '.';
        count+=1;
    }

    pos += c-k;
    k = rand()%r/5+1;   // 1-fifthofmaze down
    for(int i=1;i<=k;++i)
    {
        maze[i*c+pos] = '.'; 
        count+=1; 
    }
      
    pos += c*k;
    k = rand()%(c-5-pos%c)+1;   // 1-threelessthanboundary right 
    for(int i=0; i<=k;++i)  
    {
        maze[i+c+pos] = '.';
        count+=1;
    } 
    
    pos += k+c;
    k = rand()%(pos/c-row_fr-2)+1;    // 1-firstrightmovement up
    for(int i=1;i<=k;++i)
    {
        maze[-i*c+pos] = '.'; 
        count+=1; 
    }

    pos -= k*c+c;
    k = c-2-pos%c;  // onelessthanboundary right 
    for(int i=0; i<=k;++i)  
    {
        maze[i+c+pos] = '.';
        count+=1;
    } 

    pos += k+c;
    k = rand()%(r-2-pos/c)+1; // 1 - onelessthanboundary down
     for(int i=1;i<=k;++i)
    {
        maze[i*c+pos] = '.'; 
        count+=1; 
    }

    pos += c*k-c;
    k = c-1-pos%c;  // right all the way
    for(int i=0; i<=k;++i)  
    {
        maze[i+c+pos] = '.';
        count+=1;
    }
    
    return maze;
}

// Input: maze (type char pointer), column (type integer), row (type integer)
// Output: game over value (type bool)
// Function: check to see whether user has reached end of maze
bool GameOver(char* maze, int c, int r)
{
    for(int i=c-1;i<c*r;i+=c)
    {
        if (maze[i] == 'X')
            return true;
    }
    return false;
}

// Input: coordinate (type integer), column (type integer), row (type integer)
// Output: is in bounds value (type bool)
// Function: check to see whether coordinate is in bound of maze
bool IsInBounds(int n, int c, int r)
{
    if (n > 0 || n < (c*r))
        return true;
    else
        return false;
}

// Input: maze (type char pointer), column (type integer), row (type integer)
// Output: -
// Function: stimulate play of maze and mini games
void Play(char* maze, int c, int r)
{
    char move;
    int pos = c, turn = 0;
    maze[pos] = 'X';

    while(!GameOver(maze,c,r))
    {
        ShowMaze(maze, c, r);   // print maze each turn
        cout << "Enter your move (w,a,s,d): ";
        cin >> move;
        cout << endl;

        /* user move */

        switch(move)
        {
            case 'w':   // w is up 
                if(IsInBounds(pos-c, c, r) && maze[pos-c]!='#')
                { 
                    maze[pos] = '.';
                    pos -=c;
                }
                else
                    cout << "\nInvalid input. Try again.\n" << endl;
                turn+=1;
                break;
            case 's':   // s is down
                if(IsInBounds(pos+c, c, r) && maze[pos+c]!='#')
                {  
                    maze[pos] = '.';
                    pos +=c;
                }
                else
                    cout << "\nInvalid input. Try again.\n" << endl;
                turn+=1;
                break;
            case 'a':   // a is left
                if(IsInBounds(pos-1, c, r) && maze[pos-1]!='#')
                { 
                    maze[pos] = '.';
                    pos -=1;
                }
                else
                    cout << "\nInvalid input. Try again.\n" << endl;
                turn+=1;
                break;
            case 'd':   // d is right
                if(IsInBounds(pos+1, c, r) && maze[pos+1]!='#')
                {   
                    maze[pos] = '.';
                    pos +=1;
                }
                else
                    cout << "\nInvalid input. Try again.\n"<< endl;
                turn+=1;
                break;
            default:    // in case input value is not valid
                cout << "\nInvalid input. Try again.\n" << endl;
        }
        maze[pos] = 'X';

        /* mini games execution */

        int win;    // repeating game if game not won
        ifstream myfile;    
        if (turn == count/7)    // riddle mini game
        {
            cout << "THE MAZE CHALLENGES YOU TO A MINI GAME!\n"<<endl;
            win = 0;
            while (win!=1)
            {
                if (!system("g++ -pedantic-errors -std=c++11 riddle.cpp -o riddle"))
                    exit;
                if (!system("./riddle"))
                    exit;
                myfile.open("file.txt");
                myfile >> win;
                myfile.close();
            }
        }
        else if (turn == count/7*2) // rock paper scissors mini game
        {
            cout << "THE MAZE CHALLENGES YOU TO A MINI GAME!\n"<<endl;
            win = 0;
            while (win!=1)
            {
                if (!system("g++ -pedantic-errors -std=c++11 rock_paper_scissors.cpp -o rock_paper_scissors"))
                    exit;
                if (!system("./rock_paper_scissors"))
                    exit;
                myfile.open("file.txt");
                myfile >> win;
                myfile.close();
            }
        } 
        else if (turn == count/7*3) // word search mini game
        {
            cout << "THE MAZE CHALLENGES YOU TO A MINI GAME!\n"<<endl;
            win = 0;
            while (win!=1)
            {
                if (!system("g++ -pedantic-errors -std=c++11 word_search.cpp -o word_search"))
                    exit;
                if (!system("./word_search"))
                    exit;
                myfile.open("file.txt");
                myfile >> win;
                myfile.close();
            }
        }
        else if (turn == count/7*4) // tic-tac-toe mini game
        {
            cout << "THE MAZE CHALLENGES YOU TO A MINI GAME!\n"<<endl;
            win = 0;
            while (win!=1)
            {
                if (!system("g++ -pedantic-errors -std=c++11 tic_tac_toe.cpp -o tic_tac_toe"))
                    exit;
                if (!system("./tic_tac_toe"))
                    exit;
                myfile.open("file.txt");
                myfile >> win;
                myfile.close();
            }
        }
        else if (turn == count/7*5) // word jumble mini game
        {
            cout << "THE MAZE CHALLENGES YOU TO A MINI GAME!\n"<<endl;
            win = 0;
            while (win!=1)
            {
                if (!system("g++ -pedantic-errors -std=c++11 word_jumble.cpp -o word_jumble"))
                    exit;
                if (!system("./word_jumble"))
                    exit;
                myfile.open("file.txt");
                myfile >> win;
                myfile.close();
            }
        }
        else if (turn == count/7*6)   // math mini game
        {
            cout << "THE MAZE CHALLENGES YOU TO A MINI GAME!\n"<<endl;
            win = 0;
            while (win!=1)
            {
                if (!system("g++ -pedantic-errors -std=c++11 math.cpp -o math"))
                    exit;
                if (!system("./math"))
                    exit;
                myfile.open("file.txt");
                myfile >> win;
                myfile.close();
            }
        }    
    }
}

int main()
{
    string name;
    cout << "WELCOME TO MAZE AND MINI GAMES!\n" << endl;
    cout << "What's your name? ";
    cin >> name;
    cout << "Nice name " << name << "\n" << endl;
    cout << "Before we begin, we would like to introduce you to the game rules:\n\n"
        << "    1. The aim of the game is for you to reach the right/east wall of the maze.\n\n"
        << "    2. You may encounter obstacles set in your path that you must overcome to proceed.\n\n"
        << "    3. Try to follow our input answer guidelines, but don't worry!\n"
        << "       We have measures in place in case you mess up.\n\n"
        << "    4. Have fun and try your best to beat the maze!\n" << endl;
    
    int c, r;   // maze column and row dimensions

    cout << name << ", choose your maze dimensions (51>columns>9, 51>rows>9): " << endl;
    cin >> c >> r;

    while (c < 9 or r < 9 or c > 50 or r > 50)  // in case input value is not valid
    {
        cout << "\nInvalid input. Try again.\n" << endl;
        cout << name << ", choose your maze dimensions (51>columns>9, 51>rows>9): " << endl;
        cin >> c >> r;
    }

    char* maze=mazegenerator(c,r);   // generate maze
    Play(maze,c,r);     // stimulate play
    ShowMaze(maze,c,r);  // print final win board
    cout << "\nGame Over! Thank you for playing " << name << "!" << endl;

    delete [] maze;

    return 0;
}
