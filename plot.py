import numpy as np
import matplotlib.pyplot as plt
from m_temp import yy  # Assuming yy is defined in m_temp.py

# Plot the histogram
plt.hist(yy, bins=range(16), align='left', rwidth=0.8)
plt.xlabel('Number of Hits')
plt.ylabel('Occurrences')
plt.title('Histogram of Hits')
plt.show()
