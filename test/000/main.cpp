/* ************************************************************************** */
/*                                                                            */
/* Random Search Testing                                                      */
/*                                                                            */
/* ************************************************************************** */

// env
#include "Maze.h"
#include "Game.h"

// algo
#include "Random.h"

int main(int, char**)
{
    auto maze = Maze();
    auto algo = Search::Random(0);

    play(maze, algo);

    return 0;
}
