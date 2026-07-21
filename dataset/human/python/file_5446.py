import numpy as np


def getInput():
    """

    :return: list of list of str. 1st dim: row, 2nd dim: column.
    """
    separator = ' '
    ret_array = []
    while True:
        try:
            row = input().split(sep=separator)
            ret_array.append(row)
        except EOFError:
            break
    return ret_array


g = getInput()

# number
p = np.array(list(map(int, g[0])), dtype=np.int32)
h, f = divmod(p, 10)
if h == 9 or f == 9:
    print('Yes')
else:
    print('No')
