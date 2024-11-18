def findCheapestPrice(n, flights, source, destination, k):
    graph = [[] for _ in range(n)]
    for frm, to, price in flights:
        graph[frm].append((to, price))
    
    queue = [(source, 0, 0)]
    
    min_cost = [[float('inf')] * (k + 2) for _ in range(n)]
    min_cost[source][0] = 0

    while queue:
        current_city, current_cost, stops = queue.pop(0)

        if stops > k:
            continue

        for neighbor, price in graph[current_city]:
            new_cost = current_cost + price
            if new_cost < min_cost[neighbor][stops + 1]:
                min_cost[neighbor][stops + 1] = new_cost
                queue.append((neighbor, new_cost, stops + 1))

    result = min(min_cost[destination])
    return result if result != float('inf') else -1

n = 4
flights = [
    [0, 1, 100],
    [1, 2, 100],
    [2, 3, 100],
    [0, 3, 500]
]
source = 0
destination = 3
k = 1

result = findCheapestPrice(n, flights, source, destination, k)
print(result)