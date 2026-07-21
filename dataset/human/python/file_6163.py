import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")


a,b,c = list(map(int, input().split()))
ans = b + min(c, a+b+1)
print(ans)
