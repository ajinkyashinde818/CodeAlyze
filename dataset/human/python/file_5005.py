def get_input():
    while True:
        try:
            yield ''.join(input())
        except EOFError:
            break

N = list(get_input())


for l in range(len(N)):
    c = [4, 1, 4, 1, 2, 1, 2, 1]
    p = [int(i) for i in N[l].split()]
    for i in range(len(p)):
        if p[i] > 9:
            p[i] = 9

    V = 99999999
    score = 99999
    for d in range(8):
        s = 0
        for i in range(8):
            s += max(p[i] - c[(i+d)%8], 0)

        v = 0
        for i in range(8):
            v *= 10
            v += c[(i+d)%8]

        if s < score:
            score = s
            V = v
        elif s == score:
            if v < V:
                V = v

    ans = str(V)
    for i in range(7):
        print(ans[i], end=" ")
    print(ans[7])
