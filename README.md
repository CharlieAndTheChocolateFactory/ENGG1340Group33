# ENGG1340Group33
Team Members

Wong Chor Sing UID: 3035790769
Jiang Nan UID:3033093349

Game Description

  This game is called "Mini MTR". It's a simplified version of the game "Mini Metro". 
  In this game, players can design their own MTR network and aim for a higher efficiency to transport passengers inside Hong Kong. The game will include symbols from the ASCII table to create simplified graphics to visualize the MTR network created by the player.
  
Game Rules
  
  Upon the beginning of the game, the player will be given a certain amount of money as his initial budget to construct the MTR network. The income then comes from delivering passengers, who have to pay the fare according to the travel distance between the origin and their target destinations. Meanwhile, building new lines, constructing tunnels, managing stations as well as trains all cost money. The target of the game is to keep a positive net income and avoid bankruptcy.
  
List of Features

  1. Stations: Stations will represent the functions of the corresponding regions, the latter will be catagorized into different types, for example, residential areas or business areas. The stations will pop up in a random order gradually from the city center to the outskirts. They will be named as a letter plus a number, for example, "R4" stands for a station in the residential area number 4.
  2. Passengers: The passengers will go to a station that is located in a region of a different function than the current region they are in. The destination of the passengers will be randomly generated with observation to the rule. 
  3. Lines: The player need to pay certain amount of money to build a line. He can also input the name for the line which is to be stored in an array.
  4. General: Stations, passengers and lines will be considered as different structs (classes) and stored in separated files. The player can input keywords to add or delete lines, connect new stations to lines, etc. Of course, when no new changes need to be made, the player can simply input "continue" so that the MTR system will continue to function for a certain time period before pausing again to output the current status and wait for the prompt of the player. The map, stations and lines will be drawn using symbols, for example:

    A3-----C1-----D1
                   |
                   |
                   E1-----A2
