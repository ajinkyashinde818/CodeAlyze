def solve():
    D, G = map(int, input().split())
    p = [0 for _ in range(D)]
    c = [0 for _ in range(D)]

    for i in range(D):
        p[i], c[i] = map(int, input().split())

    ans = 1000
    for i in range(2 ** D):
        comp = [0 for _ in range(D)]
        num = 0
        score = 0
        for j in range(D):
            if i >> j & 1:
                comp[j] = 1
                # print('j',j)
                score += 100 * (j + 1) * p[j] + c[j]

        for j in range(D):
            if comp[j] == 1:
                num += p[j]
        if score < G:
            index = 0
            for j in range(D - 1, 0, -1):
                if comp[j] == 0:
                    index = j
                    break
            for _ in range(p[index]):
                score += 100 * (index + 1)
                num += 1
                if score >= G:
                    break
            if score < G:
                continue
        # print('i', i)
        # print('num',num)
        # print('score',score)
        ans = min(ans, num)
    print(ans)


if __name__ == "__main__":
    solve()
