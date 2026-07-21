def solve(D, G, P, C):
    ret = float('inf')
    for i in range(pow(2, D)):
        tmp_score = 0
        tmp_counter = 0
        not_selected = -1

        for j in range(D):
            if i >> j & 1:
                tmp_counter += P[j]
                tmp_score += P[j] * 100 * (j + 1) + C[j]
            else:
                not_selected = j

        if G <= tmp_score:
            ret = min(ret, tmp_counter)
            continue

        for _ in range(1, P[not_selected]):
            tmp_score += 100 * (not_selected + 1)
            tmp_counter += 1
            if G <= tmp_score:
                ret = min(ret, tmp_counter)
                break

    print(ret)

if __name__ == "__main__":
    D, G = map(int, input().split())
    P = []
    C = []

    for _ in range(D):
        p, c = map(int, input().split())
        P.append(p)
        C.append(c)

    solve(D, G, P, C)
