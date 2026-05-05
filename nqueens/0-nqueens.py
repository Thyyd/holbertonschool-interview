#!/usr/bin/python3
"""N queens puzzle solver"""
import sys


def is_safe(queens, row, col):
    """
    Check if a queen can be safely placed at the given position.

    Args:
        queens (list): List of tuples (row, col) representing already placed queens.
        row (int): The row index where we want to place the new queen.
        col (int): The column index where we want to place the new queen.

    Returns:
        bool: True if the position is safe, False otherwise.
    """
    for r, c in queens:
        if c == col or abs(r - row) == abs(c - col):
            return False
    return True


def backtrack(queens, row, n, solutions):
    """
    Recursively explore all possible queen placements using backtracking.

    Args:
        queens (list): List of tuples (row, col) representing already placed queens.
        row (int): The current row being processed.
        n (int): The size of the chessboard (N×N).
        solutions (list): List that accumulates all valid solutions found.

    Returns:
        None: Solutions are appended directly to the solutions list.
    """
    if row == n:
        solutions.append([[r, c] for r, c in queens])
        return
    for col in range(n):
        if is_safe(queens, row, col):
            queens.append((row, col))
            backtrack(queens, row + 1, n, solutions)
            queens.pop()


def solve_nqueens(n):
    """
    Find all solutions to the N queens problem on an N×N chessboard.

    Args:
        n (int): The size of the chessboard and the number of queens to place.

    Returns:
        list: A list of solutions, where each solution is a list of [row, col]
              pairs representing the position of each queen.
    """
    solutions = []
    backtrack([], 0, n, solutions)
    return solutions


def validate_input(args):
    """
    Validate the command-line arguments provided by the user.

    Args:
        args (list): The list of command-line arguments (sys.argv).

    Returns:
        int: The validated value of N if all checks pass.

    Raises:
        SystemExit: Exits with status 1 if arguments are invalid.
    """
    if len(args) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(args[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    return n


if __name__ == "__main__":
    N = validate_input(sys.argv)

    for solution in solve_nqueens(N):
        print(solution)
