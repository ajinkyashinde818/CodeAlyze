def main():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    d = [[None]*51 for _ in [0]*51]  # 目的のあまり、現在の数値
    for i in range(51):
        d[i][i] = [[]]
    for i in range(51):  # あまり
        for j in range(i+1, 51):  # 現在の数値
            temp = []
            for kk in range(1, j+1):  # 割る数
                k = j % kk
                if d[i][k] is None:
                    continue
                for l in d[i][k]:
                    temp += [l+[kk]]
            if temp == []:
                temp = None
            d[i][j] = temp
    c = [d[bb][aa] for aa, bb in zip(a, b)]
    if None in c:
        print(-1)
        return
    ans = 0
    while True:
        M = -1
        for i in range(n):
            if [] in c[i]:
                c[i] = [[]]
            else:
                m = min([j[-1] for j in c[i]])
                M = max(M, m)
        if M == -1:
            break
        ans += 2**M
        for i in range(n):
            temp = []
            if c[i] == [[]]:
                continue
            for j in c[i]:
                if j[-1] == M:
                    temp.append(j[:-1])
                elif j[-1] < M:
                    temp.append(j)
            c[i] = temp
    print(ans)


main()
