#pragma once

#include "Search.h"
#include "Timer.h"
#include <queue>

namespace Search
{
class Beam : public IMaze {
public:
    Beam(const uint64_t beamWidth = 2, const int64_t threshold = 1)
        : beamWidth_(beamWidth),
          threshold_(threshold)
    {
    }

    virtual ~Beam() = default;

    virtual ACTION Search(const Maze &maze) override
    {
        Maze mazeBest;

        std::priority_queue<Maze> beamNow;
        beamNow.push(maze);

        auto timer = Timer(threshold_);
        for (uint64_t i = 0;; i++)
        {
            std::priority_queue<Maze> beamNext;
            for (uint64_t j = 0; j < beamWidth_; j++)
            {
                if (timer.IsOver())
                {
                    return mazeBest.GetAction();
                }
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
    uint64_t beamWidth_;
    int64_t  threshold_;
};
} // namespace Search
