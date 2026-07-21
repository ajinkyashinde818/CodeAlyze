import sys

readline = sys.stdin.readline
readlines = sys.stdin.readlines
ns = lambda: readline().rstrip() # input string
ni = lambda: int(readline().rstrip()) # input int
nm = lambda: map(int, readline().split()) # input multiple int 
nl = lambda: list(map(int, readline().split())) # input multiple int to list

n, k, s = nm()
ans_h = [str(s) for _ in range(k)]
if s==10**9 :
    ans_t = ['1' for _ in range(n-k)]
else:
    ans_t = [str(s+1) for _ in range(n-k)]
print(' '.join(ans_h + ans_t))
