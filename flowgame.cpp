#include "flowgame.h"
#include <cstdlib>
// default constructor generates 8x8 board with random endpoints
FlowGame::FlowGame() {
    board_ = vector<vector<Tile>>(8, vector<Tile>(8, Tile()));
    endpoints_ = vector<Endpoints>(7);
    unsigned int size = board_[0].size();
    for (unsigned int i = 0; i < endpoints_.size(); i++) {
        char x0 = std::rand() % (size*size);
        char y0 = std::rand() % (size*size);
        while(!board_[y0][x0].empty) {
            x0 = std::rand() % (size*size);
            y0 = std::rand() % (size*size);
        }
        board_[y0][x0].empty = false;
        board_[y0][x0].color = i;
        char x1 = std::rand() % (size*size);
        char y1 = std::rand() % (size*size);
        while(!board_[y0][x0].empty) {
            x1 = std::rand() % (size*size);
            y1 = std::rand() % (size*size);
        }
        board_[y1][x1].empty = false;
        board_[y1][x1].color = i;

        endpoints_[i] = Endpoints(x0, y0, x1, y1);
    }
}

//overloaded constructor for special board sizes
FlowGame::FlowGame(int gamesize, int numcolors) {
    board_ = vector<vector<Tile>>(gamesize, vector<Tile>(gamesize, Tile()));
    endpoints_ = vector<Endpoints>(numcolors);
    unsigned int size = board_[0].size();
    for (unsigned int i = 0; i < endpoints_.size(); i++) {
        char x0 = std::rand() % (size*size);
        char y0 = std::rand() % (size*size);
        while(!board_[y0][x0].empty) {
            x0 = std::rand() % (size*size);
            y0 = std::rand() % (size*size);
        }
        board_[y0][x0].empty = false;
        board_[y0][x0].color = i;
        char x1 = std::rand() % (size*size);
        char y1 = std::rand() % (size*size);
        while(!board_[y0][x0].empty) {
            x1 = std::rand() % (size*size);
            y1 = std::rand() % (size*size);
        }
        board_[y1][x1].empty = false;
        board_[y1][x1].color = i;

        endpoints_[i] = Endpoints(x0, y0, x1, y1);
    }
}

// runs Astar on the current board 
void solveGame() {

}