# G134 - Maze and Mini games 
Team members - Sathya Geetha Balaji, Aisan Azizi

Objective - to solve the maze and reach the end point

Description - A game based on solving mini games at each crossroad of the maze to reach the end

Steps 
1) Welcome message is shown to user and they enter the maze .
2) The program automatically takes the user to the next crossroad.
3) At each crossroad, the user is presented with a choice of either to play a mini game or go back to the previous crossroad (if applicable). In order to choose the path at the crossroad, user has to win the mini game. If the user loses, they are supposed to play the mini-game until they win.
4) If the user takes a wrong turn, they may go to the previous crossroad (if applicable).
5) The game randomly generates sudden-death mini-games at any point. If the user loses, the game will automatically terminate. 
6) The third step is repeated with different minigames at each crossroad, until player dies or finds the way out.


Game rules:
1) The user should play crossroad minigame until it is won to be able to proceed.
1) If the user loses sudden-death game, they die and game terminates. 
2) If the user reaches a dead-end, the program will automatically take user to previous crossroad.

List of Features: 
1. Generation of random game sets or events - Sudden-death mini game, as an obstacle at any random turn of the user. 
2. Data structures for storing game status - Vector that stores the user position (which crossroad they are at). 
3. Dynamic memory management - 
4. File input/output - Input is user's choice between mini-games/previous crossroad, mini-game I/O, and choice of the path they wish to take. Output is the choice between minigames/previous cross-roads (if applicable), and dead-end pop-up message. 
5. Program codes in multiple files - Welcome message and game rule file, each mini-game stored in seperate file, random-obstacle generator file, maze stored in main file.
