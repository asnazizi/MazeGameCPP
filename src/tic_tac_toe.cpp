#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

// Input: tic-tac-toe board (type string array)
// Output: -
// Function: print tic-tac-toe board
void ShowBoard(string board[][3])
{
    cout << "+---+---+---+" << endl;
    for(int i=0; i<3; ++i)
    {
        for(int j=0; j<3; ++j)
            cout << "| " << board[i][j] << " ";
        cout << "|" << endl;
        cout << "+---+---+---+" << endl;
    }
}

int draw = 0;   // counts cells until draw
string win = "";    // stores the piece, if any, that has won

// Input: tic-tac-toe board (type string array)
// Output: game over value (type bool)
// Function: checks whether the game has been won/ is a draw
bool GameOver(string board[][3])
{
    int draw = 0;
    for (int i=0; i < 3; ++i)
    {
        if (board[i][0] == board[i][1] && board[i][1]==board[i][2]) // horizontal win
        {   
            win = board[i][0];
            return true;
        }
        else if (board[0][i] == board[1][i] && board[1][i] == board[2][i])  // vertical win
        {
            win = board[0][i];
            return true;
        }
    }
    if (board[0][0]==board[1][1] && board[1][1]==board[2][2]) // negative diagonal win
    {
        win = board[1][1];
        return true;
    }
    else if (board[0][2]==board[1][1] && board[1][1]==board[2][0]) // positive diagonal win
    {
        win = board[1][1];
        return true;
    }
    else if (draw == 9) // draw
    {
        win = "No one";
        return true;
    }
    else
        return false;
}

// Input: tic-tac-toe board (type string array), user's piece (type string)
// Output: -
// Function: computer makes random move on tic-tac-toe board
void RandomMove(string board[][3], string piece_u)
{
    srand(int(time(0)));
    string piece, move;
    bool invalid = true;

    if (piece_u == "X") // computer's piece
        piece = "O";    
    else
        piece = "X";

    while (invalid)
    {
        move = to_string(rand()%9+1);   // random move

        /* validating and executing move */

        if (move == "1")
        {
            if (board[0][0]!="1")
                continue;
            board[0][0] = piece;
            invalid = false;
        }   
        else if (move == "2")
        {
            if (board[0][1]!="2")
                continue;
            board[0][1] = piece;
            invalid = false;
        }
        else if (move == "3")
        {
            if (board[0][2]!="3")
                continue;
            board[0][2] = piece;
            invalid = false;
        }
        else if (move == "4")
        {
            if (board[1][0]!="4")
                continue;
            board[1][0] = piece;
            invalid = false;
        }
        else if (move == "5")
        {
            if (board[1][1]!="5")
                continue;
            board[1][1] = piece;
            invalid = false;
        }
        else if (move == "6")
        {
            if (board[1][2]!="6")
                continue;
            board[1][2] = piece;
            invalid = false;
        }
        else if (move == "7")
        {
            if (board[2][0]!="7")
                continue;
            board[2][0] = piece;
            invalid = false;
        }
        else if (move =="8")
        {
            if (board[2][1]!="8")
                continue;
            board[2][1] = piece;
            invalid = false;
        }
        else if (move == "9")
        {
            if (board[2][2]!="9")
                continue;
            board[2][2] = piece;
            invalid = false;
        }
    }
    draw+=1; 

    ShowBoard(board);
    cout << "Computer's move: " << move << endl;
    cout << endl;
}

// Input: tic-tac-toe board (type string array), user's piece (type string)
// Output: -
// Function: stimulate play of tic-tac-toe, with user's move and computer's random move
void Play(string board[][3], string piece)
{
    string move;
    while(!GameOver(board))
    {
        ShowBoard(board);
        cout << "Choose your move (1-9): ";
        cin >> move;
        cout << endl;

        /* validating and executing move */

        if (move == "1")
        {
            if (board[0][0]!="1")
            {
                cout << "That move is taken! Try again.\n" << endl;
                continue;;
            }
            board[0][0] = piece;
            draw+=1;
        }   
        else if (move == "2")
        {
            if (board[0][1]!="2")
                {
                    cout << "That move is taken! Try again.\n" << endl;
                    continue;
                }
            board[0][1] = piece;
            draw+=1;
        }
        else if (move == "3")
        {
            if (board[0][2]!="3")
            {
                cout << "That move is taken! Try again.\n" << endl;
                continue;
            }
            board[0][2] = piece;
            draw+=1;
        }
        else if (move == "4")
        {
            if (board[1][0]!="4")
            {
                cout << "That move is taken! Try again.\n" << endl;
                continue;
            }
            board[1][0] = piece;
            draw+=1;
        }
        else if (move == "5")
        {
            if (board[1][1]!="5")
            {
                cout << "That move is taken! Try again.\n" << endl;
                continue;
            }
            board[1][1] = piece;
            draw+=1;
        }
        else if (move == "6")
        {
            if (board[1][2]!="6")
            {
                cout << "That move is taken! Try again.\n" << endl;
                continue;
            }
            board[1][2] = piece;
            draw+=1;
        }
        else if (move == "7")
        {
            if (board[2][0]!="7")
            {
                cout << "That move is taken! Try again.\n" << endl;
                continue;
            }
            board[2][0] = piece;
            draw+=1;
        }
        else if (move =="8")
        {
            if (board[2][1]!="8")
            {
                cout << "That move is taken! Try again.\n" << endl;
                continue;
            }
            board[2][1] = piece;
            draw+=1;
        }
        else if (move == "9")
        {
            if (board[2][2]!="9")
            {
                cout << "That move is taken! Try again.\n" << endl;
                continue;
            }
            board[2][2] = piece;
            draw+=1;
        }
        else    // error
            cout << "Invalid input. Try again.\n" << endl;
        
        if (GameOver(board))
            break;
        else
            RandomMove(board, piece);
    }
    ShowBoard(board);
    cout << "Game Over!" << endl;
    cout << win << " wins." << endl;
}

int main()
{
    string board[3][3] = {{"1","2","3"},{"4","5","6"},{"7","8","9"}};
    string piece;

    cout << "Let's Play Tic-Tac-Toe!\n\nChoose your piece (X/O): " ;
    cin >> piece;
    while (piece != "X" && piece != "O")    // error
    {
        cout << "\nInvalid input. Try again.\n" << endl;
        cout << "Choose your piece (X/O): ";
        cin >> piece;
    }

    Play(board, piece); // stimulating game

    ofstream myfile;    // storing status of game in file.txt
    myfile.open("file.txt");
    if (win == piece)
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
