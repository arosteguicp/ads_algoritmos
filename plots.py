import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

data = pd.read_csv('data.csv')

# Plotting the data
plt.plot(data['x'], data['y'], 'o')
plt.xlabel('x')
plt.ylabel('y')
plt.show()


