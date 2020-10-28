N = None


def pos_is_safe(board, row, col):
    # check row and column
    for i in range(N):
        if board[row][i] == 'Q' or board[i][col] == 'Q':
            return False
    # check right-down diagonal
    i = 1
    while (row+i < N) and (col+i < N):
        if board[row+i][col+i] == 'Q':
            return False
        i += 1

    # check right-up diagonal
    i = 1
    while (row-i > -1) and (col-i > -1):
        if board[row-i][col-i] == 'Q':
            return False
        i += 1

    # check left-down
    i = 1
    while (row+i < N) and (col-i > -1):
        if board[row+i][col-i] == 'Q':
            return False
        i += 1

    # check left-up
    i = 1
    while (col+i < N) and (row-i > -1):
        if board[row-i][col+i] == 'Q':
            return False
        i += 1
    return True


def n_queen_helper(board, queens_to_place):
    global N

    # if all placements done, return board
    if queens_to_place == 0:
        return board

    for i in range(N):
        for j in range(N):
            # if place is empty, place queen
            if board[i][j] == '.' and pos_is_safe(board, i, j):
                # place the queen
                board[i][j] = 'Q'
                # check if we can place one more queen
                if n_queen_helper(board, queens_to_place-1):
                    return board
                else:
                    # if we reach here, matlab we cannot place anymore queens therefore reverse last move
                    board[i][j] = '.'
    # in case of all iterations being done and still no placement, return empty
    return None


def create_matrix():
    global N
    # Inserting . at all locations of the matrix to denote availability
    matrix = [['.'] * N for i in range(N)]
    return matrix


# While loop to continue asking user for valid input
while(True):
    try:
        N = int(input("Input number of queens(>=4<=8): "))
    except ValueError:
        print('Non-integer value given, enter value!\n')
        continue
    if N < 4:
        print('N cannot be less than 4!\n')
        continue
    elif N > 8:
        print('N cannot be greater than 8!\n')
        continue
    break
board = create_matrix()
solved_board = n_queen_helper(board, N)
if solved_board:
    for row in solved_board:
        print(row)
