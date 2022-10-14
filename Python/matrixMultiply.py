#An alogritm to multiply two matrices
def display(matrix):
    for row in matrix:
        print(row)
#matrix one input
r1=int(input("Enter the row for the matrix one: "))
c1=int(input("Enter the column for the matrix one: "))
matrix1 = [[ int(input("Enter the element  :")) for j in range(c1) ] for i in range(r1)]

#matrix two input
r2=int(input("Enter the row for the matrix two: "))
c2=int(input("Enter the column for the matrix two: "))
matrix2 = [[ int(input("Enter the element  :")) for j in range(c2)] for i in range(r2)]

if c1 == r2:
    #multiplication of two matrices
    mul=[[ 0 for j in range(c2)] for i in range(r1)]

    for x in range(r1):
        for j in range(c2):
            for i in range(r2):
                mul[x][j] += matrix1[x][i] * matrix2[i][j]
    print("Matrix 1: ")
    display(matrix1)

    print("Matrix 2: ")
    display(matrix2)

    print("Multiplied Matrix: ")
    display(mul)
else:
    print("""Matrix Multiplication is not possible with these row and column values.
    Column of the first matrix and Row of the second matrix must be equal.
    Please Try Again!""")