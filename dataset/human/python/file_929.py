import sys
input = sys.stdin.readline
inpl = lambda: tuple(map(int,input().split()))

N, C = inpl()
xv = [None]*N
for i in range(N):
    xv[i] = inpl()
xv.sort()

Rs = [0]*(N+1)
Ls = [0]*(N+1)
Rd = [0]*(N+1)
Ld = [0]*(N+1)
RsMax = LsMax = RdMax = LdMax = 0
RvSum = LvSum = 0
RsCur = LsCur = RdCur = LdCur = 0
for i in range(1,N+1):
    RvSum += xv[i-1][1]
    LvSum += xv[N-i][1]
    RsCur = RvSum - xv[i-1][0]
    RdCur = RvSum - xv[i-1][0]*2
    LsCur = LvSum - (C-xv[N-i][0])
    LdCur = LvSum - (C-xv[N-i][0])*2
    Rs[i] = max(Rs[i-1],RsCur)
    Rd[i] = max(Rd[i-1],RdCur)
    Ls[i] = max(Ls[i-1],LsCur)
    Ld[i] = max(Ld[i-1],LdCur)
Rans = max(Rs[i]+Ld[N-i] for i in range(N+1))
Lans = max(Ls[i]+Rd[N-i] for i in range(N+1))
ans = max(Rans,Lans)
print(ans)
