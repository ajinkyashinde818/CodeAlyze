if __name__ == "__main__":
    n = int(input())
    a = map(int, input().split())
    a = list(a)
    zerop = any(map(lambda x: x == 0, a))
    evenp = sum(map(lambda x: 1 if x < 0 else 0, a)) % 2 == 0
    abss = list(map(abs, a))
    ans = 0
    if zerop or evenp:
        ans = sum(abss)
    else:
        m = min(abss)
        i = abss.index(m)
        for j, elm in enumerate(a):
            if j == i:
                ans += -abs(elm)
            else:
                ans += abs(elm)
    print(ans)
