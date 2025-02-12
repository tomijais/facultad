def knapsack_dp(items, K):
    n = len(items)
    dp = [[0] * (K + 1) for _ in range(n + 1)]
    reachable = [[False] * (K + 1) for _ in range(n + 1)]
    reachable[0][0] = True

    for i in range(1, n + 1):
        size, value = items[i - 1]
        for w in range(K + 1):
            dp[i][w] = dp[i - 1][w]
            if w >= size:
                dp[i][w] = max(dp[i][w], dp[i - 1][w - size] + value)
            reachable[i][w] = reachable[i - 1][w]
            if w >= size:
                reachable[i][w] |= reachable[i - 1][w - size]

    max_value = dp[n][K]
    exact_size_possible = reachable[n][K]

    return dp, max_value, exact_size_possible


items = [(6, 5), (4, 3), (2, 1), (7, 3), (4, 10), (12, 6)]
K = 6
dp_table, max_value, exact_size_possible = knapsack_dp(items, K)

print("DP Table:")
for row in dp_table:
    print(row)
print("\nMaximum Value:", max_value)
print("Is exact size K achievable?", exact_size_possible)