import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)

N = int(input())

if N%2 == 0:
    ans = 0
    for i in range(1, 20):
        ans += (N//(10**i))
    for i in range(1, 40):
        A = (N//((5**i)*(10)))
        B = N//(10**(i+1))
        ans += A - B
    print(ans)
else:
    print(0)
