#pragma once

#include <random>
#include <string>
#include <vector>

// Structure representing a 2D coordinate of a maze
struct Coord
{
    int y_;
    int x_;
    Coord(const int y = 0, const int x = 0) : y_(y), x_(x) {}
};

// Enumeration representing possible actions on a maze
enum ACTION : int8_t
{
    ILLEGAL = -1,
    RIGHT,
    LEFT,
    DOWN,
    UP,
    MAX,
};

// Changes in a coordinate by an ACTION
constexpr const int DY[ACTION::MAX] = {0, 0, 1, -1}; // In Y-axis
constexpr const int DX[ACTION::MAX] = {1, -1, 0, 0}; // In X-axis

class Maze
{
public:
    // Default constructor
    Maze();

    // Constructor initializing a maze with given parameters
    Maze(const int seed, const int height, const int width, const int endTurn, const int maxPoint);

    // Deconstructor to free allocated memory
    ~Maze();

    // Check if the game is done
    bool IsDone() const;

    // Advance the game state according to the given action
    void Advance(const ACTION action);

    // Get available actions for the current state
    std::vector<ACTION> Actions() const;

    // Convert current game state to string for display
    std::string ToString() const;

private:
    std::mt19937 eng_ = {}; // Random engine

    int h_ = 0; // Height of the maze
    int w_ = 0; // Width of the maze

    int **points_; // Point values for each cell

    int turn_  = 0;
    int score_ = 0;

    int endTurn_  = 0;
    int maxPoint_ = 0;

    Coord player_ = Coord();
};
