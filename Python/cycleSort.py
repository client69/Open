# Python program to implement cycle sort
# OUTPUT
# The original array is: [2, 4, 5, 1, 3]
# The sorted array is: [1, 2, 3, 4, 5]

def cycle_Sort(array):
    write = 0

    # Loop through the array to find cycles to rotate.
    for cycle in range(0, len(array) - 1):
        ele = array[cycle]

        # Find where to put the element.
        position = cycle
        for i in range(cycle + 1, len(array)):
            if array[i] < ele:
                position += 1

        # If the item is already there, this is not a cycle.
        if position == cycle:
            continue

        # Otherwise, put the element there or right after any duplicates.
        while ele == array[position]:
            position += 1
        array[position], ele = ele, array[position]
        write += 1

        # Rotate the rest of the cycle.
        while position != cycle:

            # Find where to put the element.
            position = cycle
            for a in range(cycle + 1, len(array)):
                if array[a] < ele:
                    position += 1

            # Put the element there or right after any duplicates.
            while ele == array[position]:
                position += 1
            array[position], ele = ele, array[position]
            write += 1

    return write


# driver code
array = [2, 4, 5, 1, 3]
print("The original array is:", array)
n = len(array)
cycle_Sort(array)
print("The sorted array is: ", array)
