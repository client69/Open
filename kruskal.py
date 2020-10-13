def create_matrix(n_lines, n_columns, value):  # Create a matrix
    matrix = []
    for i in range(n_lines):
        line = []
        for j in range(n_columns):
            line.append(value)
        matrix.append(line)
    return matrix

def min_value(weight):  # Function that finds the min value of the distances that are still open
    min1 = float("inf")
    min_index = 0
    for i in range(len(weight)):
        if min1 > weight[i]:
            min1 = weight[i]
            min_index = i
    return min_index


def same_edge(i, j, edges):  # Function to verify if the edge is already in the list of all the edges
    r = False
    for k in edges:
        if (k[2] == i and k[1] == j) or (k[1] == i and k[2] == j):
            r = True
            break
    return r


def find_set(i, set1):  # Function to find the set of the i vertex
    for k in range(len(set1)):
        if i in set1[k]:
            return k


def kruskal(adjacency_matrix):  # Function that receives a adjacency matrix and return the minimal spanning tree's adjacency matrix
    edges = []
    sets = []
    spanning_tree = create_matrix(len(adjacency_matrix), len(adjacency_matrix), 0)

    for i in range(len(adjacency_matrix)):
        list1 = [i]
        sets.append(list1)

    for i in range(len(adjacency_matrix)):
        for j in range(len(adjacency_matrix[i])):
            if adjacency_matrix[i][j] != 0 and same_edge(i, j, edges) == False:
                t = (adjacency_matrix[i][j], i, j)
                edges.append(t)
    edges.sort(key=lambda x: x[0])

    for cont in range(len(adjacency_matrix)):
        i = find_set(edges[cont][1], sets)
        j = find_set(edges[cont][2], sets)
        if i != j:
            spanning_tree[edges[cont][1]][edges[cont][2]] = edges[cont][0]
            spanning_tree[edges[cont][2]][edges[cont][1]] = edges[cont][0]
            sets[i] += sets[j]
            sets.remove(sets[j])

    return spanning_tree


matrix = [[0, 0, 1, 0, 0], [0, 0, 3, 0, 1], [1, 3, 0, 5, 2], [0, 0, 5, 0, 4], [0, 1, 2, 4, 0]]
spanning_tree = kruskal(matrix)

for line in spanning_tree:
    line_result = ""
    for j in line:
        line_result += str(j)+","
    line_result = line_result[:-1]
    print(line_result)
