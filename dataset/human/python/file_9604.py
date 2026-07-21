from sys import stdin
from sys import setrecursionlimit
setrecursionlimit(10 ** 7)

n,k = map(int,stdin.readline().rstrip().split())
a = list(map(int,stdin.readline().rstrip().split()))
a = [0]+a
bunki = 0
now = a[1]
lip = [1]
se = set()
while True:
    bunki += 1
    if now in se:
        break
    se.add(now)
    lip.append(now)
    now = a[now]

tenki = lip.index(now)
lis = lip[tenki:]
roop = bunki-tenki

if k < tenki: 
    print(lip[k])
    exit()
k -= tenki

print(lis[k%roop])
