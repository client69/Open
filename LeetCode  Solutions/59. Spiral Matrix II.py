# PROBLEM STATEMENT:
# Given to you shall be a number, within the range from 0 to 9. Draw a set of triangles which sit inside each other.
# You will be given a positive integer n. You need to create a 2-D matrix which is filled with elements beginning
# from 1 till n^2 in a circular or spiral fashion.
# Given constraint that the positive number shall be less than 20 only.  
# 
# EXAMPLE:
# Input1:
# 3
#  
# Output1:
# [[1,2,3],[8,9,4],[7,6,5]]
#  
# Input2:
# 4
#  
# Output2:
# [[1,2,3,4],[12,13,14,5],[11,16,15,6],[10,9,8,7]
#  
# Input3:
# 1
#  
# Output3:
# [[1]]


n = int(input())
matrix = [[0 for x in range(n)] for x in range(n)]
left = 0
right = n-1
top = 0
bottom = n-1
num = 1 
while(left <= right and top <= bottom):
    for i in range(left, right+1):
        matrix[top][i] = num 
        num = num + 1
    for i in range(top+1, bottom):
        matrix[i][right] = num 
        num = num + 1
    for i in range(right, left-1, -1):
        if(top<bottom):
            matrix[bottom][i] = num 
            num = num + 1
    for i in range(bottom-1, top, -1):
        if(left<right):
            matrix[i][left] = num 
            num = num + 1
    left = left+1 
    right = right-1
    top = top+1 
    bottom = bottom-1
print(matrix)