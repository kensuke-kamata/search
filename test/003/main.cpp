/* ************************************************************************** */
/*                                                                            */
/* Beams Search Testing                                                      */
/*                                                                            */
/* ************************************************************************** */

// env
#include "Maze.h"
#include "Game.h"

// algo
#include "Beam.h"
#include "Beams.h"

#include <iostream>

int main(int, char**)
{
    const int END_TURN = 100;
    // // Width: 5, Threshold: 10 ms
    auto algo1 = Search::Beam(5, 10);
    // // Width: 1, Depth: 100, Threshold: 10 ms
    auto algo2 = Search::Beams(1, END_TURN, 10);

    auto score1 = average(algo1, 100, 30, 30, END_TURN, false);
    auto score2 = average(algo2, 100, 30, 30, END_TURN, false);

    using std::cout;
    using std::endl;

    cout << "[Beam]  Average: " << score1 << endl;
    cout << "[Beams] Average: " << score2 << endl;

    return 0;
}
