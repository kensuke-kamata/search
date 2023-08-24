#pragma once

#include "Search.h"
#include "Timer.h"
#include <queue>
#include <vector>

namespace Search
{
class Beams : public IMaze {
public:
    Beams(const uint64_t beamWidth = 2, const uint64_t beamDepth = 4, const int64_t threshold = 1)
        : beamWidth_(beamWidth),
          beamDepth_(beamDepth),
          threshold_(threshold)
    {
    }

    virtual ~Beams() = default;

    virtual ACTION Search(const Maze &maze) override
    {
        // Maintain a priority queue at each depth (the number of steps from the state)
        // to hold states in order of their scores
        auto beams = std::vector<std::priority_queue<Maze>>(beamDepth_ + 1);
        for (uint64_t i = 0; i < beamDepth_ + 1; i++)
        {
            beams[i] = std::priority_queue<Maze>();
        }
        beams[0].push(maze);

        auto timer = Timer(threshold_);
        while (!timer.IsOver())
        {
            for (uint64_t i = 0; i < beamDepth_; i++)
            {
                auto &beamNow  = beams[i];
                auto &beamNext = beams[i + 1];
                for (uint64_t j = 0; j < beamWidth_; j++)
                {
                    if (beamNow.empty())
                    {
                        break;
                    }
                    Maze mazeNow = beamNow.top();
                    if (mazeNow.IsDone())
                    {
                        break;
                    }
                    beamNow.pop();
                    auto actions = mazeNow.Actions();
                    for (auto action : actions)
                    {
                        Maze mazeNext = mazeNow;
                        mazeNext.Advance(action);
                        if (i == 0)
                        {
                            // Keep the action as a candidate that can be taken
                            mazeNext.SetAction(action);
                        }
                        beamNext.push(mazeNext);
                    }
                }
            }
        }

        for (int i = beamDepth_; i >=0; i--)
        {
            const auto &beamNow = beams[i];
            if (!beamNow.empty())
            {
                return beamNow.top().GetAction();
            }
        }

        return ACTION::ILLEGAL;
    }

private:
    uint64_t beamWidth_;
    uint64_t beamDepth_;
    int64_t  threshold_;
};
} // namespace Search
