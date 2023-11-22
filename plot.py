import numpy as np
import matplotlib.pyplot as plt
from m_temp1 import yy1
from m_temp2 import yy2
from m_temp3 import yy3
from m_temp4 import yy4
from m_temp5 import yy5
from m_temp6 import yy6

# Plot histograms together
plt.hist(yy1, bins=range(16), align='left', rwidth=0.8, alpha=0.5, label='Test 1')
plt.hist(yy2, bins=range(16), align='left', rwidth=0.8, alpha=0.5, label='Test 2')
plt.hist(yy3, bins=range(16), align='left', rwidth=0.8, alpha=0.5, label='Test 3')

plt.xlabel('Number of Hits')
plt.ylabel('Occurrences')
plt.title('Histogram of Hits')
plt.legend() 
plt.show()

# Plot histograms together
plt.hist(yy4, bins=range(16), align='left', rwidth=0.8, alpha=0.5, label='Test 4')
plt.hist(yy5, bins=range(16), align='left', rwidth=0.8, alpha=0.5, label='Test 5')
plt.hist(yy6, bins=range(16), align='left', rwidth=0.8, alpha=0.5, label='Test 6')

plt.xlabel('Number of Hits')
plt.ylabel('Occurrences')
plt.title('Histogram of Hits')
plt.legend() 
plt.show()

# Plot the histogram for test1
plt.figure(figsize=(8, 6))
plt.hist(yy1, bins=range(16), align='left', rwidth=0.8)
plt.xlabel('Number of Hits')
plt.ylabel('Occurrences')
plt.title('Histogram of Hits - Test 1')
plt.show()

# Plot the histogram for test2
plt.figure(figsize=(8, 6))
plt.hist(yy2, bins=range(16), align='left', rwidth=0.8)
plt.xlabel('Number of Hits')
plt.ylabel('Occurrences')
plt.title('Histogram of Hits - Test 2')
plt.show()

# Plot the histogram for test3
plt.figure(figsize=(8, 6))
plt.hist(yy3, bins=range(16), align='left', rwidth=0.8)
plt.xlabel('Number of Hits')
plt.ylabel('Occurrences')
plt.title('Histogram of Hits - Test 3')
plt.show()

# Plot the histogram for test4
plt.figure(figsize=(8, 6))
plt.hist(yy4, bins=range(16), align='left', rwidth=0.8)
plt.xlabel('Number of Hits')
plt.ylabel('Occurrences')
plt.title('Histogram of Hits - Test 4')
plt.show()


# Plot the histogram for test5
plt.figure(figsize=(8, 6))
plt.hist(yy5, bins=range(16), align='left', rwidth=0.8)
plt.xlabel('Number of Hits')
plt.ylabel('Occurrences')
plt.title('Histogram of Hits - Test 5')
plt.show()


# Plot the histogram for test6
plt.figure(figsize=(8, 6))
plt.hist(yy6, bins=range(16), align='left', rwidth=0.8)
plt.xlabel('Number of Hits')
plt.ylabel('Occurrences')
plt.title('Histogram of Hits - Test 6')
plt.show()

