#pragma once

#include <chrono>

class Timer
{
public:
    // Constructor
    Timer(const int64_t &threshold)
        : start_(std::chrono::high_resolution_clock::now()),
          threshold_(threshold)
    {
    }

   bool IsOver() const
   {
        auto elapsed = std::chrono::high_resolution_clock::now() - start_;
        return std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count() >= threshold_;
   }

private:
    std::chrono::high_resolution_clock::time_point start_;
    int64_t threshold_; // ms
};
