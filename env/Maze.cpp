#include <iostream>
#include <random>
#include <string>
#include <sstream>
#include <vector>

#include "Maze.h"

Maze::Maze(const int seed, const int height, const int width, const int endTurn, const int maxPoint)
    : h_(height), w_(width), endTurn_(endTurn), maxPoint_(maxPoint)
{
    eng_ = std::mt19937(seed); // Init random engine with seed
    player_.y_ = eng_() % h_;  // Set player y coordinate
    player_.x_ = eng_() % w_;  // Set player x coordinate

    // Allocate memory for a maze
    points_ = new int *[h_];
    for(int i = 0; i < h_; i++)
    {
        points_[i] = new int[w_];
    }

    // Initialize points randomly
    for (int i = 0; i < h_; i++)
    {
        for (int j = 0; j < w_; j++)
        {
            if (i == player_.y_ && j == player_.x_)
            {
                continue;
            }
            points_[i][j] = eng_() % maxPoint_;
        }
    }
}

// Copy constructor
Maze::Maze(const Maze &other)
{
    h_        = other.h_;
    w_        = other.w_;
    eng_      = other.eng_;
    turn_     = other.turn_;
    score_    = other.score_;
    player_   = other.player_;
    endTurn_  = other.endTurn_;
    maxPoint_ = other.maxPoint_;

    points_ = new int *[h_];
    for (int i = 0; i < h_; i++)
    {
        points_[i] = new int[w_];
        for (int j = 0; j < w_; j++)
        {
            points_[i][j] = other.points_[i][j];
        }
    }
}

// Destructor to free allocated memory
Maze::~Maze()
{
    for (int i = 0; i < h_; i++)
    {
        delete[] points_[i];
    }
    delete[] points_;
}

// Check if the game is done
bool Maze::IsDone() const
{
    return turn_ == endTurn_;
}

// Advance the game state according to the given action
void Maze::Advance(const ACTION action)
{
    if (ACTION::ILLEGAL < action && action < ACTION::MAX)
    {
        player_.y_ += DY[action];
        player_.x_ += DX[action];
        auto &point = points_[player_.y_][player_.x_];
        if (point > 0)
        {
            score_ += points_[player_.y_][player_.x_];
            point = 0; // Set the point value to 0
        }
        turn_++;
    }
}

// Evaluate the game state
Score Maze::Evaluate() const
{
    // Just return the score for now
    return score_;
}

// Get available actions for the current state
std::vector<ACTION> Maze::Actions() const
{
    std::vector<ACTION> actions;
    for (uint8_t action = 0; action < ACTION::MAX; action++)
    {
        int ty = player_.y_ + DY[static_cast<ACTION>(action)];
        int tx = player_.x_ + DX[static_cast<ACTION>(action)];
        if (0 <= ty && ty < h_ && 0 <= tx && tx < w_)
        {
            actions.emplace_back(static_cast<ACTION>(action));
        }
    }
    return actions;
}

// Convert current game state to string for display
std::string Maze::ToString() const
{
    std::stringstream ss;
    ss << "Turn:\t" << turn_ << "\n";
    ss << "Score:\t" << score_ << "\n";
    for (int i = 0; i < h_; i++)
    {
        for (int j = 0; j < w_; j++)
        {
            int point = points_[i][j];
            if (i == player_.y_ && j == player_.x_)
            {
                ss << '@';
            }
            else if (point > 0)
            {
                ss << point;
            }
            else
            {
                ss << '.';
            }
        }
        ss << '\n';
    }
    return ss.str();
}
