import sys
def input(): return sys.stdin.readline().strip()
def mapint(): return map(int, input().split())
sys.setrecursionlimit(10**9)

S = list(input())
new = []
for s in S:
    if s=='x':
        continue
    new.append(s)

leng = len(new)
for n in range(leng//2):
    if new[n]!=new[-n-1]:
        print(-1)
        break
else:
    lis = []
    cnt = 0
    for s in S:
        if s!='x':
            lis.append(cnt)
            cnt = 0
        else:
            cnt += 1
    lis.append(cnt)
    leng = len(lis)
    ans = 0
    for i in range(leng//2):
        ans += abs(lis[i]-lis[-i-1])
    print(ans)
