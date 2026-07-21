def check(L,m,n,d):
    i = 0
    for _ in xrange(m):
        s = 0
        while i < n:
            if s+L[i] > d:
                break
            s += L[i]
            i += 1
    return i == n

def bs(L,m,n):
    left,right = 0,sum(L)
    while left != right:
        mid = (left+right)/2
        if check(L,m,n,mid):
            right = mid
        else:
            left = mid+1
    return left

while True:
    m,n = map(int,raw_input().split())
    if m|n == 0:
        break
    L = [input() for _ in xrange(n)]
    print bs(L,m,n)
