#pragma once
#include <vector>
#include <iostream>
#include "dsets.h"

using namespace std;

class FlowGame
{
    struct Tile {
        bool empty;
        bool endpoint;
        char color;
    };
public:
    FlowGame();
    FlowGame(int gamesize);
    void solveGame();
private:
    unsigned int game_size_;
    vector<vector<Tile>> board_;
};