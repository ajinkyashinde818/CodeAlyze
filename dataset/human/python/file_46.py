def read_input():
    r, g, b, n = map(int, input().split())
    return r, g, b, n

def submit():
    r, g, b, n = read_input()

    r_max = n // r
    g_max = n // g

    count = 0
    for rc in range(r_max + 1):
        for gc in range(g_max + 1):
            rest = n - (r*rc) - (g*gc)
            if rest < 0:
                continue

            bc, remain = divmod(rest, b)
            if remain == 0:
                count += 1

    print(count)

if __name__ == '__main__':
    submit()
