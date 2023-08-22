#pragma once

#include "Search.h"
#include <iostream>

namespace Search
{
class Greedy : public IMaze {
public:
    Greedy()
    {
    }

    virtual ~Greedy() = default;

    virtual ACTION Search(const Maze &maze) override
    {
        auto actions = maze.Actions();

        auto bestScore  = -max_;
        auto bestAction = ACTION::ILLEGAL;
        for (const auto action : actions)
        {
            auto now = maze;
            now.Advance(action);
            auto score = now.Evaluate();
            if (score > bestScore)
            {
                bestScore = score;
                bestAction = action;
            }
        }
        return bestAction;
    }

private:
    const Score max_ = 1000000000000LL;
};
} // namespace Search
