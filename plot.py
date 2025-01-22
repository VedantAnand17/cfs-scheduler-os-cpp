import matplotlib.pyplot as plt

# Data
data = [
    (3, 1668631324671, 1668631325587),
    (7, 1668631326796, 1668631327587),
    (5, 1668631328254, 1668631328921),
    (1, 1668631329629, 1668631330254),
    (2, 1668631330629, 1669631653073),
    (8, 1669631655031, 1670632338142),
    (6, 1670632338933, 1671632489252),
    (4, 1671632490544, 1672632974696)
]

# Extract data
pids = [item[0] for item in data]
start_times = [item[1] for item in data]
end_times = [item[2] for item in data]

# Calculate durations
durations = [end - start for start, end in zip(start_times, end_times)]

# Plot
fig, ax = plt.subplots(figsize=(10, 6))

for i, (pid, start, duration) in enumerate(zip(pids, start_times, durations)):
    ax.broken_barh([(start, duration)], (i - 0.4, 0.8), facecolors=f"C{i % 10}")

# Set labels and formatting
ax.set_yticks(range(len(pids)))
ax.set_yticklabels([f"PID {pid}" for pid in pids])
ax.set_xlabel("Time (ms since epoch)")
ax.set_ylabel("Processes")
ax.set_title("Process Execution Timeline")
ax.grid(True, which="both", linestyle="--", linewidth=0.5)

plt.tight_layout()
plt.show()
