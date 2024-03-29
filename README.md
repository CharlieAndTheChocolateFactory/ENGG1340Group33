# ENGG1340Group33

                    _____                    _____                    _____                    _____          
                   /\    \                  /\    \                  /\    \                  /\    \         
                  /::\____\                /::\    \                /::\    \                /::\    \        
                 /::::|   |               /::::\    \               \:::\    \              /::::\    \       
                /:::::|   |              /::::::\    \               \:::\    \            /::::::\    \      
               /::::::|   |             /:::/\:::\    \               \:::\    \          /:::/\:::\    \     
              /:::/|::|   |            /:::/__\:::\    \               \:::\    \        /:::/__\:::\    \    
             /:::/ |::|   |           /::::\   \:::\    \               \:::\    \      /::::\   \:::\    \   
            /:::/  |::|___|______    /::::::\   \:::\    \               \:::\    \    /::::::\   \:::\    \  
           /:::/   |::::::::\    \  /:::/\:::\   \:::\    \               \:::\    \  /:::/\:::\   \:::\    \ 
          /:::/    |:::::::::\____\/:::/  \:::\   \:::\____\_______________\:::\____\/:::/__\:::\   \:::\____\
          \::/    / ~~~~~/:::/    /\::/    \:::\  /:::/    /\::::::::::::::::::/    /\:::\   \:::\   \::/    /
           \/____/      /:::/    /  \/____/ \:::\/:::/    /  \::::::::::::::::/____/  \:::\   \:::\   \/____/ 
                       /:::/    /            \::::::/    /    \:::\~~~~\~~~~~~         \:::\   \:::\    \     
                      /:::/    /              \::::/    /      \:::\    \               \:::\   \:::\____\    
                     /:::/    /               /:::/    /        \:::\    \               \:::\   \::/    /    
                    /:::/    /               /:::/    /          \:::\    \               \:::\   \/____/     
                   /:::/    /               /:::/    /            \:::\    \               \:::\    \         
                  /:::/    /               /:::/    /              \:::\____\               \:::\____\        
                  \::/    /                \::/    /                \::/    /                \::/    /        
                   \/____/                  \/____/                  \/____/                  \/____/         


## Team Members

|Name|UID|
|----|---|
|WONG, Chor Sing|3035790769|
|JIANG, Nan|3033093349|

## Game Description and Rules

 The player could control the character using the keyboard input to find its way out of the maze. There are five diffculty levels avalible and the maze sizes are larger if the level is higher. The game also provides save and load functions. If the player decides to give up, the system will generate the solution of the maze. The player could also choose to quit the game during playing.

## Features

1. A maze is randomly generated using recursion. It is random since the walls and holes are randomly made using local time as a seed;
2. Vector of Vector of integers will be used to store the maze;
3. The system will record the player's movement by a vector of string. There will be a function to undo the moves;
4. The system will provide the function to save/load the game, including the maze itself and the position history of the player. The player can opt to save the game into a file and quit the system, the file can be reloaded to continue the game;
5. The program will be divided into several files, with headers, game.cpp and main.cpp;
6. Moveable character and the wall of the maze might be decorated with suitable color using ANSI escape sequence. 

## Non-standard libraries
`terminos.h` and `unistd.h` are used for the `readkey()` function in [`main.cpp`](main.cpp). This function is used for reading keyboard input without requiring to press <kbd>Enter</kbd> or <kbd>Return</kbd> to improve user experience. 

## Compilation and Execution Instructions

1. Make sure all files (main.cpp, main.h, game.cpp, game.h, and Makefile) are in the same folder on Linux
2. open the folder in terminal
3. Type `make` to compile the program
4. Type `./main` to start the program
5. If you want to clear unwanted files, you may use the command `make clean`
