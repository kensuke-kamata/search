#pragma once

#include "Search.h"

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
        // auto size = actions.size();
        // if (size <= 0)
        // {
        //     return ACTION::ILLEGAL;
        // }

        auto bestScore = -max_;
        auto bestAction = ACTION::ILLEGAL;
        for (const auto action : actions)
        {
            auto now = maze;
            // now.Adv
            (void)now;
            (void)action;
        }
        (void)bestScore;

        // return actions[eng_()n% size];
        return bestAction;
    }

private:
    const Score max_ = 1000000000000LL;
};
} // namespace Search
