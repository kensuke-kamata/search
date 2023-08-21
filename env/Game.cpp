#include <iostream>
#include <cassert>

#include "Game.h"

void play(Maze &maze, Search::IMaze &algo)
{
    using std::cout;
    using std::endl;

    cout << maze.ToString() << endl;
    while (!maze.IsDone())
    {
        auto action = algo.Search(maze);
        assert(action != ACTION::ILLEGAL);
        maze.Advance(action);
        cout << maze.ToString() << endl;
    }
}
