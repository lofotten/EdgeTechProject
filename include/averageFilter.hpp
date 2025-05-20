#pragma once
#include <queue>

class averageFilter
{
public:
    /// @brief A moving average filter with a fixed window size
    /// @param windowUserSize defines the number of elements inside the moving average filter.
    averageFilter(int windowUserSize)
    {
        windowSize = windowUserSize; // assigning variable from user input
        movingAverageSum = 0;        // Initializes movingAverageSum
    }

    /// @brief processes a sample and returns a filtered sample
    /// @param inputNoisySample noisy sample to be filtered by algorithm
    /// @return returns a filtered sample
    float run(float inputNoisySample)
    {
        buffer.push(inputNoisySample);        // Get a new sample and add to buffer
        movingAverageSum += inputNoisySample; // adding the sample to the sum

        if (buffer.size() > windowSize)
        {
            movingAverageSum -= buffer.front(); // Subtract the oldest sample and protects future avg.
            buffer.pop();                       // Remove the oldest sample
        }

        float filteredValue = movingAverageSum / buffer.size(); // calculating the average

        return filteredValue;
    }

private:
    int windowSize;
    std::queue<float> buffer;
    float movingAverageSum;
};