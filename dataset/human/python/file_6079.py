def resolve():
    n = int(input())
    aaa = list(map(int, input().split()))
    bbb = list(map(int, input().split()))
    ccc = list(map(int, input().split()))
    ans = bbb[aaa[0]-1]
    for i in range(n-1):
        if aaa[i+1] == aaa[i] + 1:
            ans += ccc[aaa[i]-1]
        ans += bbb[aaa[i+1]-1]
    print(ans)
resolve()
