def least_interval(tasks, n):
    task_counts = [0] * 26
    for task in tasks:
        index = ord(task) - ord('A')
        task_counts[index] += 1

    max_freq = 0
    for count in task_counts:
        if count > max_freq:
            max_freq = count

    max_count = 0
    for count in task_counts:
        if count == max_freq:
            max_count += 1

    intervals = (max_freq - 1) * (n + 1) + max_count

    total_tasks = len(tasks)
    return max(total_tasks, intervals)

# Example 1
tasks1 = ["A", "A", "A", "B", "B", "B"]
n1 = 2
result1 = least_interval(tasks1, n1)
print("Minimum intervals required (Example 1):", result1)

# Example 2
tasks2 = ["A", "C", "A", "B", "D", "B"]
n2 = 1
result2 = least_interval(tasks2, n2)
print("Minimum intervals required (Example 2):", result2)