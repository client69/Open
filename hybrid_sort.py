'''
This is a combination of insertion sort and merge sort, it changes the base
case of merge sort to use insertion sort.
'''

import arrays
import sorts
import array_utils

insertion = 10

#Insertion sort
def increasing_comparator(a, b):
    return a < b

def decreasing_comparator(a, b):
    return a >= b

def swap(arr, index1, index2):
    arr[index1], arr[index2] = arr[index2], arr[index1]

def shift(arr, index, comparator=increasing_comparator):
    while index > 0:
        if comparator(arr[index], arr[index - 1]):
            swap(arr, index, index - 1)
            index -= 1
        else:
            break

def insertion_sort(arr, comparator = increasing_comparator):
    for i in range(len(arr)):
        shift(arr, i, comparator)
    return arr


#Merge Sort
def mod_merge_sort(arr):
    #Base Cases
    if len(arr) <= insertion: #instead of the normal basecase, once the arrays are split to size <insertion> they use an insertion sort to finish sorting faster
        return (insertion_sort(arr))
    else:
        half1, half2 = split(arr)
        return merge(mod_merge_sort(half1), mod_merge_sort(half2))

def split(arr):
    evens = arrays.Array((len(arr)+1) // 2)
    odds = arrays.Array(len(arr) // 2)
    isEven = True
    for i in range(len(arr)):
        if isEven:
            evens[i//2] = arr[i]
        else:
            odds[i // 2] = arr[i]
        isEven = not isEven
    return evens, odds

def merge(half1, half2):
    result = arrays.Array(len(half1) + len(half2))
    i1 = 0 
    i2 = 0
    while i1 < len(half1) and i2 < len(half2):
        if half1[i1] <= half2[i2]:
            result[i1+i2] = half1[i1]
            i1 += 1
        else:
            result[i1 + i2] = half2[i2]
            i2 += 1
    if i1 < len(half1):
        for j in range(i1, len(half1)):
            result[i2 + j] = half1[j]
    else:
        for j in range(i2, len(half2)):
            result[i1 + j] = half2[j]

    return result