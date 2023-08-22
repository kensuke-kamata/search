/* ************************************************************************** */
/*                                                                            */
/* Beam Search Testing                                                      */
/*                                                                            */
/* ************************************************************************** */

// env
#include "Maze.h"
#include "Game.h"

// algo
#include "Greedy.h"
#include "Beam.h"

#include <iostream>

int main(int, char**)
{
    auto algo1 = Search::Greedy();
    auto algo2 = Search::Beam();

    auto score1 = average(algo1, 100, false);
    auto score2 = average(algo2, 100, false);

    using std::cout;
    using std::endl;

    cout << "[Greedy] Average: " << score1 << endl;
    cout << "[Beam]   Average: " << score2 << endl;

    return 0;
}
