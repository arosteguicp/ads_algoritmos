import matplotlib.pyplot as plt;
import pandas as pd;

# |====| get data section
# read data generated from main
df = pd.read_csv("tester_times.csv", header=None, names=["size", "sort", "time"])

countsort_times = df[df["sort"] == "count_sort"]["time"].tolist()
radix_times = df[df["sort"] == "radix_sort"]["time"].tolist()
sizes = df[df["sort"] == "radix_sort"]["size"].tolist()

# |====| plot section 
plt.plot(sizes, countsort_times, label='Counting Sort', marker='o')
plt.plot(sizes, radix_times, label='Radix Sort', marker='o')

plt.xlabel('Cantidad de elementos')
plt.ylabel('Tiempo (ms)')
plt.title('Grafico comparativo.')
plt.legend()
plt.grid(True)
plt.show()