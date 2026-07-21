def A_hex(X, Y):
    x = [10, 11, 12, 13, 14, 15, 16][ord(X) - ord('A')]
    y = [10, 11, 12, 13, 14, 15, 16][ord(Y) - ord('A')]
    if x > y:
        return '>'
    elif x < y:
        return '<'
    else:
        return '='

X,Y = input().split()
print(A_hex(X, Y))
