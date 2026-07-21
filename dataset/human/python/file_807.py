import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")


n,r = map(int, input().split())
if n >= 10:
    ans = r
else:
    ans = r + 100*(10-n)
print(ans)
