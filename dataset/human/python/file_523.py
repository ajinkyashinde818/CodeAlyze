from bisect import bisect_left

N = int(input())
A = list(map(int,input().split()))

"""
方針
符号を変えられるのは偶数箇所
ソートしてどこまでが負の値かを調べる
境界のところで符号を変えるかは境界付近の値を見て決める
"""

A.sort()

ans,pt = 0,bisect_left(A,0)

if pt % 2 == 0:
    ans = sum(map(abs,A))
else:
    if pt == N:
        ans = sum(map(abs,A)) + 2*A[N-1]
    else:
        if A[pt-1] + A[pt] >= 0:
            ans = sum(map(abs,A)) + 2*A[pt-1]
        else:
            ans = sum(map(abs,A)) - 2*A[pt]

print(ans)
