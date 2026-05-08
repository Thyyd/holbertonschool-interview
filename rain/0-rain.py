#!/usr/bin/python3
"""
Module to calculate rainwater retention
"""


def rain(walls):
    """
    Calculate how many square units of water will be retained after it rains.

    Args:
        walls: List of non-negative integers representing wall heights

    Returns:
        Integer indicating total amount of rainwater retained

    Algorithm:
        For each position, water retained = min(max_left, max_right) - height
        We precompute max_left and max_right arrays for efficiency
    """
    if not walls or len(walls) < 3:
        return 0

    n = len(walls)
    total_water = 0

    left_max = [0] * n
    left_max[0] = walls[0]
    for i in range(1, n):
        left_max[i] = max(left_max[i - 1], walls[i])

    right_max = [0] * n
    right_max[n - 1] = walls[n - 1]
    for i in range(n - 2, -1, -1):
        right_max[i] = max(right_max[i + 1], walls[i])

    for i in range(n):
        water_level = min(left_max[i], right_max[i])
        if water_level > walls[i]:
            total_water += water_level - walls[i]

    return total_water
