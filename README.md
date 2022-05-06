# G134 - Maze and Mini games 
Team members - Sathya Geetha Balaji, Aisan Azizi<br />
__________________________________________________________
Abstract:<br /><br />
It should be noted that our team chose to implement a maze and mini games project due to several reasons.<br /><br />Firstly, the question of generating a random maze with a solvable path posed an interesting challenge to us, and we had the opportunity to explore different algorithms that implement this idea. Secondly, we preferred to work on several small games rather than a whole due to the fact that we could explore various implementations of interaction with users i.e. diverse input and output - in a single project. We also believe that a constant change in the flow of the game makes it interesting for the user to keep on playing. Finally, breaking down a conventional maze game and adding our own ideas to it was an enjoyable and educative experience to both of us.<br /><br />Therefore, with the implementation of the features listed below, we aimed to simultaneously meet the project requirements whilst also testing out the capabilities of C++. <br />
_____________________________

Objective - To solve the maze and reach the end point.

Description - A game based on passing through a user-based maze, whilst solving random minigames, to reach the end.

Steps: 
1) Welcome message is shown to user.
2) Dimensions are asked for a new maze.
3) User starts at beginning of generated maze. 
4) User is prompted to enter direction to move through the maze.
5) In case of invalid input, user is prompted to try again and is taken to step 4.
6) Mini-games are randomly presented in the maze.
7) In case of mini-game execution, user plays mini-game until win in order to progress.
8) When user reaches end of maze, game ends.

Game rules:
1) Maze dimensions must be between 10 and 50.
2) Player must play mini-games until win in order to progress.
3) Player wins maze when they reach east/right maze wall.
___________________________________________________________________________________

List of Features: 
1) Generation of random game sets or events:
    - Randomely generated maze.
    - Random sets are generated in all 6 mini games
  
2) Data structures for storing game status:
    - Dynamic array storing user progress throughout the maze, loading user progress after completion of mini-game.
    - Arrays and enum used as data structures in mini games for storing mini game user status.
  
3) Dynamic memory management:
    - Maze generated in dynamic array by user's inputted dimensions.
  
4) File input/output 
    - Loading game status of user from mini-games to maze, not allowing progress until mini-game has been won.

5) Program codes in multiple files:
 (It should be noted that the system() command was used to link files)
    - Maze
    - Riddle mini game
    - Rock Paper Scissors mini game
    - Word Search mini game
    - Tic-Tac-Toe mini game
    - Word Jumble mini game
    - Math mini game
    
6) Others
    - Easy quick start as main program compiles all mini-games automatically using system() command.
    - Multiple mini games allowing different types of interaction between user and program.
    - Possible errors in user input/file compilation/file execution foreseen and measures in place.
________________________________________________________
 
Compilation and Execution Instructions:
1) Download all included files (.txt .cpp) in src directory. Ensure their placement in same directory.
2) Compile "maze.cpp" file using "g++ -pedantic-errors -std=c++11 maze.cpp -o maze".
3) Execute game by inputting "./maze" in console.
__________________________________________________________________
Notes:
- Server used for testing is academy21.
- Sample I/O pdf may be located in sample directory.
