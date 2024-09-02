# Tic-Tac-Toe game in Python

# Function to print the game board
def print_board(board):
    for row in board:
        print(" | ".join(row))
        print("-" * 9)

# Function to check for a win condition
def check_win(board, player):
    # Check rows
    for row in board:
        if all([spot == player for spot in row]):
            return True

    # Check columns
    for col in range(3):
        if all([board[row][col] == player for row in range(3)]):
            return True

    # Check diagonals
    if all([board[i][i] == player for i in range(3)]) or all([board[i][2 - i] == player for i in range(3)]):
        return True

    return False

# Function to check for a draw
def check_draw(board):
    for row in board:
        if " " in row:
            return False
    return True

# Main function to run the game
def tic_tac_toe():
    # Initialize an empty game board
    board = [[" " for _ in range(3)] for _ in range(3)]
    current_player = "X"

    while True:
        print_board(board)
        print(f"Player {current_player}'s turn")

        # Get user input
        row, col = map(int, input("Enter row and column numbers to place your mark (0, 1, 2): ").split())
        
        # Check if the cell is empty
        if board[row][col] == " ":
            board[row][col] = current_player
        else:
            print("Cell already taken. Choose another one.")
            continue

        # Check for win or draw
        if check_win(board, current_player):
            print_board(board)
            print(f"Player {current_player} wins!")
            break
        elif check_draw(board):
            print_board(board)
            print("It's a draw!")
            break

        # Switch player
        current_player = "O" if current_player == "X" else "X"

# Start the game
tic_tac_toe()
