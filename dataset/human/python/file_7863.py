import sys
def input():
    return sys.stdin.readline()[:-1]

N,K,S = map(int,input().split(' '))
u = 10**9

if S==u:
    ans = ['1']*N
    for i in range(K):
        ans[i] = str(u)
    print(' '.join(ans))
    exit()
str_s = str(S)
ans = ['1000000000']*N
for i in range(K):
    ans[i] = str_s
print(' '.join(ans))
