def main():
    D, G = (int(i) for i in input().split())
    A = [[int(i) for i in input().split()] for j in range(D)]
    ans = 10**6
    for bit in range(1 << D):  # bitが立っている問題のコンプリートボーナスを得る
        cur = 0
        cur_sum = 0
        cur_set = set()
        for j in range(D):
            if (bit & (1 << j)):
                cur += A[j][0]
                cur_sum += A[j][1] + A[j][0] * (100*(j+1))
                cur_set.add(j)
        if cur_sum >= G:
            ans = min(ans, cur)
        else:
            less = G - cur_sum
            for j in range(D)[::-1]:
                if j in cur_set:
                    continue
                solve = (less+(100*(j+1))-1)//(100*(j+1))
                less -= min(solve, A[j][0] - 1) * (100*(j+1))
                cur += min(solve, A[j][0] - 1)
                if less <= 0:
                    ans = min(ans, cur)
                    break
    print(ans)


if __name__ == '__main__':
    main()
