#ifndef GAME_H // game.h is for all the function and algorithm for the maze generation.
#define GAME_H
#include <vector>
#include <string>
#define ROW 0
#define COL 1

#define STATUS_PLAYING 0
#define STATUS_GIVE_UP 1
#define STATUS_FINISHED 2

#define MAP_EMPTY 0
#define MAP_WALL 1
#define MAP_CHECKING 2
#define MAP_PATH 3

using namespace std;
typedef struct Game
{
    vector<vector<int> > * map; //map[row][col]
    int player_pos[2]; //player position       player_pos[ROW],  player_pos[COL]
    int start_pos[2];  //start  position       start_pos[ROW],   start_pos[COL]
    int dest_pos[2];   //destination position  dest_pos[ROW],    dest_pos[COL]
    int map_height;    //number of row
    int map_width;     //number of column
    int status;        //either STATUS_PLAYING, STATUS_GIVE_UP, STATUS_FINISHED
    vector<string> history;
}Game;

void division(Game * game, int x1,int y1,int x2,int y2);
bool solve(Game * game, int x, int y, int w, int h);
Game * createGame(int width, int height);
#endif
