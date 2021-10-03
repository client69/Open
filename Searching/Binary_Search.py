def binarySearch(element, l, r, arr):
    if r >= l:
        mid = l + (r-l)//2
        if arr[mid] == element:
            return f"Element found at {mid} position"
        elif arr[mid] > element:
            return binarySearch(element, l, mid-1, arr)
        else:
            return binarySearch(element, mid+1, r, arr)
    else:
        return f"Element not found"

if __name__ == "__main__":
    arr = [-45, -1, 9, 9, 11, 46, 89, 1000]
    # for ele in arr:
    #     print(binarySearch(ele, 0, len(arr), arr))
    print(binarySearch(-46, 0, len(arr), arr))