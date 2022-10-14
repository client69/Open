lst = eval(input("Enter the list to be sorted: "))
n = len(lst)
print("Entered list before sorting:" , lst)
for i in range (0 , n):
    key = lst[i]
    j = i - 1
    while j >=0 and key < lst[j]:
        lst[j+1] = lst[j]
        j -= 1
    else:
        lst[j+1] = key

print("List after Insertion sort:" , lst)
