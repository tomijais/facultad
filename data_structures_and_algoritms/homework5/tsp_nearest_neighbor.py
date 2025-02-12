def tsp_nearest_neighbor(distances):
    num_cities = len(distances)
    visited = [False] * num_cities
    route = []
    total_distance = 0

    current_city = 0
    visited[current_city] = True
    route.append(current_city)

    for _ in range(num_cities - 1):
        nearest_city = None
        nearest_distance = float('inf')
        for city in range(num_cities):
            if not visited[city] and distances[current_city][city] < nearest_distance:
                nearest_city = city
                nearest_distance = distances[current_city][city]

        visited[nearest_city] = True
        route.append(nearest_city)
        total_distance += nearest_distance
        current_city = nearest_city

    total_distance += distances[current_city][route[0]]
    route.append(route[0])

    return total_distance, route

distances = [
    [0, 10, 15, 20],
    [10, 0, 35, 25],
    [15, 35, 0, 30],
    [20, 25, 30, 0]
]

total_distance, route = tsp_nearest_neighbor(distances)
print("Approximate Total Distance:", total_distance)
print("Route:", route)