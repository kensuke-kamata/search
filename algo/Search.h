#pragma once

#include "Maze.h"

namespace Search
{
class IMaze {
public:
    virtual ~IMaze() = default;
    virtual ACTION Search(const Maze &maze) = 0;
};
} // namespace Search
