def has_hamiltonian_path(graph):
    from collections import deque
    in_degree = {u: 0 for u in graph}
    for u in graph:
        for v in graph[u]:
            in_degree[v] += 1

    queue = deque([u for u in graph if in_degree[u] == 0])
    top_order = []

    while queue:
        u = queue.popleft()
        top_order.append(u)
        for v in graph[u]:
            in_degree[v] -= 1
            if in_degree[v] == 0:
                queue.append(v)

    if len(top_order) != len(graph):
        return False

    for i in range(len(top_order) - 1):
        u = top_order[i]
        v = top_order[i + 1]
        if v not in graph[u]:
            return False

    return True

# Example:
graph = {
    'A': ['B'],
    'B': ['C'],
    'C': ['D'],
    'D': []
}

print(has_hamiltonian_path(graph))