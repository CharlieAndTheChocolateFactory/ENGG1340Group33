#ifndef MAIN_H // main.h to store all the definition and function headers.
#define MAIN_H

#define ROW 0
#define COL 1

#define STATUS_PLAYING 0
#define STATUS_GIVE_UP 1
#define STATUS_FINISHED 2
#define STATUS_QUIT 3

#define MAP_EMPTY 0
#define MAP_WALL 1
#define MAP_CHECKING 2
#define MAP_PATH 3

#include "game.h"
using namespace std;


void main_menu();
void start_game();
void tutorial();
void about();
void exit_screen();
void show_maze(Game *game, bool show_bar);
void next_step(Game *game);
void save_game(Game *game);
void load_game();
void game_loop(Game *game);

#endif
