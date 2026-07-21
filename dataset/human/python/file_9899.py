def main():
    N = int(input())
    p = list(map(int, input().split()))
    ans = []

    sc = 1 #score count
    for _ in range(N):
        cnt = 0
        for i in range(len(p)):
            if p[i] >= sc:
                cnt += 1
        if cnt >= sc:
            ans.append(sc)
        sc += 1

    ans.sort(reverse = True)
    print(ans[0])


if __name__ == "__main__":
    main()
