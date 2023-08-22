#pragma once

#include <cassert>
#include <iostream>
#include <random>

#include "Maze.h"
#include "Search.h"

void debug(Maze &maze, bool verbose)
{
    using std::cout;
    using std::endl;

    if (verbose)
    {
        cout << maze.ToString() << endl;
    }
}

void play(Maze &maze, Search::IMaze &algo, bool verbose = false)
{
    debug(maze, verbose);

    while (!maze.IsDone())
    {
        auto action = algo.Search(maze);
        assert(action != ACTION::ILLEGAL);
        maze.Advance(action);

        debug(maze, verbose);
    }
}

double average(Search::IMaze &algo, int n, bool verbose = false)
{
    std::random_device gen;
    std::mt19937 eng(gen());
    Score score = 0;
    for (int i = 0; i < n; i++)
    {
        auto maze = Maze(static_cast<int>(eng()));
        play(maze, algo, verbose);
        score += maze.Evaluate();
    }
    return static_cast<double>(score / n);
}
