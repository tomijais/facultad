def matrixDiagonalSort(arr):
    diagonals = {}
    for i in range(len(arr)):
        for j in range(len(arr[0])):
            key = i-j
            if key not in diagonals:
                diagonals[key] = []
            diagonals[key].append(arr[i][j])

    for key in diagonals:
        sorted_arr = bubble_sort(diagonals[key])
        diagonals[key] = sorted_arr



    for i in range(len(arr)):
        for j in range(len(arr[0])):
            key = i-j
            arr[i][j] = diagonals[key].pop(0)

    return arr


def bubble_sort(arr):
    for n in range(len(arr) - 1, 0, -1):
        for i in range(n):
            if arr[i] > arr[i + 1]:
                arr[i], arr[i + 1] = arr[i + 1], arr[i]

    return arr

            
print(matrixDiagonalSort([[3,3,1,1], [2,2,1,2], [1,1,1,2]]))