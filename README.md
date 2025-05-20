### Build Instructions for EdgeTech Project:

```
mkdir build 
cd build
cmake ..
make
```

### Run instructions:

```
cd build
./EdgeTechProject [windowSize] [maxSamples] [numSamples] [samplingRateHz] [freqHz]
```

### display.py Dependency Instructions:
```
sudo apt install python3-pip
pip install matplotlib
pip install PyQt5
```

### display.py Run Instructions: 
```
python3 ./display.py
```


### Explaination of implementation approach: 
- The program contains two classes, signalGenerate and averageFilter, to keep objects modular and organized. 
- signalGenerate is the class the contains the function that produces the noisy signal, and averageFilter is the class that contains the function that the moving average filter is stored in. 
- In averageFilter, the queue library was used for it's features, such as .pop or .push. The run function maintains a buffer with the queue of the most recent samples inputted to the function. The sum and the buffer are updated with each input, and the oldest value is removed from the sum and the queue if the windowSize is exceeded. The sum is then divided by the buffer size to calculate the average. The averageFilter function returns a single variable, filteredValue. 
- In the main function, it uses command line interface to obtain the variables and define the signal. 
- The user must input variables: windowSize, maxSamples, numSamples, samplingRateHz, and freqHz. 
- The file outputs to both the terminal and a .csv file. If the user wants the .csv file, it can be found in the build directory, and one can run the display.py file to see an output graph that plots both the noisy signal and the filtered signal against time. 

