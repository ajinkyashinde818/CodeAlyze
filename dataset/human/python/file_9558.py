import sys
input = sys.stdin.readline

n,k = map(int,input().split())
L=list(map(int,input().split()))
town=[]
visit=[False]*(n+1)
next=1
while 1:
    next = L[next-1]
    if not visit[next]:
        visit[next] = True
        town.append(next)
    else:
        town.append(next)
        break
for i in range(n):
    if town[i]==town[-1]:
        mod = i
        loop = len(town)-i-1
        loop_array = town[i:-1]
        break
fin_len = (k-mod)%loop
if k<=mod:
    print(town[k-1])
else:
    print(loop_array[fin_len-1])
