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
A = g[0][0]
B = g[0][1]

if A > B:
    print(">")
elif A < B:
    print("<")
else:
    print("=")
