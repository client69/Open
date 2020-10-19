def binary_search(array, array_size, value):
    i = 0
    j = array_size - 1
    position = int((i + j)/2)

    while j >= i and array[position] != value:
        if array[position] > value:
            j = position - 1
        else:
            i = position + 1
        position = int((i + j)/2)

    if array[position] == value:
        return position
    else:
        return -1


array = [1, 5, 6, 8, 9, 22, 32]
position = binary_search(array, len(array), 22)
if position != -1:
    print("The value's position in the array is:", position)
else:
    print("This value doesn't exist in the array")
