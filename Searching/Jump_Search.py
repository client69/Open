def jumpSearch(arr, x):
    m = int(len(arr)**0.5)
    for i in range(0,len(arr),m-1):
        if arr[i] == x:
            return f"Element found at {i} position"
        elif arr[i] > x:
            for j in range(i-m,i):
                if arr[j] == x:
                    return f"Element found at {j} position"

    return f"Element not found"


if __name__ == "__main__":
    arr = [0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 79, 89, 91, 95, 110]
    # for element in arr:
    #     print(jumpSearch(arr,element))
    print(jumpSearch(arr, -8))