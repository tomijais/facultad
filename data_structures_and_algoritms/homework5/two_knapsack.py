def two_knapsack(items, K):
    n = len(items)
    dp = [[[0] * (K + 1) for i in range(K + 1)] for i in range(n + 1)]
    choices = [[[0] * (K + 1) for i in range(K + 1)] for i in range(n + 1)]

    for i in range(1, n + 1):
        size_i, value_i = items[i - 1]
        for k1 in range(K + 1):
            for k2 in range(K + 1):
                dp[i][k1][k2] = dp[i - 1][k1][k2]
                choices[i][k1][k2] = 0
                max_val = dp[i][k1][k2]

                if size_i <= k1:
                    val = dp[i - 1][k1 - size_i][k2] + value_i
                    if val > max_val:
                        dp[i][k1][k2] = val
                        choices[i][k1][k2] = 1
                        max_val = val

                if size_i <= k2:
                    val = dp[i - 1][k1][k2 - size_i] + value_i
                    if val > max_val:
                        dp[i][k1][k2] = val
                        choices[i][k1][k2] = 2
                        max_val = val

    max_value = dp[n][K][K]

    k1, k2 = K, K
    knapsack1, knapsack2 = [], []
    i = n
    while i > 0:
        choice = choices[i][k1][k2]
        if choice == 0:
            i -= 1
        elif choice == 1:
            knapsack1.append(i - 1)
            k1 -= items[i - 1][0]
            i -= 1
        elif choice == 2:
            knapsack2.append(i - 1)
            k2 -= items[i - 1][0]
            i -= 1

    knapsack1.reverse()
    knapsack2.reverse()

    return max_value, knapsack1, knapsack2

items = [
    (3, 4),
    (4, 5),
    (2, 3),
    (3, 7),
]
K = 5

max_value, knapsack1, knapsack2 = two_knapsack(items, K)

print("Maximum total value:", max_value)
print("Items in knapsack 1:", [index + 1 for index in knapsack1])
print("Items in knapsack 2:", [index + 1 for index in knapsack2])