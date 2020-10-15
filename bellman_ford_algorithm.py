#This function utilizes Bellman-Ford's algorithm to find the shortest path from the chosen vertex to the others.
def bellman_ford(matrix, nRows, nVertex):
    vertex = nVertex - 1
    listDist = []
    estimation = float("inf")
    for i in range(nRows):
        if (i == vertex):
            listDist.append(0)
        else:
            listDist.append(estimation)
    for i in range(nRows-1):
        for j in range(nRows):
            for k in range (nRows):
                if (matrix[j][k] != 0 and matrix[j][k] + listDist[j] < listDist[k]):
                    listDist[k] = matrix[j][k] + listDist[j]
    return listDist


# This function prints the distance from the inital vertex to the othersdef printBF(lista):
def printBF(list):
    nDist = len(list)
    for i in range(nDist):
        print("The distance to the vertex " + str(i + 1) + " is: " + str(list[i]))

#We start with  the adjacency matrix of a weighted graph.
adjacencyMatrix = [[0, 10, 5, 0, 0, 0], [0, 0, 0, 1, 0, 0], [0, 3, 0, 8, 2, 0], [0, 0, 0, 0, 4, 4], [0, 0, 0, 0, 0, 6], [0, 0, 0, 0, 0, 0]]
originVertex = 1  # Here you can chose the origin vertex (value >=1)
nRows=len(adjacencyMatrix[0])
nColumns=len(adjacencyMatrix)
#Here we get the shortest paths from the origin vertex utilizing Bellman-Ford's Algorithm
finalBF = bellman_ford(adjacencyMatrix, nRows, originVertex)
# Now we just print the distances from the chosen vertex to another.
printBF(finalBF)
