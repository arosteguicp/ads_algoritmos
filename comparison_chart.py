import matplotlib.pyplot as plt;
import pandas as pd;

# |====| get data section
# read data generated from main
df = pd.read_csv("tester_times.csv", header=None, names=["size", "sort", "time"])

countsort_times = df[df["sort"] == "count_sort"]["time"].tolist();
radix_times = df[df["sort"] == "radix_sort"]["time"].tolist();
sizes = df[df["sort"] == "radix_sort"]["size"].tolist();

# --> for bubble sort
# bubble_sizes = df[(df["sort"] == "bubble_sort") & (df["size"] <= 100000)]["size"].tolist()
# bubble_times = df[(df["sort"] == "bubble_sort") & (df["size"] <= 100000)]["time"].tolist()

# |====| plot section 

plt.plot(sizes, countsort_times, label='Counting Sort', marker='*');
plt.plot(sizes, radix_times, label='Radix Sort', marker='*');
# --> for bubble sort
# plt.plot(bubble_sizes, bubble_times, label='Bubble Sort', marker='o')

labels = ["0", "20k", "40k", "60k", "80k", "100k", "300k", "600k", "800k", "1M"]
plt.xticks(sizes, labels, rotation=45)

plt.xlabel('Cantidad de elementos')
plt.ylabel('Tiempo (ms)')
plt.title('Grafico comparativo.')
plt.legend()
plt.grid(True)
plt.tight_layout()

# --> for bubble sort
# plt.xlim(0, 150000)  # Ajusta el límite del eje x para centrarte en el rango de 0 a 150k


plt.show()