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
    /// @param inputArray noisy sample to be filtered by algorithm
    /// @param sampleValue defines the length of the vector
    /// @return returns a filtered sample
    std::vector<float> run(const float *inputArray, size_t sampleValue)
    {
        std::vector<float> filteredDataList;

        for (size_t i = 0; i < sampleValue; i++)
        {

            buffer.push(inputArray[i]);        // Get a new sample and add to buffer
            movingAverageSum += inputArray[i]; // adding the sample to the sum

            if (buffer.size() > windowSize)
            {
                movingAverageSum -= buffer.front(); // Subtract the oldest sample and protects future avg.
                buffer.pop();                       // Remove the oldest sample
            }

            float filteredValue = movingAverageSum / buffer.size(); // calculating the average
            filteredDataList.push_back(filteredValue);
        }

        return filteredDataList;
    }

private:
    int windowSize;
    std::queue<float> buffer;
    float movingAverageSum;
};