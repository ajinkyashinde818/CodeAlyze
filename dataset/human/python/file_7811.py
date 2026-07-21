import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")



n,k,s = map(int, input().split())
if s==10**9:
    a = [10**9]*k + [1]*(n-k)
else:
    a = [s]*k + [s+1]*(n-k)
print(" ".join(map(str, a)))
