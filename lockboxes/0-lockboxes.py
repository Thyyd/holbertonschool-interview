def canUnlockAll(boxes):
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
