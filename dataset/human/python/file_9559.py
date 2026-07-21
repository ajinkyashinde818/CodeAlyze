import sys
sys.setrecursionlimit(10**7)

N, K = map(int,input().split())
A = list(map(int, input().split())) 
check = [0]*N
tele_lis = []
start = []
def tele(x):
    check[x-1] = 1
    tele_lis.append(x)
    if check[A[x-1]-1] == 0:
        tele(A[x-1])
    else:
        start.append(A[x-1])
        return
tele(1)
for i in range(N):
    if start[0] == tele_lis[i]:
        break
if i >= K:
    print(tele_lis[K])
else:
    print(tele_lis[i::][(K-i) % (sum(check)-i)])
