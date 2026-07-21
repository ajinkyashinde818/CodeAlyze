import sys
input = sys.stdin.readline
N = int(input())
def m5(N):
    count = 0
    while True :
        k = N // 5
        if k == 0 :
            break
        else :
            N = k
            count += k // 2
    return count
if N % 2 == 1 :
    print(0)
else :
    s = str(N)
    o = int(s[-1])
    N -= o
    print(m5(N))
