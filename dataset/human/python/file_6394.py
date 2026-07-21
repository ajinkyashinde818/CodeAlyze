import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")


n = int(input())
if n%2==1:
    ans = 0
else:
    tmp = 2
    v2 = 0
    while n//tmp>0:
        v2 += n//tmp
        tmp *= 2
    v5 = 0
    tmp = 5
    nn = n//2
    while nn//tmp>0:
        v5 += nn//tmp
        tmp *= 5
    ans = min(v2, v5)
print(ans)
