#pragma once

#include "Search.h"

namespace Search
{
class Random : public IMaze {
public:
    Random(const int seed)
    {
        eng_ = std::mt19937(seed);
    }

    virtual ~Random() = default;

    virtual ACTION Search(const Maze &maze) override
    {
        auto actions = maze.Actions();
        auto size = actions.size();
        if (size <= 0)
        {
            return ACTION::ILLEGAL;
        }
        return actions[eng_() % size];
    }

private:
    std::mt19937 eng_ = {};
};
} // namespace Search
