def main():
    d, g = map(int, input().split())
    p, c = [0 for i in range(d)], [0 for i in range(d)]
    for i in range(d):
        p[i], c[i] = map(int, input().split())

    min_p = 1001
    for i in range(2**d):
        s = 0
        max_s, t = -1, 0
        for j in range(d):
            if (i >> j) & 1:
                s += p[j] * (j+1) * 100 + c[j]
                t += p[j]
            else:
                max_s = j + 1

        if g <= s:
            min_p = min(t, min_p)
        elif max_s != -1 and (g-s) // (max_s*100) < p[max_s-1]:
            t += (g-s+max_s*100-1) // (max_s*100)
            min_p = min(t, min_p)

    print(min_p)


if __name__ == '__main__':
    main()
