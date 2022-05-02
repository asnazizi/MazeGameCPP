#include <iostream>
#include <cstdlib>
#include <iomanip>
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
    }

    pos += c*k;
    row_fr = (pos+c)/c;     // row of first right movement, to be used
    k = rand()%(c-5-pos%c)+2;    // 1-twolessthanboundary right
    for(int i=0; i<=k;++i)  
    {
        maze[i+c+pos] = '.';
    }

    pos += c+k;
    k = rand()%r/5+1; // 1-fifthofmaze down
    for(int i=1;i<=k;++i)
    {
        maze[i*c+pos] = '.';  
    }

    pos += c*k;
    k = rand()%(pos%c - 2)+1;  // 1-twolessthanboundary left
    for(int i=0; i<=k;++i)  
    {
        maze[-i+c+pos] = '.';
    }

    pos += c-k;
    k = rand()%r/5+1;   // 1-fifthofmaze down
    for(int i=1;i<=k;++i)
    {
        maze[i*c+pos] = '.';  
    }
      
    pos += c*k;
    k = rand()%(c-5-pos%c)+1;   // 1-threelessthanboundary right 
    for(int i=0; i<=k;++i)  
    {
        maze[i+c+pos] = '.';
    } 
    
    pos += k+c;
    k = rand()%(pos/c-row_fr-2)+1;    // 1-firstrightmovement up
    for(int i=1;i<=k;++i)
    {
        maze[-i*c+pos] = '.';  
    }

    pos -= k*c+c;
    k = c-2-pos%c;  // onelessthanboundary right 
    for(int i=0; i<=k;++i)  
    {
        maze[i+c+pos] = '.';
    } 

    pos += k+c;
    k = rand()%(r-2-pos/c)+1; // 1 - onelessthanboundary down
     for(int i=1;i<=k;++i)
    {
        maze[i*c+pos] = '.';  
    }

    pos += c*k-c;
    k = c-1-pos%c;  // right all the way
    for(int i=0; i<=k;++i)  
    {
        maze[i+c+pos] = '.';
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
// Function: stimulate play of maze
void Play(char* maze, int c, int r)
{
    char move;
    int pos = c;
    maze[pos] = 'X';

    while(!GameOver(maze,c,r))
    {
        ShowMaze(maze, c, r);   // print maze each turn
        cout << "Enter your move (w,a,s,d): ";
        cin >> move;

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
                break;
            case 's':   // s is down
                if(IsInBounds(pos+c, c, r) && maze[pos+c]!='#')
                {  
                    maze[pos] = '.';
                    pos +=c;
                }
                else
                    cout << "\nInvalid input. Try again.\n" << endl;
                break;
            case 'a':   // a is left
                if(IsInBounds(pos-1, c, r) && maze[pos-1]!='#')
                { 
                    maze[pos] = '.';
                    pos -=1;
                }
                else
                    cout << "\nInvalid input. Try again.\n" << endl;
                break;
            case 'd':   // d is right
                if(IsInBounds(pos+1, c, r) && maze[pos+1]!='#')
                {   
                    maze[pos] = '.';
                    pos +=1;
                }
                else
                    cout << "\nInvalid input. Try again.\n"<< endl;
                break;
            default:    // in case input value is not valid
                cout << "\nInvalid input. Try again.\n" << endl;
        }
        maze[pos] = 'X';
    }
}

int main()
{
    int c, r;   // maze column and row dimensions

    cout << "Choose your maze dimensions (51>columns>9, 51>rows>9): " << endl;
    cin >> c >> r;

    while (c < 9 or r < 9 or c > 50 or r > 50)  // in case input value is not valid
    {
        cout << "\nInvalid input. Try again.\n" << endl;
        cout << "Choose your maze dimensions (51>columns>9, 51>rows>9): " << endl;
        cin >> c >> r;
    }

    char* maze=mazegenerator(c,r);   // generate maze
    Play(maze,c,r);     // stimulate play
    ShowMaze(maze,c,r);  // print final win board
    cout << "\nGame Over! Thank you for playing!" << endl;

    delete [] maze;

    return 0;
}
