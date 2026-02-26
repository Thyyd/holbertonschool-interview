#!/usr/bin/python3
"""
Minimum operation
"""


def minOperations(n):
    """
    Compute the minimum number of operations

    If n is impossible to achieve, return 0
    """
    if not isinstance(n, int) or n < 2:
        return 0

    ops = 0  # Opérations
    d = 2  # Diviseur

    # Calcul nombre de diviseurs premiers
    while d * d <= n:
        while n % d == 0:
            ops += d
            n //= d
        d += 1

    # Ajoute le dernier facteur premier
    if n > 1:
        ops += n

    return ops
