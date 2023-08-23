#pragma once

#include "Search.h"
#include <queue>

namespace Search
{
class Beam : public IMaze {
public:
    Beam(const size_t beamDepth = 4, const size_t beamWidth = 2)
        : beamDepth_(beamDepth),
          beamWidth_(beamWidth)
    {
    }

    virtual ~Beam() = default;

    virtual ACTION Search(const Maze &maze) override
    {
        std::priority_queue<Maze> beamNow;
        Maze mazeBest;

        beamNow.push(maze);
        for (size_t i = 0; i < beamDepth_; i++)
        {
            std::priority_queue<Maze> beamNext;
            for (size_t j = 0; j < beamWidth_; j++)
            {
                if (beamNow.empty())
                {
                    break;
                }
                Maze mazeNow = beamNow.top();
                beamNow.pop();
                auto actions = mazeNow.Actions();
                for (const auto action : actions)
                {
                    Maze mazeNext = mazeNow;
                    mazeNext.Advance(action);
                    if (i == 0)
                    {
                        mazeNext.SetAction(action);
                    }
                    beamNext.push(mazeNext);
                }
            }
            beamNow = beamNext;
            mazeBest = beamNow.top();

            if (mazeBest.IsDone())
            {
                break;
            }
        }
        return mazeBest.GetAction();
    }

private:
    size_t beamDepth_;
    size_t beamWidth_;
};
} // namespace Search
