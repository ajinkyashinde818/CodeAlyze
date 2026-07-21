def main():
    d, g = map(int, input().split())
    pc = [list(map(int, input().split())) for _ in range(d)]

    n = len(pc)
    ans = float("inf")

    for i in range(2**n):
        point, cnt = 0, 0
        for j in range(n):
            if (i>>j) & 1:
                point += (j+1)*100*pc[j][0] + pc[j][1]
                cnt += pc[j][0]
        if point >= g:
            ans = min(ans, cnt)
        # print(cnt, point)
        else:
            for j in range(n-1, -1, -1):
                if (i >> j) & 1:
                    continue
                else:
                    for k in range(pc[j][0]):
                        if point >= g:
                            ans = min(ans, cnt)
                            break
                        point += (j+1)*100
                        cnt += 1
    print(ans)


if __name__ == "__main__":
    main()
