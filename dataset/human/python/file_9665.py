import sys
input = sys.stdin.buffer.readline
N, K = map(int, input().split())
li = list(map(int, input().split()))
li_a = []
for i in li:
    i -=1
    li_a.append(i)
k = li_a[0]
dic = {}
for i in range(N):
    dic[i] = [False, 0]
dic[0] = [True, 0]
loop = 0
for i in range(1, N+1):
    if dic[k][0] == True:
        loop = i - dic[k][1]
        start = dic[k][1]
        start_k = k
        break
    dic[k] = [True, i]
    k = li_a[k]
    
if K-start <= 0:
    ans = 0
    for i in range(K):
        ans = li_a[ans]
    print(ans+1)
    sys.exit()

amari = (K-start)%loop
if amari == 0:
    print(start_k+1)
else:
    ans = start_k
    for i in range(amari):
        ans = li_a[ans]
    print(ans+1)
