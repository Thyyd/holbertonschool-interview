#!/usr/bin/python3
"""
Module for rotating a 2D matrix 90 degrees clockwise
"""


def rotate_2d_matrix(matrix):
    """
    Rotates an n x n 2D matrix 90 degrees clockwise in-place.

    Parameters:
        matrix: 2D list representing the matrix to rotate
    """
    # Retreival of the dimention of the matrix
    n = len(matrix)

    # Transpose the Matrix
    for i in range(n):
        for j in range(i, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

    # Reverse each row
    for i in range(n):
        for j in range(int(n/2)):
            matrix[i][j], matrix[i][n-1-j] = matrix[i][n-1-j], matrix[i][j]
