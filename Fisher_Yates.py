#Shuffle a given array using Fisher–Yates shuffle Algorithm
def shuffler (arr, n):
	
	for i in range(n-1,0,-1):
		
		
		j = random.randint(0,i+1)
		arr[i],arr[j] = arr[j],arr[i]
	return arr

arr = np.array([1, 2, 3, 4, 5, 6])

print("Original array: ",arr)

n = len(arr)

print("Shuffled array: ",shuffler(arr, n))
