def resolve():
    """ recursive function"""

    def func(i, sum, cnt, rem):
        nonlocal ans
        if i == D:
            if sum < G:
                use = max(rem)
                n = min(lst[use - 1][0], -(-(G - sum) // ((use) * 100)))
                sum += n * use * 100
                cnt += n
            if sum >= G:
                ans = min(ans, cnt)
        else:
            func(i + 1, sum, cnt, rem)
            func(
                i + 1,
                sum + lst[i][0] * (i + 1) * 100 + lst[i][1],
                cnt + lst[i][0],
                rem - {i + 1})

    D, G = map(int, input().split())
    lst = [list(map(int, input().split())) for x in range(D)]
    ans = float('inf')

    func(0, 0, 0, set(range(1, D + 1)))
    print(ans)

if __name__ == "__main__":
    resolve()
