# Define a function named 'check' that takes a list 'b', [b is our string] as input
def check(b):
    # Create an empty dictionary 'temp' to store counts of each element in 'b'
    temp = {}

    # Loop through each element 'i' in the list 'b'
    for i in b:
        # Check if 'i' is already in the 'temp' dictionary
        if i in temp:
            # If it is, increment its count by 1
            temp[i] += 1
        else:
            # If it's not, add it to the dictionary with a count of 1
            temp[i] = 1

    # Initialize variables 'count' and 'rep_num' to keep track of the most common element and its count
    rep_num = 0
    count = 0

    # Loop through the items in the 'temp' dictionary
    for n, c in temp.items():
        # Check if the count 'c' is greater than the current maximum count 'count'
        if c > count:
            # If it is, update 'count' and 'rep_num' with the new maximum values
            count = c
            rep_num = n

    # Return the most common element 'rep_num' as the result
    return rep_num

# Input: Read an integer 'a'
a = int(input())

# Input: Read a list of integers 'b'
b = list(map(int, input().split()))

# Call the 'check' function with the list 'b' and print the result
print(check(b))
