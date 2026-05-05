#!/usr/bin/python3
"""
N Queens Problem Solver
"""
import sys


def is_safe(board, row, col, n):
    """
    Vérifie si on peut placer une reine à la position (row, col)

    Args:
        board: liste des positions des reines (liste de [row, col])
        row: ligne actuelle
        col: colonne à tester
        n: taille de l'échiquier

    Returns:
        True si la position est sûre, False sinon
    """
    for queen in board:
        queen_row, queen_col = queen[0], queen[1]

        if queen_col == col:
            return False

        if queen_row - queen_col == row - col:
            return False

        if queen_row + queen_col == row + col:
            return False

    return True


def solve_nqueens(board, row, n, solutions):
    """
    Résout le problème des N reines avec backtracking

    Args:
        board: positions actuelles des reines
        row: ligne actuelle à traiter
        n: taille de l'échiquier
        solutions: liste pour stocker toutes les solutions
    """
    if row == n:
        solutions.append([queen[:] for queen in board])
        return

    for col in range(n):
        if is_safe(board, row, col, n):
            board.append([row, col])

            solve_nqueens(board, row + 1, n, solutions)

            board.pop()


def main():
    """
    Point d'entrée du programme
    """
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    solutions = []
    solve_nqueens([], 0, n, solutions)

    for solution in solutions:
        print(solution)


if __name__ == "__main__":
    main()
