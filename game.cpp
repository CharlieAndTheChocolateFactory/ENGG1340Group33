
#include <vector>
#include "game.h"
using namespace std;
void division(Game * game, int x1,int y1,int x2,int y2){
// the maze is generated using recursion, each time two walls, horizontally and veritcally is drawn to divide a cell. 3 holes are then made on 3 sides of the walls.
	if (x2 - x1 == 2) { return; } // cannot be divided into smaller division horizontally
	if (y2 - y1 == 2) { return; } // cannot be divided into smaller division vertically

	int c1 = x1 + 2 + 2 * (rand() % ((x2 - x1 - 2) / 2)); // x1 + 2 = c1 , +2*(rand()%((x2-x1-2)/2)) will force the c1 to be an even number.
	int c2 = y1 + 2 + 2 * (rand() % ((y2 - y1 - 2) / 2));
        //A diagram to illustrate the generation algorithm
		
	        /*
		   +---x1--c1--x2--->x
		   |
		   y1   +---+---+
		   |    | A 1 B |
		   c2   +-2-+-3-+---------Wall A
		   |    | C 0 D |
		   y2   +---+---+
		   |        |
		   v        wall B
		   y
		*/

	for (int i = x1; i <= x2; i++) {
		game->map->at(c2)[i] = 1; // build wall A
	}
	for (int i = y1; i <= y2; i++) {
		game->map->at(i)[c1] = 1; // build wall B
	}
	int c3 = rand() % 4;// 0,1,2,3

/* check the diagram above.
maze[c2][x1 + 1 + 2*(rand()%((c1-x1)/2))]=0; //wall 2 , wall 2 can be long, therefore, a random hole is made.
maze[c2][c1 + 1 + 2*(rand()%((x2-c1)/2))]=0; //wall 3 wall is made on wall 3
maze[c2 + 1 + 2*(rand()%((y2-c2)/2))][c1]=0; //wall 0 wall is made on wall 0
maze[y1 + 1 + 2*(rand()%((c2-y1)/2))][c1]=0; //wall 1 wall is made on wall 1
*/

	if (c3 == 1) {
		game->map->at(c2)[x1 + 1 + 2 * (rand() % ((c1 - x1) / 2))] = 0;
		game->map->at(c2)[c1 + 1 + 2 * (rand() % ((x2 - c1) / 2))] = 0;
		game->map->at(c2 + 1 + 2 * (rand() % ((y2 - c2) / 2)))[c1] = 0;
	} else if (c3 == 2) {
		game->map->at(y1 + 1 + 2 * (rand() % ((c2 - y1) / 2)))[c1] = 0;
		game->map->at(c2)[c1 + 1 + 2 * (rand() % ((x2 - c1) / 2))] = 0;
		game->map->at(c2 + 1 + 2 * (rand() % ((y2 - c2) / 2)))[c1] = 0;
	} else if (c3 == 3) {
		game->map->at(c2)[x1 + 1 + 2 * (rand() % ((c1 - x1) / 2))] = 0;
		game->map->at(y1 + 1 + 2 * (rand() % ((c2 - y1) / 2)))[c1] = 0;
		game->map->at(c2 + 1 + 2 * (rand() % ((y2 - c2) / 2)))[c1] = 0;
	} else {
		game->map->at(c2)[x1 + 1 + 2 * (rand() % ((c1 - x1) / 2))] = 0;
		game->map->at(y1 + 1 + 2 * (rand() % ((c2 - y1) / 2)))[c1] = 0;
		game->map->at(c2)[c1 + 1 + 2 * (rand() % ((x2 - c1) / 2))] = 0;
	}

	division(game, x1, y1, c1, c2); // further divdes the four rooms by recursion.
	division(game, c1, y1, x2, c2);
	division(game, x1, c2, c1, y2);
	division(game, c1, c2, x2, y2);

}
// deep first search is used to solve the maze.
bool solve(Game * game, int row, int col, int w, int h) { // check if we can reach the dest from (x,y)
  //printf("solve(game,row=%d,col=%d,w=%d,h=%d)\n",row,col,w,h);
  if(row<0 || col<0 || row>=h || col>=w) return false; // if out of bound, return false
  vector<vector<int> > * maze = game->map;
	if(maze->at(row)[col]==MAP_PATH){ // we are in the dest, so return true , 2 is defined as the destintation.
		return true;
	}

	maze->at(row)[col]=MAP_CHECKING; // -1 means checking
	for(int i=-1;i<=1;i++) {
		for(int j=-1;j<=1;j++){
			if( row+i<0 || col+j<0 || row+i>=h || col+j>=w ||
                            (i==0 && j==0) /* middle block */||
                            (maze->at(row+i)[col+j]==MAP_WALL) /* wall */||
                            (maze->at(row+i)[col+j]==MAP_CHECKING) /* checking */ ||
                            (i*j!=0) /* none of NESW */ ){
				continue;
			}

			if(solve(game,row+i,col+j,w,h)){
				maze->at(row)[col]=MAP_PATH; // if reachable, the middle is reachable too.
				return true;
			} else { // if reachable, the middle is reachable too.
				 // return false;
			}

		}
	}

  maze->at(row)[col]=MAP_EMPTY;
	return false;
}

Game * createGame(int width, int height) {
  Game * game = new Game();
  game->map_width = width;
  game->map_height = height;
  game->player_pos[ROW] = game->start_pos[ROW] = 0;
  game->player_pos[COL] = game->start_pos[COL] = 1;

  game->map = new vector<vector<int> >();
  for (int i = 0; i < height; i++) {
    vector<int> * row = new vector<int>();
    for (int j = 0; j < width; j++) {
      row->push_back(MAP_EMPTY);
    }
    game->map->push_back(*row);
  }

	for (int i = 0; i < width; i++) { // Frame generation
		game->map->at(0)[i] = MAP_WALL; // Generate top boundary
		game->map->at(height - 1)[i] = MAP_WALL; // Generate bottom boundary
	}
	for (int i = 0; i < height; i++) { // Frame generation
		game->map->at(i)[0] = MAP_WALL; // Generate left boundary
		game->map->at(i)[width - 1] = MAP_WALL; // Generate right boundary
	}


  division(game, 0, 0, game->map_width - 1, game->map_height - 1);
  game->map->at(0)[1] = MAP_EMPTY;
	game->map->at(game->map_height - 1)[game->map_width - 2] = MAP_PATH;
  game->dest_pos[ROW] = game->map_height - 1;
  game->dest_pos[COL] = game->map_width - 2;
  game->history.push_back("0 1");
  return game;
}
