from collections import defaultdict,deque

N,K = map(int,input().split())
A = list(map(int,input().split()))

loop = N
pos = 0
oto = defaultdict(int)
ind = 0
tej = deque([])
for i in range(N):
    pos = A[pos] - 1
    tej.append(pos+1)
    if oto[pos] == 1:
        ind = tej.index(pos+1)
        loop = i - ind 
        break
    oto[pos] = 1
K -= 1
##print("loop",loop,"ind",ind)
##print(tej)
if K <= ind:
    print(tej[K])
else:
    print(tej[(K-ind)%loop+ind])
