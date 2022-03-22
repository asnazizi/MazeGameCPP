# G134 - Maze and Mini games 
Team members - Sathya Geetha Balaji, Aisan Azizi

Description of the game and the game rules:
Objective - to solve the maze and reach the end point
Description - A game based on solving mini games at each crossroad of the maze to reach the end
Steps - 
1) User enters the maze 
2) The program automatically takes the user to the next crossroad 
3) At each crossroad, the user is presented with a choice of either to play a mini game or go back to the previous crossroad. In order to choose the path at the crossroad, user has to win the mini game. If they lose, they are supposed to play the mini-game until they pass
4) If the user takes the wrong turn, and the user wants to go back a crossroad, they are given the choice. 
5) the third step is repeated with different mini game at each crossroad, until player dies or finds the way out.
6) The game randomly generates sudden-death mini-games at any point, which if they lose, the game automatically terminates. 

Game rules:
1) If the user loses sudden-death game, they die 
2) If the user takes a wrong turn, they would have to repeat the mini-game 

List of Features: 
1. Generation of random game sets or events - sudden-death mini game, as an obstacle at any random time step. 
2. Data structures for storing game status - arrays and vectors that store the user position (which crossroad they are at) 
3. Dynamic memory management - 
4. File input/output - Output is the choice between minigames/previous cross-roads (if applicable), dead-end pop-up message. Input is choice between mini-games/previous crossroad, mini-game I/O, choice of the path they wish to take.
5. Program codes in multiple files - each mini-game stored in seperate files, maze stored in main file, random-obstacle generator file, welcome message and game rule file. 
