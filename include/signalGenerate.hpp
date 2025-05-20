#pragma once
#include <cmath>
#include <random>
#include <chrono>

// Function provided by EdgeTech Software Development Team

class signalGenerate
{
public:
    const double PI = 3.14159265358979323846;

    void generateNoisySignal(float *signalPtr, size_t maxSamples, size_t numSamples, float samplingRateHz, float freqHz)
    {
        if (numSamples > maxSamples || signalPtr == nullptr || samplingRateHz <= 0)
        {
            return;
        }

        std::default_random_engine generator(
            static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count()));
        std::normal_distribution<float> noiseDist(0.0f, 0.2f);

        float time = 0;
        float signal = 0;
        float noisySample = 0;
        for (size_t i = 0; i < numSamples; ++i)
        {
            time = static_cast<float>(i) / samplingRateHz;
            signal = std::sin(2.0f * static_cast<float>(PI) * freqHz * time);
            noisySample = signal + noiseDist(generator);
            signalPtr[i] = noisySample;
        }
    }
};
