import matplotlib.pyplot as plt
import subprocess

sizes = [100, 500, 1000, 2000, 5000, 10000, 50000, 100000]
list_times = []
vector_times = []
map_times = []

i=0
for size in sizes:
    # Run the C++ code and capture the output
    output = subprocess.check_output(["./Insertion_Random", str(size)])
    lines = output.decode().splitlines()

    # Extract the numerical part of the string and convert it to a float for list time
    list_time_str = lines[i].split(": ")[1].split()[0]  # Extract the time string and remove 'seconds'
    list_time = float(list_time_str)

    # Extract the numerical part of the string and convert it to a float for vector time
    vector_time_str = lines[i+1].split(": ")[1].split()[0]  # Extract the time string and remove 'seconds'
    vector_time = float(vector_time_str)

    # Extract the numerical part of the string and convert it to a float for map time
    map_time_str = lines[i+2].split(": ")[1].split()[0]  # Extract the time string and remove 'seconds'
    map_time = float(map_time_str)

    list_times.append(list_time)
    vector_times.append(vector_time)
    map_times.append(map_time)
    
    if (i<len(lines)-3):
        i=i+3
# Plot with logarithmic scale on x-axis
# plt.plot(sizes, list_times, label="List")
# plt.plot(sizes, vector_times, label="Vector")
plt.plot(sizes, map_times, label="Map")
plt.xlabel("Size")
plt.ylabel("Time (seconds)")
plt.legend()

# Set logarithmic scale on x-axis
plt.xscale('log')
plt.show()
