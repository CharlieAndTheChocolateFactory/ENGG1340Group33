#include <iostream>
#include <fstream>
#include <vector>
#include <termios.h>
#include <unistd.h>
#include <string>
#include <sstream>
#include <iomanip>
#include "main.h"
#include "game.h"
using namespace std;

char ansi_reset[] = "\033[40m\033[37m";
char cls[] = "\033[2J\033[0;0H\033[40m\033[37m";
////////BELOW FUNCTION MODIFIED FROM https://stackoverflow.com/questions/1798511/how-to-avoid-pressing-enter-with-getchar
int readkey() {
    int c;
    static struct termios oldt, newt;
    /*tcgetattr gets the parameters of the current terminal
    STDIN_FILENO will tell tcgetattr that it should write the settings
    of stdin to oldt*/
    tcgetattr(STDIN_FILENO, &oldt);
    /*now the settings will be copied*/
    newt = oldt;
    /*ICANON normally takes care that one line at a time will be processed
    that means it will return if it sees a "\n" or an EOF or an EOL*/
    newt.c_lflag &= ~(ICANON | ECHO);
    /*Those new settings will be set to STDIN
    TCSANOW tells tcsetattr to change attributes immediately. */
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    c = getchar();
    /*restore the old settings*/
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return c;
}
////////ABOVE FUNCTION MODIFIED FROM https://stackoverflow.com/questions/1798511/how-to-avoid-pressing-enter-with-getchar


int main() {
  	srand(time(NULL));
    cout << "\033[40m";
    main_menu();
    return 0;
}

void main_menu() {
  while (true) { //keep looping, until exit(0) is called in exit_screen()
    char c = 0;
    bool err = false;
    while (c < '1' || c > '3') {
      cout << cls <<endl;//clear screen
      cout << "\033[38;5;46m           _____                    _____                    _____                    _____          "<<endl; // ASICII art at the beginning of the game.
      cout << "\033[38;5;47m          /\\    \\                  /\\    \\                  /\\    \\                  /\\    \\         "<<endl;
      cout << "\033[38;5;48m         /::\\____\\                /::\\    \\                /::\\    \\                /::\\    \\        "<<endl;
      cout << "\033[38;5;49m        /::::|   |               /::::\\    \\               \\:::\\    \\              /::::\\    \\       "<<endl;
      cout << "\033[38;5;50m       /:::::|   |              /::::::\\    \\               \\:::\\    \\            /::::::\\    \\      "<<endl;
      cout << "\033[38;5;51m      /::::::|   |             /:::/\\:::\\    \\               \\:::\\    \\          /:::/\\:::\\    \\     "<<endl;
      cout << "\033[38;5;87m     /:::/|::|   |            /:::/__\\:::\\    \\               \\:::\\    \\        /:::/__\\:::\\    \\    "<<endl;
      cout << "\033[38;5;123m    /:::/ |::|   |           /::::\\   \\:::\\    \\               \\:::\\    \\      /::::\\   \\:::\\    \\   "<<endl;
      cout << "\033[38;5;159m   /:::/  |::|___|______    /::::::\\   \\:::\\    \\               \\:::\\    \\    /::::::\\   \\:::\\    \\  "<<endl;
      cout << "\033[38;5;195m  /:::/   |::::::::\\    \\  /:::/\\:::\\   \\:::\\    \\               \\:::\\    \\  /:::/\\:::\\   \\:::\\    \\ "<<endl;
      cout << "\033[38;5;231m /:::/    |:::::::::\\____\\/:::/  \\:::\\   \\:::\\____\\_______________\\:::\\____\\/:::/__\\:::\\   \\:::\\____\\"<<endl;
      cout << "\033[38;5;230m \\::/    / ~~~~~/:::/    /\\::/    \\:::\\  /:::/    /\\::::::::::::::::::/    /\\:::\\   \\:::\\   \\::/    /"<<endl;
      cout << "\033[38;5;229m  \\/____/      /:::/    /  \\/____/ \\:::\\/:::/    /  \\::::::::::::::::/____/  \\:::\\   \\:::\\   \\/____/ "<<endl;
      cout << "\033[38;5;228m              /:::/    /            \\::::::/    /    \\:::\\~~~~\\~~~~~~         \\:::\\   \\:::\\    \\     "<<endl;
      cout << "\033[38;5;227m             /:::/    /              \\::::/    /      \\:::\\    \\               \\:::\\   \\:::\\____\\    "<<endl;
      cout << "\033[38;5;226m            /:::/    /               /:::/    /        \\:::\\    \\               \\:::\\   \\::/    /    "<<endl;
      cout << "\033[38;5;190m           /:::/    /               /:::/    /          \\:::\\    \\               \\:::\\   \\/____/     "<<endl;
      cout << "\033[38;5;154m          /:::/    /               /:::/    /            \\:::\\    \\               \\:::\\    \\         "<<endl;
      cout << "\033[38;5;118m         /:::/    /               /:::/    /              \\:::\\____\\               \\:::\\____\\        "<<endl;
      cout << "\033[38;5;82m         \\::/    /                \\::/    /                \\::/    /                \\::/    /        "<<endl;
      cout << "\033[38;5;46m          \\/____/                  \\/____/                  \\/____/                  \\/____/         "<<endl;
      cout << ansi_reset <<endl;
      cout << "Creators: WONG Chor Sing, JIANG Nan"                                        << endl;
      cout << "Welcome to maze!"                                                           << endl;
      cout << "A random maze is generated each time you play this game."                   << endl;
      cout << "You can use keyboard inputs to control the character and find your way out." << endl;
      cout << "There are five diffculties available."                                       << endl;
      cout << "You can press 'o' to save your game and reload it later in the home page."  << endl;
      cout << "If you want to quit the current maze, just press 'q'."                      << endl;
      cout << "If you want to give up and generate solution, just press 'g'."                  << endl;
      cout << "Good luck and enjoy!"                                                       << endl;
      cout << endl;
      cout << "=====MAIN MENU====="          << endl;
      cout << "1. Start New Game"            << endl;
      cout << "2. Load Game"                 << endl;
      cout << "3. Exit"                      << endl;
      cout << (err ? "[Invalid input]" : "") <<endl;
      cout << "Please input 1-3: ";
      cin >> c;
      readkey(); //remove the enter key pressed from the stdin buffer
      err = true;
    }
    if (c == '1') {
        start_game();
    } else if (c == '2') {
        load_game();
    } else if (c == '3') {
        exit_screen();
    }
  }
}
void game_loop(Game * game){
  game->status = STATUS_PLAYING;

  while (game->status == STATUS_PLAYING) {
      show_maze(game,true);
      next_step(game);
  }
  if(game->status == STATUS_FINISHED){
    cout << cls <<endl;//clear screen
    cout << "\033[38;5;196m    ___                            _         _       _   _             " <<endl; // once the player win the game, the screen will show the ASICII art.
    cout << "\033[38;5;202m   / __\\___  _ __   __ _ _ __ __ _| |_ _   _| | __ _| |_(_) ___  _ __  " <<endl;
    cout << "\033[38;5;208m  / /  / _ \\| '_ \\ / _` | '__/ _` | __| | | | |/ _` | __| |/ _ \\| '_ \\ " <<endl;
    cout << "\033[38;5;214m / /__| (_) | | | | (_| | | | (_| | |_| |_| | | (_| | |_| | (_) | | | |" <<endl;
    cout << "\033[38;5;220m \\____/\\___/|_| |_|\\__, |_|  \\__,_|\\__|\\__,_|_|\\__,_|\\__|_|\\___/|_| |_|" <<endl;
    cout << "\033[38;5;226m                   |___/                                               " <<endl;
    cout << endl;
    cout << "Congratulations! You have successfully found the way out!" << endl;
    cout << "Press any key to back to main menu." << ansi_reset <<endl;
    readkey();
  }else if(game->status == STATUS_GIVE_UP){//GIVE UP
    cout << cls <<endl;//clear screen
    solve(game, game->start_pos[ROW], game->start_pos[COL], game->map_width, game->map_height);
    show_maze(game, false);
    cout << "Here is the solution, press any key to back to main menu." <<endl;
    readkey();
  }else if(game->status == STATUS_QUIT){
    //do nothing
  }
}
void start_game(){

  Game * game = NULL;
      char c = 0;
      bool err = false;
      while (c < '1' || c > '5') {
          cout << cls << endl;//clear screen
          cout << "=====GAME LEVEL====="         << endl; //the user will input a no. to decide the diffculty of the game.
          cout << "1. Very Easy"                 << endl;
          cout << "2. Easy"                      << endl;
          cout << "3. Medium"                    << endl;
          cout << "4. Hard"                      << endl;
          cout << "5. Impossible"                << endl;
          cout << (err ? "[Invalid input]" : "") << endl;
          cout << "Please input 1-5: ";
          cin >> c;
          cout << c << endl;
          err = true;
      }
      if (c == '1') { //the size of the maze varies with different diffculties. depends on input c.
        game = createGame(11,11);
      } else if (c == '2') {
        game = createGame(21,21);
      } else if (c == '3') {
        game = createGame(31,31);
      } else if (c == '4') {
        game = createGame(41,41);
      } else if (c == '5') {
        game = createGame(51,51);
      }
      game_loop(game);

}

void show_maze(Game *game, bool show_bar) {
    cout << cls <<endl;//clear screen
    cout << "   START HERE "<<endl;
  	cout << "   \u2193"<<endl;
    for (int i = 0; i < game->map_height; i++) {
      for (int j = 0; j < game->map_width; j++) {
        if (game->player_pos[ROW] == i && game->player_pos[COL] == j) {
          cout << "\033[45m  ";
        } else {
          cout << (game->map->at(i)[j] == MAP_WALL?"\033[47m  ":(game->map->at(i)[j] == MAP_PATH?"\033[46m  ":"\033[40m  "));
        }
      }
      cout << ansi_reset << endl;
    }
    cout << std::setfill(' ') << std::setw((game->map_width) * 2) << "\u2193" << endl; // add start and exit with arrow.
    cout << std::setfill(' ') << std::setw((game->map_width) * 2) << "EXIT" << endl;
    cout << ansi_reset << endl;
    if(show_bar){
      cout << endl;
      cout << "\033[47;91mA \033[30mLeft  \033[91mS \033[30mDown  \033[91mW \033[30mUp  \033[91mD \033[30mRight\033[91m  \033[91mO \033[30mSave\033[91m  \033[91mZ \033[30mUndo\033[91m  \033[91mG\033[30m Give up  \033[91mQ\033[30m Quit  " << ansi_reset << endl;
    } // control discription is added. with escape character.
}

void next_step(Game *game) {
    int c = readkey();

    int old_player_pos[] = {game->player_pos[ROW], game->player_pos[COL]};
    //cout << c << endl;
    if (c == 'o') {
        save_game(game);
        cout << "Saved. Press any key to continue." <<endl;
        readkey();
        return;
    } else if (c == 'g') {
        game->status = STATUS_GIVE_UP;
        return;
    }else if (c == 'q') {
        game->status = STATUS_QUIT;
        return;
    } else if (c == 'z') {
        if (game->history.size() > 0) {
          string s = game->history.back();
          game->history.pop_back();
          istringstream stream1(s);
          stream1 >> game->player_pos[ROW];
          stream1 >> game->player_pos[COL];
        }
        return;
    } else if (c == 'w') { // move up
        game->player_pos[ROW]--;
    } else if (c == 'a') { // move left
        game->player_pos[COL]--;
    } else if (c == 's') { // move down
        game->player_pos[ROW]++;
    } else if (c == 'd') { // move right
        game->player_pos[COL]++;
    }
    if (game->player_pos[ROW] < 0 || game->player_pos[COL] < 0 //to prevent the player go out-of-bound.
       || game->player_pos[ROW] >= game->map_height ||  game->player_pos[COL] >= game->map_width
       || game->map->at(game->player_pos[ROW])[game->player_pos[COL]] == MAP_WALL) { // to prevent the player pass through the wall
      game->player_pos[ROW] = old_player_pos[ROW];
      game->player_pos[COL] = old_player_pos[COL];
    }
    else {
      string s = to_string(game->player_pos[ROW]) + ' ' + to_string(game->player_pos[COL]);
      game->history.push_back(s);
    } // store player position to vector globally,

    if (game->player_pos[ROW] == game->dest_pos[ROW] && game->player_pos[COL] == game->dest_pos[COL]) {

      game->status=STATUS_FINISHED;

    }
}

void save_game(Game *game) {
    ofstream myfile; // the game is saved into a file called save.txt and to be loaded later.
    myfile.open ("save.txt");
    myfile << game->map_width     << "\n";
    myfile << game->map_height    << "\n";
    myfile << game->player_pos[ROW] << "\n";
    myfile << game->player_pos[COL] << "\n";
    myfile << game->start_pos[ROW]  << "\n";
    myfile << game->start_pos[COL]  << "\n";
    myfile << game->dest_pos[ROW]   << "\n";
    myfile << game->dest_pos[COL]   << "\n";
    myfile << game->status        << "\n"; // add the information including the player's position, and the map sized is stored.
    for (int i = 0; i < game->map_height; i++) {
        vector<int> v = game->map->at(i);
        for (int j = 0; j < game->map_width; j++) {
          myfile << v[j] << " "; // use loop to store the inner wall of the maze.
        }
        myfile << "\n";
    }
    for (string s : game->history) {
      myfile << s << "\n";
    }
    myfile.close();
}

void load_game(){

  ifstream file ("save.txt"); // read the save.txt files to reload the game with player position and the map.
  if(!file.good()){
      cout << "No save file detected, press any key to back to main menu." << endl;
      readkey();
      return;
  }
  Game * game = new Game();
  file >> game->map_width;
  file >> game->map_height;
  file >> game->player_pos[ROW];
  file >> game->player_pos[COL];
  file >> game->start_pos[ROW];
  file >> game->start_pos[COL];
  file >> game->dest_pos[ROW];
  file >> game->dest_pos[COL];
  file >> game->status;

  game->map = new vector<vector<int> >();
  for (int i = 0; i < game->map_height; i++) { // use loop to create the inner walls of the maps
    vector<int> * row = new vector<int>();
    for (int j = 0; j < game->map_width; j++) {
      int e; //load the map entity.
      file >> e;
      row->push_back(e);
    }
    game->map->push_back(*row);
  }

  string line;
  while (getline(file, line))
  {
    game->history.push_back(line);
  }

  game_loop(game);
}

void exit_screen(){
    cout << "Thank you for playing this game, good bye!" << endl;
    exit(0);
}
