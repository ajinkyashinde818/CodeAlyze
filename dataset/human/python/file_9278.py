import sequtils,strutils
var
    N,K,cnt,ans,l : int
    A : seq[int]
    p : int
    f : array[1000005,int]
    mem = f
(N, K) = stdin.readline.split.map(parseInt)
A = stdin.readline.split.map(parseInt)
p = 0
cnt = 0
while true:
    cnt += 1
    f[p] = cnt
    mem[cnt] = p
    if cnt > K:
        ans = p + 1
        break
    p = A[p] - 1
    
    if f[p] > 0:
        K = K - f[p] + 1
        l = cnt - f[p] + 1
        K = K mod l
        ans = mem[f[p] + K] + 1
        break
echo ans
