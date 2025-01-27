import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV file
df = pd.read_csv('process_schedule.csv')

# Create a figure
plt.figure(figsize=(12, 6))

# Plot each process as a horizontal bar
for _, row in df.iterrows():
    plt.hlines(y=row['pid'], 
              xmin=row['start_time'], 
              xmax=row['end_time'], 
              linewidth=10, 
              color=plt.cm.Set3(row['pid'] % 8))  # Cycle through colors

# Customize the plot
plt.title('Process Schedule Timeline')
plt.xlabel('Time')
plt.ylabel('Process ID')
plt.grid(True, axis='x', linestyle='--', alpha=0.7)

# Adjust y-axis to show all process IDs
unique_pids = df['pid'].unique()
plt.yticks(unique_pids)

# Add legend
processes = [f'Process {pid}' for pid in unique_pids]
plt.legend(processes, bbox_to_anchor=(1.05, 1), loc='upper left')

plt.tight_layout()
plt.savefig('process_schedule.png')
plt.show()