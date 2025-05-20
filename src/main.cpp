#include <iostream>
#include <fstream>
#include "averageFilter.hpp"
#include "signalGenerate.hpp"
#include <cstdlib>
#include <thread>
#include <chrono>
using namespace std::chrono;
using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 6) // If improper number of command line arguments, send user message
    {
        std::cout << "Usage incorrect: ./EdgeTechProject [windowSize] [maxSamples] [numSamples] [samplingRateHz] [freqHz]" << endl;

        return 1;
    }

    // Getting data from terminal inputs
    int windowSize = std::stoi(argv[1]);
    const size_t maxSamples = std::stoi(argv[2]);
    int numSamples = std::stoi(argv[3]);
    float samplingRateHz = std::stof(argv[4]);
    float freqHz = std::stof(argv[5]);
    int period = (1.0 / samplingRateHz) * 1000;
    float signal[maxSamples];

    auto startTimeStamp = high_resolution_clock::now(); // Beginning the clock that times each instance for the variable timeStamp

    signalGenerate generate; // Constructor of signalGenerate
    generate.generateNoisySignal(signal, maxSamples, numSamples, samplingRateHz, freqHz);

    averageFilter movingFilter(windowSize); // Declaring an instance of object and passing windowSize

    std::ofstream csvFile("Output.csv"); // Open file to write CSV
    if (!csvFile.is_open())              // If the file can't open, send message to user
    {
        std::cout << "CSV file couldn't be opened." << std::endl;
        return 1;
    }

    for (size_t i = 0; i < numSamples; i++)
    {
        float filteredData = movingFilter.run(signal[i]); // Applying moving average filter onto noisy data set

        auto stopTimeStamp = high_resolution_clock::now();                                      // Getting time to calculate each instance of timeStamp
        auto calculatedTimeStamp = duration_cast<milliseconds>(stopTimeStamp - startTimeStamp); // Getting milliseconds for decimal point
        double timeStamp = static_cast<double>(calculatedTimeStamp.count()) / 1000.0;           // casting to a double and converting to seconds

        std::cout << timeStamp << ", " << signal[i] << ", " << filteredData << endl; // print to terminal
        csvFile << timeStamp << ", " << signal[i] << ", " << filteredData << endl;   // print to .csv file

        std::this_thread::sleep_for(std::chrono::milliseconds(period)); // delaying by the period
    }
    csvFile.close();
    return 0;
}
