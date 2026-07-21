S = input()

S = S[::-1]


def solve(S):
    point = 0
    while S:
        if len(S) == point:
            print('YES')
            return False
        if S[point:point + 7] in {'remaerd'}:
            point += 7
        elif S[point:point + 6] in {'resare'}:
            point += 6
        elif S[point:point + 5] in {'esare', 'maerd'}:
            point += 5
        else:
            return True


if solve(S):
    print('NO')
