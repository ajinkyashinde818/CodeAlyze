def main():
    D, G = map(int, input().split())
    PC = [tuple(map(int, input().split())) for _ in range(D)]
    PC = [(p, c // 100) for p, c in PC]
    G //= 100
    m = 10 * 100
    for i in range(2 ** D):
        g = 0
        t = 0
        k = -1
        for j, (p, c) in enumerate(PC):
            if (1 << j) & i:
                g += (j + 1) * p + c
                t += p
            else:
                k = j
        if g >= G:
            m = min(m, t)
            continue
        p, c = PC[k]
        if (k + 1) * p + g < G:
            continue
        m = min(m, t + (G - g + k) // (k + 1))
    return m

print(main())
