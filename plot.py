import numpy as np
import matplotlib.pyplot as plt

# Read data from a file
filename = 'm_temp.py'
data = np.loadpy(filename)

# Plotting the histogram
plt.hist(data, bins=10, edgecolor='black')  # Adjust the number of bins as needed

# Adding labels and title
plt.xlabel('Value')
plt.ylabel('Frequency')
plt.title('Histogram from File')

# Display the plot
plt.show()
