/* ************************************************************************** */
/*                                                                            */
/* Greedy Search Testing                                                      */
/*                                                                            */
/* ************************************************************************** */

// env
#include "Maze.h"
#include "Game.h"

// algo
#include "Random.h"
#include "Greedy.h"

#include <iostream>
#include <random>

int main(int, char**)
{
    std::random_device gen;
    std::mt19937 eng(gen());

    auto algo1 = Search::Random(static_cast<int>(eng()));
    auto algo2 = Search::Greedy();

    auto score1 = average(algo1, 100, false);
    auto score2 = average(algo2, 100, false);

    using std::cout;
    using std::endl;

    cout << "[Random] Average: " << score1 << endl;
    cout << "[Greedy] Average: " << score2 << endl;

    return 0;
}
