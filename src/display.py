import matplotlib.pyplot as plt
import csv 

timeStamp = []
filteredOutput = []
rawOutput = [] 

with open('../build/Output.csv', 'r') as csvfile: #Reading CSV File 
    plots = csv.reader(csvfile, delimiter = ',')

    for row in plots:  
        timeStamp.append(float(row[0]))
        filteredOutput.append(float(row[1]))
        rawOutput.append(float(row[2])) 

    plt.plot(timeStamp, filteredOutput)
    plt.plot(timeStamp, rawOutput) #Plotting both variables against Time 

    plt.xlabel('Time Stamp')
    plt.ylabel('Raw Output/Filtered Output')    
    plt.title('Graphed Moving Average Filter', fontsize = 20) 
    plt.grid()
    plt.show() 
