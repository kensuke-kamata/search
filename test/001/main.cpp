/* ************************************************************************** */
/*                                                                            */
/* Greedy Search Testing                                                      */
/*                                                                            */
/* ************************************************************************** */

// env
#include "Maze.h"
#include "Game.h"

// algo
#include "Greedy.h"

int main(int, char**)
{
    auto maze = Maze();
    auto algo = Search::Greedy();

    play(maze, algo);

    return 0;
}
