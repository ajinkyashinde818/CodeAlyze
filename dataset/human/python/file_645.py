import sys
def I(): return int(sys.stdin.readline())
def LI(): return list(map(int,sys.stdin.readline().split()))
mod = 10**9 + 7
inf = float('inf')
ans = int(0)

N = I()
A = LI()
k = int(1)
for i in A:
    if i<0:
        k *=(-1)
    elif i==0:
        k = 0

for i in range(N):
    A[i] = abs(A[i])
sumA = sum(A)
if k<0:
    ans = sumA-min(A)*2
else:
    ans = sumA

print(ans)
