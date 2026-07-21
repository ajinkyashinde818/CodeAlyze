def solve():
    n = int(input())
    A = list(map(int, input().split()))
    B = [0] + list(map(int, input().split()))
    C = [0] + list(map(int, input().split()))
    last = -1
    ans = 0
    for i in A:
        ans += B[i]
        if last + 1 == i:
            ans += C[last]
        last = i
    print(ans)
solve()
