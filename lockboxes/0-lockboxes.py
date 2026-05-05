#!/usr/bin/python3
"""
This module contains a function that returns True of False
if we can open all the boxes
"""


def canUnlockAll(boxes):
    """
    Function canUnlockAll that checks if we can unlock every box contained
    in a bigger one.

    Parameters :
    boxes : List containing another list composed by entire values

    Return :
    True if all the boxes are unlocked
    False if they're not all unlocked
    """
    keys = [0]
    for index in keys:
        for element in boxes[index]:
            if element not in keys and element < len(boxes) and element > 0:
                keys.append(element)
    if len(keys) == len(boxes):
        Retour = True
    else:
        Retour = False
    return Retour
