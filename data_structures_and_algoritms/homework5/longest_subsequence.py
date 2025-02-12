def longest_increasing_subsequence(A):
    n = len(A)
    dp = [1] * n
    prev = [-1] * n

    for i in range(n):
        for j in range(i):
            if A[j] < A[i] and dp[j] + 1 > dp[i]:
                dp[i] = dp[j] + 1
                prev[i] = j

    max_length = max(dp)
    max_index = dp.index(max_length)

    lis = []
    k = max_index
    while k != -1:
        lis.append(A[k])
        k = prev[k]
    lis.reverse()

    return lis

A = [10, 22, 9, 33, 21, 50, 41, 60]
lis = longest_increasing_subsequence(A)
print("The longest increasing subsequence is:")
print(lis)