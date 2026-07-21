s,t = map(str, [input() for i in range(2)])

S = [s[i] for i in range(len(s))]
T = [t[i] for i in range(len(t))]


def XY(x, y):
    x.sort()
    y.sort(reverse=True)
    c = 0
    D = True
    while c < len(x) and c < len(y):
        if x[c] < y[c]:
            break
        elif x[c] == y[c]:
            c += 1
        elif x[c] > y[c]:
            D = False
            break
        if len(x) >= len(y) and c == len(y)-1 and x[c] >= y[c]:
            D = False


    return D

Result = XY(S, T)

if Result:
    print('Yes')
else:
    print('No')
