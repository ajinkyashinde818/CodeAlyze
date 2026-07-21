import sys
input = sys.stdin.readline

n,k = map(int,input().split())
a = list(map(int,input().split()))

for i in range(n):
    a[i] -= 1

used = [-1]*n

now = 0
tmp = 0
while True:
    used[now] = tmp
    now = a[now]
    tmp += 1
    if tmp == k:
        print(now+1)
        exit()    
    if used[now] != -1:
        break

k -= tmp
tank = []
p = now
while True:
    tank.append(p)
    p = a[p]
    if p == now:
        break

print(tank[k%len(tank)]+1)
